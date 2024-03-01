#include<iostream>
#include<cstring>
#include<limits.h>
#include<algorithm>
#include<vector>
#define MAX INT_MAX

using namespace std;
int t, n;
int map[13][13];
int temp_map[13][13];
int maxCoreCnt;
int minWireLength;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };


struct Pos {
	int y, x;
};

vector<Pos>cores;

void init() {
	memset(map, 0, sizeof(map));
	maxCoreCnt = 0;
	minWireLength = MAX;
	cores.clear();
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
}

void cntCore() {
	for (int i = 1; i < n-1; i++) {
		for (int j = 1; j < n-1; j++) {
			if (map[i][j] == 1) {
				cores.push_back({ i,j });
			}
		}
	}
}

void dfs(int curIdx, int coreCnt, int wireLength) {

	// 현재 설치된 코어 + 남은 코어 개수 < 이전 최대 코어
	if ((coreCnt + cores.size() - curIdx) < maxCoreCnt)return;

	// 모든 조합들로 연결해야하는 코어를 만든 경우
	if (curIdx == cores.size()) {
		
		// 최대 연결 코어 개수보다 현재 연결 코어 개수가 더 클 때
		if (maxCoreCnt < coreCnt) {
			maxCoreCnt = coreCnt;
			minWireLength = wireLength;
		}

		// 똑같은 개수이나, 선은 더 작은 경우
		else if (maxCoreCnt == coreCnt) {
			minWireLength = min(minWireLength, wireLength);
		}
		return;

	}

	for (int i = 0; i < 4; i++) {
		Pos now = cores[curIdx];

		bool isConnect = false;
		int tempCoreCnt = coreCnt;
		int tempWireLength = wireLength;
		int curWireLength = 0;
		int next_y = now.y + dy[i];
		int next_x = now.x + dx[i];
		while (1) {
			if (next_y < 0 || next_x < 0 || next_y >= n || next_x >= n) {
				isConnect = true;
				tempCoreCnt++;
				break;
			}
			if (temp_map[next_y][next_x] == 1 || temp_map[next_y][next_x] == 2) {
				break;
			}
			next_y += dy[i];
			next_x += dx[i];
			curWireLength++;
			tempWireLength++;
		}

		if (isConnect) {
			for (int j = 1; j <= curWireLength; j++) {
				int ty = cores[curIdx].y + dy[i] * j;
				int tx = cores[curIdx].x + dx[i] * j;
				temp_map[ty][tx] = 2;
			}
			dfs(curIdx + 1, tempCoreCnt, tempWireLength);
			for (int j = 1; j <= curWireLength; j++) {
				int ty = cores[curIdx].y + dy[i] * j;
				int tx = cores[curIdx].x + dx[i] * j;
				temp_map[ty][tx] = 0;
			}
		}
		else {
			dfs(curIdx + 1, coreCnt, wireLength);
		}
	}


}

int main() {
	cin >> t;
	for (int i = 1; i <= t; i++) {
		init();
		input();
		cntCore();
		memcpy(temp_map, map, sizeof(map));
		dfs(0, 0, 0);
		cout << "#" << i << " " << minWireLength << "\n";
	}
	return 0;
}
#include<iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, ans;
int arr[8][8], temp[8][8],dx[4] = { -1,1,0,0 },dy[4] = { 0,0,1,-1 };
bool combi_check[64];
vector <pair<int,int>> zero_coord;


void copy_arr() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			temp[i][j] = arr[i][j];
		}
	}
}



void bfs() {

	// 2인 지점 먼저 찾기 
	queue<pair<int, int>>q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == 2) {
				q.push(make_pair(i, j));
			}
		}
	}

	// 2인 지점에서 출발하여 안전 영역을 모두 감염시킨다
	// 그 후 안전 영역의 개수를 구한다. 

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m) {
				continue;
			}
			if (temp[next_x][next_y] == 0) {
				temp[next_x][next_y] = 2;
				q.push(make_pair(next_x, next_y));
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == 0)
			{
				cnt++;
			}
		}
	}
	ans = max(ans, cnt);
	
}

// 입력시 안전영역의 좌표를 저장한 후 해당 좌표를 3개의 조합으로
// 탐색 후 최대 영역 값 저장 

void combination(int cur, int idx) {

	// 벽을 3개 세웠을 때 : 종료조건
	if (cur == 3) {
		copy_arr();
		int cnt = 0;
		for (int i = 0; i < zero_coord.size(); i++) {
			if (cnt == 3) {
				break;
			}
			if (combi_check[i]) {
				cnt++;
				int x = zero_coord[i].first;
				int y = zero_coord[i].second;
				temp[x][y] = 1;
			}
		}
		// 벽을 세운 후 bfs탐색
		bfs();
		return;
	}

	for (int i = idx; i < zero_coord.size(); i++) {
		if (combi_check[i]) {
			continue;
		}
		combi_check[i] = true;
		combination(cur + 1, i);
		combi_check[i] = false;
	}


}


int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) {
				zero_coord.push_back(make_pair(i, j));
			}
		}
	}
	combination(0, 0);
	cout << ans;
	return 0;
}
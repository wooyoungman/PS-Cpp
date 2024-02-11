#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
// 물은 0
// 나머지는 빙산의 높이 
// 빙산은 동서남북 4방향으로 붙어있는 물의 개수만큼 줄어든다.
// 임시 맵을 저장하고 해당 빙산의 높이 조절 저장하기
// 이후 모든 높이 조절 지정이 완료되면 한 번에 연산 처리
// 높이 조절이 끝난 후 빙산이 한 덩어리로 연결되어 있는지 판단

// 1. 임시 맵에 각 지점 별 높이 변화 저장
// 2. 원래 맵에 높이 변화 적용
// 3. 변화한 높이에 따른 빙산의 덩어리 개수 판단
// 4. 만약 모든 빙산이 다 녹았는데도 덩어리가 2개 이상인 적이 없으면 0 출력


int map[301][301];
int temp_map[301][301];
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
bool visited[301][301];
bool all_water;
int n, m, ans;

bool isValid(int y, int x) {
	return y >= 0 && x >= 0 && y <= n - 1 && x <= m - 1;
}

bool isVisited(int y, int x) {
	return visited[y][x];
}

void cal_high() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int cnt = 0;
			// 현재 지점의 동서남북이 물인 지점의 개수를 저장
			if (map[i][j] == 0)continue;
			for (int k = 0; k < 4; k++) {
				int next_y = i + dy[k];
				int next_x = j + dx[k];
				if (!isValid(next_y, next_x))continue;
				if (map[next_y][next_x] == 0) {
					cnt++;
				}
			}
			temp_map[i][j] = cnt;
			//cout << temp_map[i][j] << " ";
		}
		//cout << "\n";
	}

	return;
}

void change_high() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] -= temp_map[i][j];
			if (map[i][j] < 0)map[i][j] = 0;
			//cout << map[i][j] << " ";
		}
		//cout << "\n";
	}
	return;
}

int count_mt() {

	int cnt_mt = 0;
	all_water = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// 이미 방문했거나 물인 경우 다음 지점으로
			if (visited[i][j] || map[i][j] == 0)continue;
			//cout << i << " " << j << "\n";
			all_water = false;
			// 방문하지 않은 빙산을 BFS로 탐색하여 
			// BFS 시행 횟수가 즉 덩어리의 개수가 된다.
			queue<pair<int, int>>q;
			q.push({ i,j });
			while (!q.empty()) {
				int cur_y = q.front().first;
				int cur_x = q.front().second;
				visited[cur_y][cur_x] = true;
				q.pop();/*
				cout << "\n";
				cout << cur_y << " " << cur_x << "\n";*/
				for (int k = 0; k < 4; k++) {
					int next_y = cur_y + dy[k];
					int next_x = cur_x + dx[k];
					if (!isValid(next_y, next_x)||isVisited(next_y,next_x))continue;
					if (map[next_y][next_x] > 0) {
						visited[next_y][next_x] = true;
						q.push({ next_y,next_x });
					}
				}
			}
			cnt_mt++;
		}
	}
	return cnt_mt;
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	while (1) {
		ans++;
		memset(temp_map, 0, sizeof(temp_map));
		memset(visited, false, sizeof(visited));

		cal_high();

		change_high();

		int cnt_mt = count_mt();

		if (!all_water && cnt_mt >= 2) {
			cout << ans;
			break;
		}

		if (all_water) {
			cout << 0;
			break;
		}

	}
	return 0;
}
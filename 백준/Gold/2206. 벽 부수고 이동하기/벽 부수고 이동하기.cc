#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// 벽이 있는 맵에서 최단 경로 ? 
// 하나를 깬다?
// BFS로 해봅시다

// 항상 (0,0)에서 시작하여 (n-1,m-1)에 도착하는 경우를 구해야한다
// 0은 이동 가능, 1은 이동 불가능

int n, m;
int map[1001][1001];
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,-1,1 };
bool visited[1001][1001][2];

struct Info {
	int y;
	int x;
	int hit;
	int dist;
};

bool isValid(int y, int x) {
	return y >= 0 && x >= 0 && y < n && x < m;
}

int bfs() {

	queue<Info>q;
	q.push({ 0,0,0,1 });
	while (!q.empty()) {
		int cur_y = q.front().y;
		int cur_x = q.front().x;
		int cur_hit = q.front().hit;
		int cur_dist = q.front().dist;
		q.pop();

		if (cur_y == n - 1 && cur_x == m - 1)return cur_dist;

		for (int i = 0; i < 4; i++) {
			int next_y = cur_y + dy[i];
			int next_x = cur_x + dx[i];
			if (!isValid(next_y, next_x))continue;

			// 다음 길이 이동가능하고, 벽돌을 깨서 방문했거나 안깨서 방문했거나 기록 확인 후 탐색
			if (map[next_y][next_x] == 0 && !visited[next_y][next_x][cur_hit]) {
				visited[next_y][next_x][cur_hit] = true;
				q.push({ next_y,next_x,cur_hit,cur_dist + 1 });
			}
			// 다음 길이 벽인데 현재 벽을 안깼다면 ? 
			else if (map[next_y][next_x] == 1 && cur_hit == 0) {
				q.push({ next_y,next_x,1,cur_dist + 1 });
				visited[next_y][next_x][1] = true;
			}

		}
	}
	return -1;
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			map[i][j] = s[j] - '0';
		}
	}

	int result = bfs();
	cout << result;

	return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int M, N, K, ans=0;
bool visited[101][101];
vector<int>area_cnt;

void bfs(int x, int y) {
	queue<pair<int, int>>q;
	q.push(make_pair(x, y));
	visited[x][y] = true;
	int cnt = 1;
	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];
			if (next_x < M && next_x >= 0 && next_y < N && next_y >= 0) {
				if (!visited[next_x][next_y])
				{
					q.push(make_pair(next_x, next_y));
					visited[next_x][next_y] = true;
					cnt++;
				}
			}
		}
	}
	area_cnt.push_back(cnt);
}

int main() {

	cin >> M >> N >> K;
	for (int i = 0; i < K; i++) {
		int s_x,s_y,e_x,e_y;
		cin >> s_y >> s_x >> e_y >> e_x;
		for (int j = s_x; j < e_x; j++) {
			for (int k = s_y; k < e_y; k++) {
				visited[j][k] = true;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				bfs(i, j);
				ans++; // 영역의 수 
			}
		}
	}
	cout << ans << "\n";
	sort(area_cnt.begin(), area_cnt.end());
	for (int i = 0; i < area_cnt.size(); i++) {
		cout << area_cnt[i] << " ";
	}
	return 0;
}
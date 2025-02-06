#include <iostream>
#include <cstring>
using namespace std;

int arr[501][501];
int dp[501][501]; // dp[y][x] : (y,x)에서 목표 지점으로 갈 수 있는 경로의 개수
// 문제 예제에서는 dp[1][1] = dp[1][2] + dp[2][1] 
int n, m;

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

bool isValid(int y, int x) {
	return y >= 1 && x >= 1 && y <= n && x <= m;
}

int dfs(int y, int x) {
	// 탈출 조건 (목표 지점 도착) -> 경로 1개 찾음
	if (y == n && x == m)return 1;

	
	// 미방문 시 계속 탐색
	if (dp[y][x] == -1) {
		dp[y][x] = 0;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (!isValid(ny, nx))continue;

			int ch = arr[y][x];
			int nh = arr[ny][nx];

			if (ch <= nh)continue;

			dp[y][x] += dfs(ny, nx);

		}
		
	}

	// 이미 방문한 곳이면 현재 경로의 개수 반환
	return dp[y][x];
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	// 경로 압축
	memset(dp, -1, sizeof(dp));
	cout<<dfs(1, 1);
	return 0;
}
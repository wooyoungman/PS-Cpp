#include <iostream>
using namespace std;

int n;
int arr[101][101];
long long dp[101][101];
int main() {
	cin >> n;
	
	// 1행씩 차례대로 DP 진행
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			// 이동할 수 있는 범위면 이동
			int dir = arr[i][j];
			if (i == n - 1 && j == n - 1)break;
			// 우측 이동
			if (j + dir < n && dp[i][j]>0) {
				dp[i][j + dir] += dp[i][j];
			}
			// 하단 이동
			if (i + dir < n && dp[i][j]>0) {
				dp[i + dir][j] += dp[i][j];
			}
		}
	}
	cout << dp[n - 1][n - 1];
	return 0;
}
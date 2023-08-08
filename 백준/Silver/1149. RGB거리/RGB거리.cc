#include<iostream>

using namespace std;

int n,ans;
int dp[1001][3];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + dp[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + dp[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + dp[i][2];
	}
	ans = min(dp[n][0], dp[n][1]);
	ans = min(ans, dp[n][2]);
	cout << ans;
	return 0;
}
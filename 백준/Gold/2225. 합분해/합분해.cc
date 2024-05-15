#include<iostream>
#include<algorithm>
#define modnum 1000000000
using namespace std;

int n, m;
int dp[201][201];
int ans;
void func() {
	for (int i = 1; i <= m; i++) {
		dp[0][i] = i;
		dp[1][i] = i;
		dp[i][1] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = ((dp[i][j - 1] % modnum) + (dp[i - 1][j] % modnum)) % modnum;
		}
	}
	ans = dp[n][m];
	cout << ans;
	
}
int main() {
	cin >> n >> m;
	func();
	return 0;
}
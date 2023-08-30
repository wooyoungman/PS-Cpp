#include<iostream>
using namespace std;

int main() {
	
	int t,n,m;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int dp[10001] = { 0, };
		int coin[21];
		dp[0] = 1; // 0원을 만드는 경우의 수는 동전 0개 -> 1가지
				
		cin >> n;

		for (int j = 0; j < n; j++) {
			cin >> coin[j]; // 동전 입력 받기
		}
		
		cin >> m;

		for (int j = 0; j < n; j++) {
			for (int k = coin[j]; k <= m; k++) {
				dp[k] = dp[k] + dp[k - coin[j]];
			}
		}
		cout << dp[m] << "\n";
	}

	return 0;
}
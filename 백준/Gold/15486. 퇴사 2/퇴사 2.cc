#include <iostream>
#include <algorithm>
#define MAX 1500001
using namespace std;

int n;
int days[MAX];
int profit[MAX];
int dp[MAX];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> days[i] >> profit[i]; 
	}

	for (int i = 1; i <= n+1; i++) {
		// 이전 까지의 최대 이익 유지
		dp[i] = max(dp[i], dp[i - 1]);

		// 현재 상담 가능한 경우
		if (i + days[i] <= n + 1) {
			dp[i + days[i]] = max(dp[i + days[i]], dp[i] + profit[i]);
		}
	}
	cout << dp[n + 1];
	return 0;
}
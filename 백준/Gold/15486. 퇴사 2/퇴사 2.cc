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
		dp[i + days[i]] = max(dp[i + days[i]], dp[i] + profit[i]);
		dp[i + 1] = max(dp[i], dp[i + 1]);
	}

	cout << dp[n + 1];
	return 0;
}
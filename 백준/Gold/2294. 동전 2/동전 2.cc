#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<climits>
#define MAX 99999
using namespace std;


int n, k;
int coins[101];
int dp[10001];
void func() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}
	for (int i = 1; i <= k; i++) {
		dp[i] = MAX;
	}
	for (int i = 0; i < n; i++) {
		for (int j = coins[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - coins[i]] + 1);
		}
	}
	if (dp[k] == MAX)cout << -1;
	else cout << dp[k];
}

int main() {

	func();

	return 0;
}
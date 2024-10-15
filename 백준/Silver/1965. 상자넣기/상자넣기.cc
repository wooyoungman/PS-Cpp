#include<iostream>
#include<algorithm>
using namespace std;

int n;
int arr[1001];

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

void func() {
	int dp[1001] = { 0, };
	dp[arr[0]] = 1;
	int ans = 1;
	for (int i = 1; i < n; i++) {

		int maxV = dp[arr[i]];
		int maxIdx = arr[i];
		for (int j = arr[i]; j > 0; j--) {
			if (dp[j] >= maxV) {
				maxIdx = j;
				maxV = dp[j];
			}
		}
		if (maxV == dp[arr[i]]) {
			if (maxIdx < arr[i]) {
				dp[arr[i]] = dp[arr[i]] + 1;
				ans = max(ans, dp[arr[i]]);
			}
			else {
				dp[arr[i]] = max(1, dp[arr[i]]);
				ans = max(ans, dp[arr[i]]);
			}
		}
		else {
			dp[arr[i]] = dp[maxIdx] + 1;
			ans = max(ans, dp[arr[i]]);
		}


	}
	cout << ans;
}

int main() {
	input();
	func();
	return 0;
}
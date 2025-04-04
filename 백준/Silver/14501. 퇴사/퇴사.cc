#include<iostream>
#include<algorithm>
using namespace std;

int n;
int arr[16][2];
int dp[16];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}
	for (int i = 1; i <= n; i++) {
		int next_day = i + arr[i][0]-1;
		int next_value = dp[i-1] + arr[i][1];
		for (int j = next_day; j <= n; j++) {
			dp[j] = max(dp[j], next_value);
		}
	}
	cout << dp[n];
	return 0;
}
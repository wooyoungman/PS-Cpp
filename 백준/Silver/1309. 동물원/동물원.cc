#include<iostream>
using namespace std;

int n;

int dp[100001];

void func() {
	dp[1] = 3;
	dp[2] = 7;
	for (int i = 3; i <= n; i++) {
		dp[i] = (((dp[i - 1] * 2) % 9901) + (dp[i - 2] % 9901)) % 9901;
	}
	cout << dp[n];
}

int main() {
	cin >> n;
	func();
	return 0;
}
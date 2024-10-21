#include<iostream>
#include<algorithm>
using namespace std;

int n;
int nums[201];
int dp[201];
void func() {
	int lcs = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		dp[i] = 1;
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (nums[i] < nums[j]) {
				dp[j] = max(dp[j], dp[i] + 1);
				lcs = max(lcs, dp[j]);
			}
		}
	}
	cout << n - lcs;
}

int main() {

	func();

	return 0;
}
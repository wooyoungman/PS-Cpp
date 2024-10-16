#include<iostream>
#include<algorithm>
using namespace std;

string s1, s2;

int dp[4001][4001];

void input() {
	cin >> s1;
	cin >> s2;
}

void func() {
	int ans = 0;
	for (int i = 0; i < s2.length(); i++) {
		if (s1[0] == s2[i])dp[0][i] = 1;
	}
	for (int i = 0; i < s1.length(); i++) {
		if (s2[0] == s1[i])dp[i][0] = 1;
	}
	for (int i = 1; i < s1.length(); i++) {
		for (int j = 1; j < s2.length(); j++) {
			if (s1[i] == s2[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = 0;
			}
			ans = max(ans, dp[i][j]);
		}
	}

	cout << ans;
}

int main() {
	input();
	func();
	return 0;
}
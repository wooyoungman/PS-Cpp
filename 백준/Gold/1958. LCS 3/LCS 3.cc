#include<iostream>
#include<algorithm>
using namespace std;

string s1, s2, s3;

int dp[101][101][101];

void input() {
	cin >> s1 >> s2 >> s3;
}

void func() {
	int ans = 0;
	for (int k = 1; k <= s3.length(); k++) {
		for (int i = 1; i <= s1.length(); i++) {
			for (int j = 1; j <= s2.length(); j++) {
				if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1]) {
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				}
				else dp[i][j][k] = max(max(dp[i - 1][j][k], dp[i][j - 1][k]), dp[i][j][k - 1]);
			}
		}
	}
	cout << dp[s1.length()][s2.length()][s3.length()];
}

int main() {
	input();
	func();
	return 0;
}
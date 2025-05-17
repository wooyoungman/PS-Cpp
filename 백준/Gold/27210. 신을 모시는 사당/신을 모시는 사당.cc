#include<iostream>
#include<algorithm>
using namespace std;
int n;
int num[100001];
int cnt[100001][2];
int dp[100001];
int main() {
	cin >> n;
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		if (i == 1) {
			cnt[1][num[i] - 1] = 1;
			dp[1] = 1;
			//cout << 1 << " ";
			continue;
		}

		if (num[i] == 1) {
			cnt[i][0] = cnt[i - 1][0] + 1;
			cnt[i][1] = cnt[i - 1][1] - (cnt[i - 1][1] > 0);
		}
		else {
			cnt[i][1] = cnt[i - 1][1] + 1;
			cnt[i][0] = cnt[i - 1][0] - (cnt[i - 1][0] > 0);
		}

		dp[i] = max({ dp[i - 1],cnt[i][0],cnt[i][1] });

		//cout << dp[i] << " ";
	}
	cout << dp[n];
	return 0;
}
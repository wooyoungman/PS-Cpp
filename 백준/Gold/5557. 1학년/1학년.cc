#include<iostream>

using namespace std;

// dp[i][j] = i번째 항에서의 누적합이 j가 되는 경우의 수
long long dp[101][21];

int n;

int nums[101];
int next_nums[101][2];
int final_num;

int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> nums[i];
	}
	cin >> final_num;

	// 첫번째 숫자로 시작
	dp[1][nums[1]] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 20; j++) {
			int plus_num = j + nums[i];
			int minus_num = j - nums[i];
			// 현재 j 숫자가 자신의 바로 앞 누적합에 해당하고, 더하거나 뺐을 때 범위 내라면 DP 추가
			if (plus_num <= 20 && dp[i - 1][j] != 0) {
				dp[i][plus_num] += dp[i - 1][j];
			}
			if (minus_num >= 0 && dp[i - 1][j] != 0) {
				dp[i][minus_num] += dp[i - 1][j];
			}
		}
	}
	cout << dp[n - 1][final_num];
	return 0;
}
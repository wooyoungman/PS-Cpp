#include<iostream>
#include<algorithm>
#include<cmath>
#include<climits>
#define MAX INT_MAX
using namespace std;

int n, m;
int len[1001];
int len_sum[1001];
int dp[1001];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> len[i];
		len_sum[i] = len_sum[i - 1] + len[i];
		dp[i] = -1;
	}
	dp[1] = (int)pow((m - len[1]), 2);

	// dp[i] : i번째 사람까지 이름을 적었을 때, 제곱 합 최소
	// i 이전, 모든 경우의 수를 찾아 더 작은 값으로 갱신하면 된다.
	// 이어서 안붙이는 만큼 (줄을 띄워 붙이는 만큼) dp값과 현재 빈칸의 값을 구해서 갱신한다.

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			// 범위 초과인 경우 진행 x
			int cur_len = len_sum[i] - len_sum[j - 1] + i - j;
			if (cur_len > m)continue;
			
			int cur_sum = dp[j - 1] + (int)pow((m - cur_len), 2);

			if (dp[i] == -1 || dp[i] > cur_sum)dp[i] = cur_sum;
		}
	}

	// 마지막 줄은 빈칸 고려하지 않으므로, 
	// 맨 뒤부터 m이하를 만족하는 길이 중 dp[i] 최소값을 뽑으면 된다.
	int ans = MAX;
	for (int i = 1; i <= n; i++) {
		if (len_sum[n] - len_sum[i] + n - i <= m)ans = min(ans, dp[i]);
	}
	cout << ans;
	return 0;
}
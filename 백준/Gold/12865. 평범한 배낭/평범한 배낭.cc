#include <iostream>

using namespace std;

int v[101];
int w[101];
int dp[101][100001];


int main() {

	// 물품의 수와 가방의 용량 입력 받기
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}

	// 1~N번까지의 물건을 하나씩 가방에 담을 때 용량을 1씩 증가시키면서 
	// 최대 기댓값을 누적시키면서 담는다.
	// 이 때, 현재 n번째 물건을 넣을 수 있는 경우의 수는 
	// n-1번째 물건의 기댓값과 (n-1번째 물건의 무게 - 현재 물건의 무게)의 기댓값 + 현재 물건의 기댓값이다.
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			// 현재 가방의 용량이 현재 물건을 담을 수 있다면
			if (j >= w[i])
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[n][k];
	return 0;
}
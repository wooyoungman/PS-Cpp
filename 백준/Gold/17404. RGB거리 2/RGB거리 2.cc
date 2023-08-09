#include <iostream>
#include <algorithm>
using namespace std;

int n, ans=99999999;
int arr[1001][3];
int dp[1001][3];


int main() {

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}


	// 0=R, 1=G, 2=B 세 경우로 나누어서 각각 구하기
	for (int i = 0; i < 3; i++) {
		
		// 지정된 색 이외는 선택 x 
		for (int j = 0; j < 3; j++) {
			if (i == j) {
				dp[1][j] = arr[1][j];
			}
			else
			{
				dp[1][j] = 999999999;
			}
		}

		for (int j = 2; j <= n; j++) {
			dp[j][0] = arr[j][0] + min(dp[j - 1][1], dp[j - 1][2]);
			dp[j][1] = arr[j][1] + min(dp[j - 1][0], dp[j - 1][2]);
			dp[j][2] = arr[j][2] + min(dp[j - 1][0], dp[j - 1][1]);
		}

		// 지정된 색과 마지막 집의 색이 같으면 제외
		for (int j = 0; j < 3; j++) {
			if (i == j) {
				continue;
			}
			else {
				ans = min(ans, dp[n][j]);
			}
		}
	}
	cout << ans;

	return 0;
}
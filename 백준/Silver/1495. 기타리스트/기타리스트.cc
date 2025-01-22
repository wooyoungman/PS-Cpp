#include <iostream>
#include <algorithm>
using namespace std;

int n, s, m;

int volumes[51];

// dp[i][j] => i번째 노래에서 j라는 볼륨으로 설정이 가능하다
bool dp[51][1001];

int main() {

	cin >> n >> s >> m;

	for (int i = 1; i <= n; i++) {
		cin >> volumes[i];
	}

	dp[0][s] = true;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (dp[i - 1][j]) {
				if (j + volumes[i] <= m) {
					dp[i][j + volumes[i]] = true;
				}
				if (j - volumes[i] >= 0) {
					dp[i][j - volumes[i]] = true;
				}
			}
			
		}
	}

	int ans = -1;
	for (int i = 0; i <= m; i++) {
		if (dp[n][i])ans = max(ans, i);
	}

	cout << ans;
	
	return 0;
}
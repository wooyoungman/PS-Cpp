#include<iostream>

using namespace std;

int n;

int nums[2001];

int m;

bool dp[2001][2001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	
	for (int i = 1; i <= n; i++) {
		dp[i][i] = true;
		if (nums[i] == nums[i + 1] && i != n)dp[i][i + 1] = true;
	}

	for (int len = 3; len <= n; len++) {
		// [s,e]가 참이려면 [s+1,e-1]이 참이고, nums[s]와 nums[e]가 같은 수여야 한다.
		for (int s = 1; s <= n - len + 1; s++) {
			int e = s + len - 1;
			if (nums[s] == nums[e] && dp[s + 1][e - 1])dp[s][e] = true;
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		if (dp[s][e])cout << 1 << "\n";
		else cout << 0 << "\n";
	}
	return 0;
}
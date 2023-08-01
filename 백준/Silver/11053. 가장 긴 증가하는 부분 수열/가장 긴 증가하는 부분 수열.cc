#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int n,ans=0;
int dp[1001] = { 0, };
int arr[1001] = { 0, };




int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr[i] = a;
		dp[i] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (dp[i] <= dp[j])
				{
					dp[i] = dp[j] + 1;
				}
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << ans;
	return 0;
}
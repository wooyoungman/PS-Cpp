#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;

int main() {

	int n;
	cin >> n;
	int arr[100001];
	int dp[100001];

	cin >> arr[0];
	dp[0] = arr[0];

	for (int i = 1; i < n; i++) {
		cin >> arr[i];
		if (dp[i - 1] < 0) {
			dp[i] = arr[i];
		}
		else {
			dp[i] = dp[i - 1] + arr[i];
		}
	}
	int answer = *max_element(dp, dp + n);
	cout << answer;
	return 0;
}
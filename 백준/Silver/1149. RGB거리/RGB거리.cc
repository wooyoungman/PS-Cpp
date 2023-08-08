#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1001][3];
int ans = 0;

int main() {

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

		arr[i][0] = arr[i][0] + min(arr[i-1][1], arr[i-1][2]);
		arr[i][1] = arr[i][1] + min(arr[i-1][0], arr[i-1][2]);
		arr[i][2] = arr[i][2] + min(arr[i-1][0], arr[i-1][1]);
	}
	ans = min(arr[n][0], arr[n][1]);
	ans = min(ans, arr[n][2]);
	cout << ans;
	return 0;
}
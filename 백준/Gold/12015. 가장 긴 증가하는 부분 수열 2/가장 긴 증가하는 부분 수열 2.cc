#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int n;
vector<int> ans;
vector<int> arr;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}
	ans.push_back(arr[0]);
	for (int i = 1; i < n; i++) {
		if (arr[i] > ans.back()) {
			ans.push_back(arr[i]);
		}
		else {
			int l = 0, r = ans.size() - 1, mid = 0;
			while (l < r) {
				mid = (l + r) / 2;
				if (ans[mid] >= arr[i])
				{
					r = mid;
				}
				else
				{
					l = mid + 1;
				}
			}
			ans[r] = arr[i];
		}
	}
	cout << ans.size();
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, ans;
vector<int>v;
int main() {

	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	
	int left = 0;
	int right = v.size() - 1;
	while (left < right) {
		int sum = v[left] + v[right];
		if (sum < m) {
			left++;
		}
		else if (sum == m) {
			ans++;
			left++;
			right--;
		}
		else {
			right--;
		}
	}
	cout << ans;
	return 0;
}
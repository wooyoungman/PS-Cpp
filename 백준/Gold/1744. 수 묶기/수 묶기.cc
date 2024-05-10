#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, ans;
void func() {
	vector<int>v;
	int cnt_minus = 0;
	int cnt_plus = 0;
	int cnt_zero = 0;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num < 0)cnt_minus++;
		else if (num > 0)cnt_plus++;
		else cnt_zero++;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	if (cnt_minus > 0) {
		for (int i = 0; i < cnt_minus; i++) {
			int cur = v[i];
			if (i == cnt_minus - 1) {
				if (cnt_zero > 0) {
					break;
				}
				else {
					ans += cur;
					break;
				}
			}
			int next = v[i + 1];
			if (cur < 0 && next <= 0) {
				ans += cur * next;
				i++;
			}
			else if (cur <= 0 && next == 0) {
				i++;
				ans += cur;
				ans += next;
			}
		}
	}
	if (cnt_plus > 0) {
		for (int i = n-1; i >= 0; i--) {
			int cur = v[i];
			if (i < n-cnt_plus)break;
			if (i == n - cnt_plus) {
				ans += v[i];
				break;
			}
			int next = v[i - 1];

			if (cur <= 0 && next >= 0) {
				i--;
				ans += cur;
				ans += next;
			}
			else if (cur == 1 || next == 1) {
				i--;
				ans += cur;
				ans += next;
			}
			else if (cur > 1 && next > 1) {
				i--;
				ans += cur * next;
			}
		}
	}
	cout << ans;

}
int main() {
	cin >> n;
	func();

	return 0;
}

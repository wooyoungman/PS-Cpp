#include <iostream>
#include <algorithm>
using namespace std;


int n, m;
long long times[100001];
long long mr;
void func() {
	long long left = 1;
	long long right = m * times[0];
	long long res = 0;
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += mid / times[i];
		}
		if (cnt >= m) {
			right = mid - 1;
			if (res > mid || res == 0) {
				res = mid;
			}
		}
		else {
			left = mid + 1;
		}
	}
	cout << res;
}


int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> times[i];
	}
	sort(times, times + n);
	func();
	return 0;
}
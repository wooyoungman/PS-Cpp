#include<iostream>
#include<algorithm>
#include<deque>

using namespace std;

int a, b, n;
void func() {
	cin >> n >> a >> b;
	int maxHigh = max(a, b);
	deque<int>d;
	for (int i = 1; i <= a - 1; i++) {
		d.push_back(i);
	}
	d.push_back(maxHigh);
	for (int i = b - 1; i >= 1; i--) {
		d.push_back(i);
	}
	if (d.size() > n) {
		cout << -1;
		return;
	}

	int curSize = d.size();
	int minH = d.front();
	d.pop_front();
	for (int i = 0; i < n - curSize; i++) {
		d.push_front(1);
	}
	d.push_front(minH);
	for (int i = 0; i < d.size(); i++) {
		cout << d[i] << " ";
	}

}

int main() {
	func();
	return 0;
}
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int n;
int cnt[51];
vector<int>highs;
void func() {
	for (int i = 0; i < n; i++) {
		int h;
		cin >> h;
		highs.push_back(h);
	}

	for (int i = 0; i < n; i++) {
		double maxDiff = -1000000000;
		for (int j = i + 1; j < n; j++) {
			int y = highs[j] - highs[i];
			int x = j - i;
			double diff = (y * 1.00) / x;
			if (diff <= maxDiff)continue;
			maxDiff = diff;
			cnt[i]++;
			cnt[j]++;
		}
	}
	cout << *max_element(cnt, cnt + 50);
}

int main() {
	cin >> n;
	func();
	return 0;
}
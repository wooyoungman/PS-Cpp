#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, c;
vector<int>v;

// 1, 2, 3, 4, 5, 6, 7, 8, 9 
// mid = 5 
// 두개의 공유기에 대해서만 거리를 최대로 한다.
// 이후 나머지 C-2개의 공유기가 남아있는지 확인한다.
// 12 4, 12 8, 12 9, 24 8, 24 9, 48 9

int main() {
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	int left = 0;
	int right = v[v.size() - 1] - v[0];
	int mid = 0;
	int ans = 0;
	while (left <= right) {
		int cnt = 1;
		int temp = v[0];
		mid = (left + right) / 2;
		for (int i = 1; i < n; i++) {
			if (v[i] - temp >= mid) {
				cnt++;
				temp = v[i];
			}
		}
		if (cnt < c) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
			ans = mid;
		}
	}
	cout << ans;
	return 0;
}
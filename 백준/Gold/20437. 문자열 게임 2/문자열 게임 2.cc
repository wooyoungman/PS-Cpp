#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#define MAX INT_MAX
using namespace std;
int t, k;
string w;
int ans1, ans2;
void func() {
	vector<int>idx[26];
	ans1 = MAX;
	ans2 = -1;
	for (int i = 0; i < w.length(); i++) {
		int num = w[i] - 'a';
		idx[num].push_back(i);
	}
	for (int i = 0; i < 26; i++) {
		if (idx[i].size() >= k) {
			int left = 0;
			int right = k - 1;
			while (right < idx[i].size()) {
				ans1 = min(ans1, idx[i][right] - idx[i][left] + 1);
				ans2 = max(ans2, idx[i][right] - idx[i][left] + 1);
				left++;
				right++;
			}
		}
	}
}

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> w >> k;
		func();
		if (ans1 == MAX || ans2 == -1)cout << -1 << "\n";
		else cout << ans1 << " " << ans2 << "\n";
	}
	return 0;
}
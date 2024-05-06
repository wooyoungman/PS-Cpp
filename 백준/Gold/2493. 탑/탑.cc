#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int n;
vector<int>nums(500001);
void func() {
	stack < pair<int, int>>s;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		if (s.empty()) {
			s.push({ nums[i],i+1 });
			cout << 0 << " ";
		}
		else {
			while (!s.empty()) {
				// 수신탑 찾기
				if (nums[i] < s.top().first) {
					cout << s.top().second << " ";
					break;
				}
				s.pop();
			}
			// 수신탑 없으면
			if (s.empty()) {
				cout << 0 << " ";
			}
			s.push({ nums[i],i + 1 });
		}
	}
	
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n;
	func();
	return 0;
}
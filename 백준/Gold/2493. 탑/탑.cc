#include<iostream>
#include<stack>
using namespace std;

int n;
stack<pair<int,int>>s;
void func() {

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		while (!s.empty()) {
			if (s.top().first < num) {
				s.pop();
			}
			else {
				cout << s.top().second << " ";
				s.push({ num,i + 1 });
				break;
			}
		}
		if (s.empty()) {
			cout << 0 << " ";
			s.push({num,i+1});
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
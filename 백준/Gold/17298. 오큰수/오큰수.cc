#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int>v(n);
	vector<int>answer(n);
	answer[n - 1] = -1;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	stack<int>s;
	s.push(v[n - 1]);
	
	for (int i = n-2; i >= 0; i--) {
		int cur_top = s.top();
		if (v[i] < cur_top) {
			answer[i]=cur_top;
			s.push(v[i]);
		}
		else {
			while (!s.empty()) {
				s.pop();
				if (s.empty()) {
					answer[i] = -1;
					break;
				}
				cur_top = s.top();
				if (v[i] < cur_top) {
					answer[i]=cur_top;
					break;
				}
			}
			s.push(v[i]);
		}
	}

	for (auto p : answer) {
		cout << p << " ";
	}

	return 0;
}
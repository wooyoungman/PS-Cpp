#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int g;

void func() {
	// cur의 제곱 - prev의 제곱 <= 10만
	// 50000 제곱 - 49999 제곱 = 99999
	// 최대 50000까지 확인하면 된다. 
	vector<int>ans;
	int prev = 1, cur = 1;
	while (cur<g) {
		int dif = cur * cur - prev * prev;
		if (dif == g)ans.push_back(cur);
		if (dif < g)cur++;
		else prev++;
	}
	if (ans.empty())cout << -1;
	else {
		for (auto p : ans)cout << p << "\n";
	}
}

int main() {
	cin >> g;
	func();
	return 0;
}
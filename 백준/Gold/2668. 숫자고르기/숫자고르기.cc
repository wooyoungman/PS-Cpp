#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int n;
int nums[101];
bool visit[101];
vector<int>ans;

void recur(int start, int cur) {
	if (visit[cur]) {
		if (start == cur) {
			ans.push_back(start);
		}
	}
	else {
		visit[cur] = true;
		recur(start, nums[cur]);
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}

	for (int i = 1; i <= n; i++) {
		memset(visit, 0, sizeof(visit));
		recur(i, i);
	}
	cout << ans.size() << "\n";
	for (auto p : ans) {
		cout << p << "\n";
	}
	return 0;
}
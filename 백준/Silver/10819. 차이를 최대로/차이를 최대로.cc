#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, ans;
vector<int>v;
int save[8];
bool check[8];
void input() {
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
}

void calAns() {
	int cur_ans = 0;
	for (int i = 0; i < n-1; i++) {
		cur_ans += abs(save[i] - save[i + 1]);
	}
	ans = max(ans, cur_ans);
}

void func(int depth) {
	if (depth == n) {
		calAns();
	}
	for (int i = 0; i < n; i++) {
		if (!check[i]) {
			check[i] = true;
			save[depth] = v[i];
			func(depth + 1);
			check[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	input();
	func(0);
	cout << ans;
	return 0;
}
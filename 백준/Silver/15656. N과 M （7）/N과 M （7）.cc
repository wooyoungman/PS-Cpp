#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int N, M;
vector<int> v;
int ans[10];
bool check[10];

void print_ans() {
	for (auto i : ans) {
		if (i != 0) {
			cout << i << " ";
		}
	}
	cout << "\n";
}

void recur(int depth) {
	if (depth == M) {
		print_ans();
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!check[i]) {
			ans[depth] = v[i];
			recur(depth + 1);
		}
	}
}



int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	recur(0);
	return 0;
}
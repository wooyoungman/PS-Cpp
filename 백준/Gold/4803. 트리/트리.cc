#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

int n, m;

int parents[501];
void init() {
	for (int i = 1; i <= n; i++) {
		parents[i] = i;
	}
}

int findParent(int tar) {
	
	if (tar == parents[tar])return tar;
	
	int ret = findParent(parents[tar]);

	parents[tar] = ret;

	return ret;

}

void setUnion(int a, int b) {
	int retA = findParent(a);
	int retB = findParent(b);
	if (retA < retB) {
		parents[retB] = retA;
	}
	else if (retA > retB) {
		parents[retA] = retB;
	}
	// 사이클인경우 0으로
	else {
		parents[retA] = 0;
		parents[retB] = 0;

	}
}

void func() {
	int caseNum = 1;
	while (1) {
		//freopen("input.txt", "r", stdin);
		cin >> n >> m;
		if (n == 0 && m == 0)break;
		int ans = 0;
		init();
		for (int i = 0; i < m; i++) {
			int s, e;
			cin >> s >> e;
			// 트리 연결 
			setUnion(s, e);
		}

		// 트리 카운트
		for (int i = 1; i <= n; i++) {
			if (parents[i] == i)ans++;
		}

		if (ans == 0) {
			cout << "Case " << caseNum++ << ": " << "No trees.\n";
		}
		else if (ans == 1) {
			cout << "Case " << caseNum++ << ": " << "There is one tree.\n";
		}
		else {
			cout << "Case " << caseNum++ << ": " << "A forest of "<<ans<<" trees.\n";
		}
	}
}

int main() {
	func();
	return 0;
}
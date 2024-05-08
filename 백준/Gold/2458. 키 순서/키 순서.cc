#include<iostream>
using namespace std;

int n, m, ans;
int len[501][501];
void func() {
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		len[a][b] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				// 학생 i가 k보다 작고 k가 j보다 작으면
				// i는 j보다 작다
				if (len[i][k] && len[k][j]) {
					len[i][j] = 1;
				}
			}
		}
	}

	// 하나라도 대소비교를 못하면 답 x
	for (int i = 1; i <= n; i++) {
		bool flag = true;
		for (int j = 1; j <= n; j++) {
			if (i == j)continue;
			if (len[i][j] == 0 && len[j][i] == 0) {
				flag = false;
				break;
			}
		}
		if (!flag)continue;
		ans++;
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	func();
	cout << ans;
	return 0;
}
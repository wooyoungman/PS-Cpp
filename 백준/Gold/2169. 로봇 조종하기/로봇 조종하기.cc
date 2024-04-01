#include<iostream>
#include<algorithm>  

using namespace std;
int n, m;
int map[1001][1001];

// 왼쪽->오른쪽, 오른쪽->왼쪽 둘 다 가능
//int ans[1001][1001];
int lrdp[1001][1001];
int rldp[1001][1001];
int ans[1001][1001];
int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	lrdp[0][0] = map[0][0];
	rldp[0][0] = map[0][0];
	ans[0][0] = map[0][0];
	for (int i = 1; i < m; i++) {
		lrdp[0][i] = lrdp[0][i - 1] + map[0][i];
		rldp[0][i] = lrdp[0][i];
		ans[0][i] = lrdp[0][i];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j == 0) {
				lrdp[i][j] = lrdp[i - 1][j] + map[i][j];
			}
			else {
				lrdp[i][j] = max(lrdp[i - 1][j],lrdp[i][j - 1])+map[i][j];
			}
		}
		for (int j = m - 1; j >= 0; j--) {
			if (j == m - 1) {
				rldp[i][j] = rldp[i - 1][j] + map[i][j];
			}
			else {
				rldp[i][j] = max(rldp[i - 1][j], rldp[i][j + 1]) + map[i][j];
			}
		}
		for (int j = 0; j < m; j++) {
			lrdp[i][j] = max(lrdp[i][j], rldp[i][j]);
			rldp[i][j] = lrdp[i][j];
		}
	}
	cout << rldp[n - 1][m - 1];
	return 0;
}
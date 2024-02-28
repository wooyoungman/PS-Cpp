#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;

// n = 맵 크기
// m = 벌통의 크기 (depth + m 까지 한 번에 뽑아야함)
// c = 벌통에서 최대 구할 수 있는 꿀의 양 
int t, n, m, c, ans ,ans1, ans2;
int map[11][11];
string ox = "OX";
int path[2][5];
char part_path[5];
void init() {
	memset(map, 0, sizeof(map));
	memset(path, 0, sizeof(path));
	ans = 0;
	ans1 = 0;
	ans2 = 0;
}

void input() {
	cin >> n >> m >> c;
	int num;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
}

void partGetSum(int num) {
	int sum = 0;
	for (int i = 0; i < m; i++) {
		if (part_path[i] == 'O') {
			sum += path[num][i];
		}
	}
	//cout << sum << "\n";
	if (sum <= c) {
		int pSum = 0;
		for (int i = 0; i < m; i++) {
			if (part_path[i] == 'O') {
				pSum += pow(path[num][i], 2);
			}
		}
		if (num == 0) {
			ans1 = max(ans1, pSum);
		}
		else {
			ans2 = max(ans2, pSum);
		}
	}
	return;
}

void part_recur(int depth, int num) {
	if (depth == m) {
		// C이하의 벌꿀이라면 ans 갱신
		partGetSum(num);
		return;
	}

	for (int i = 0; i < 2; i++) {
		part_path[depth] = ox[i];
		part_recur(depth + 1, num);
	}

}


void recur(int depth, int y, int x) {
	if (depth == 2) {
		// 두 일꾼이 선택 완료
		// 1번 일꾼의 최대
		part_recur(0, 0);
		// 2번 일꾼의 최대
		part_recur(0, 1);
		ans = max(ans, ans1 + ans2);
		ans1 = 0;
		ans2 = 0;
		return;
	}
	
	for (int i = y; i < n; i++) {
		for (int j = x; j < n - (m - 1); j++) {
			for (int k = 0; k < m; k++) {
				path[depth][k]=map[i][j+k];
			}
			recur(depth + 1, i, j + m);
		}
		x = 0;
	}

}

int main() {

	//freopen("input.txt", "r", stdin);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		init();
		input();
		recur(0, 0, 0);
		cout << "#" << i << " " << ans << "\n";
	}


	return 0;
}
#include <iostream>

using namespace std;

int n, m;
int oy, ox;
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

char map[11][11];
bool ans;
bool isValid(int y, int x) {
	return y >= 0 && y < n && x >= 0 && x < m && map[y][x] != '#';
}

void func(int ry, int rx, int by, int bx, int depth) {
	// 10회를 초과했는가?
	if (depth >= 10)return;

	// 4방향으로 이동하기 위한 값 복사
	int cry = ry;
	int crx = rx;
	int cby = by;
	int cbx = bx;

	//cout << ry << " " << rx << " " << by << " " << bx << " "<<depth << "\n";
	for (int i = 0; i < 4; i++) {
		// 빨간 구슬
		ry = cry;
		rx = crx;
		by = cby;
		bx = cbx;

		int move_cnt_red = 0;
		bool check_red = false;
		while (1) {
			int ny = ry + dy[i];
			int nx = rx + dx[i];
			if (!isValid(ny, nx))break;
			ry = ny;
			rx = nx;
			move_cnt_red++;
			// 구멍에 빠졌는지 확인
			if (ry == oy && rx == ox) {
				check_red = true;
				break;
			}
		}

		// 파란 구슬
		int move_cnt_blue = 0;
		bool check_blue = false;
		while (1) {
			int ny = by + dy[i];
			int nx = bx + dx[i];
			if (!isValid(ny, nx))break;
			by = ny;
			bx = nx;
			move_cnt_blue++;
			// 구멍에 빠졌는지 확인
			if (by == oy && bx == ox) {
				check_blue = true;
				break;
			}
		}


		// 구멍에 빨간 구슬만 빠졌는지 확인
		if (check_red && !check_blue) {
			ans = true;
			return;
		}

		// 파란 구슬이 빠진 경우 재귀 x
		if (check_blue) {
			continue;
		}

		// 두 구슬이 겹쳤을 때
		if (ry == by && rx == bx) {
			// 이동 전 위치 판단
			// 파란 구슬이 뒤에 있는 경우
			if (move_cnt_blue > move_cnt_red) {
				by += dy[(i + 2) % 4];
				bx += dx[(i + 2) % 4];
			}
			// 빨간 구슬이 뒤에 있는 경우
			else if (move_cnt_blue < move_cnt_red){
				ry += dy[(i + 2) % 4];
				rx += dx[(i + 2) % 4];
			}

		}
		func(ry, rx, by, bx, depth + 1);
	}
}

int main() {
	int ry, rx, by, bx;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'B') {
				by = i;
				bx = j;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'R') {
				ry = i;
				rx = j;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'O') {
				oy = i;
				ox = j;
			}
		}
	}
	func(ry, rx, by, bx, 0);
	if (ans)cout << 1;
	else cout << 0;
	return 0;
}
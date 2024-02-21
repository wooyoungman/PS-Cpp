#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#define MAX INT_MAX
using namespace std;


int n, m, ans = MAX;
int map[10][10];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
vector<pair<int, int>> cctv;

void update(int y, int x, int dir) {
    while (true) {
        y += dy[dir];
        x += dx[dir];
        if (y < 0 || y >= n || x < 0 || x >= m || map[y][x] == 6) break;
        if (map[y][x] == 0) map[y][x] = -1;
    }
}

void recover(int temp[10][10]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            map[i][j] = temp[i][j];
        }
    }
}

void dfs(int depth) {
    if (depth == cctv.size()) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 0) cnt++;
            }
        }
        ans = min(ans, cnt);
        return;
    }

    // 값을 업데이트 후 다시 복구시키기 위한 temp 배열
    // 현재 map을 복사한 후, 재귀문 종료 후 map에 다시 temp 저장 
    int temp[10][10];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[i][j] = map[i][j];
        }
    }

    // cctv의 좌표, 번호
    int y = cctv[depth].first;
    int x = cctv[depth].second;
    int num = map[y][x];

    if (num == 1) {
        for (int d = 0; d < 4; d++) {
            update(y, x, d);
            dfs(depth + 1);
            recover(temp);
        }
    }
    else if (num == 2) {
        for (int d = 0; d < 2; d++) {
            update(y, x, d);
            update(y, x, d + 2);
            dfs(depth + 1);
            recover(temp);
        }
    }
    else if (num == 3) {
        for (int d = 0; d < 4; d++) {
            update(y, x, d);
            update(y, x, (d + 1) % 4);
            dfs(depth + 1);
            recover(temp);
        }
    }
    else if (num == 4) {
        for (int d = 0; d < 4; d++) {
            update(y, x, d);
            update(y, x, (d + 1) % 4);
            update(y, x, (d + 2) % 4);
            dfs(depth + 1);
            recover(temp);
        }
    }
    else if (num == 5) {
        for (int d = 0; d < 4; d++) {
            update(y, x, d);
        }
        dfs(depth + 1);
        recover(temp);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] >= 1 && map[i][j] <= 5) {
                cctv.push_back({ i, j });
            }
        }
    }

    dfs(0);

    cout << ans;

    return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
 
 
int t, n;
int start_y,start_x;
bool check[101];
int move_rd, move_ld, move_lu,move_ru;
int map[21][21];
int ans;
using namespace std;
 
void dfs(int depth,int y,int x) {
     
    check[map[y][x]] = true;
     
    //if (start_y == 0 && start_x == 1) {
    //  cout << depth << " " << y << " " << x << " " << map[y][x]<<" "<< "\n";
    //}
 
    // 우하
    if (((y + 1) <= n - 1) && ((x + 1) <= n - 1) && !check[map[y + 1][x + 1]]&& map[y + 1][x + 1] != 0&&move_ld==0&&move_lu==0&&move_ru==0) {
        check[map[y + 1][x + 1]] = true;
        move_rd++;
        dfs(depth + 1, y + 1, x + 1);
        check[map[y + 1][x + 1]] = false;
        move_rd--;
    }
 
    // 좌하
    if (((y + 1) <= n - 1) && ((x - 1) >=0) && !check[map[y + 1][x - 1]] && map[y + 1][x - 1] != 0 && move_rd > 0 && move_lu == 0 && move_ru == 0) {
        check[map[y + 1][x - 1]] = true;
        move_ld++;
        dfs(depth + 1, y + 1, x - 1);
        check[map[y + 1][x - 1]] = false;
        move_ld--;
    }
 
    // 좌상
    if (((y - 1) >= 0) && ((x - 1) >= 0) && !check[map[y - 1][x - 1]] && map[y - 1][x - 1] != 0&&move_ld>0&&move_rd>0&&move_ru==0) {
        check[map[y - 1][x - 1]] = true;
        move_lu++;
        dfs(depth + 1, y - 1, x - 1);
        check[map[y - 1][x - 1]] = false;
        move_lu--;
    }
 
    // 우상
    if (((y - 1) >= 0) && ((x + 1) <=n-1) && !check[map[y - 1][x + 1]] && map[y - 1][x + 1] != 0&&(move_rd==move_lu)&&move_ld>0) {
        check[map[y - 1][x + 1]] = true;
        move_ru++;
        dfs(depth + 1, y - 1, x + 1);
        check[map[y - 1][x + 1]] = false;
        move_ru--;
    }
 
    else if (((y - 1) >= 0) && ((x + 1) <=n-1) &&check[map[y - 1][x + 1]] && ((y - 1) == start_y) && ((x + 1) == start_x)&&(move_rd==move_lu)&&(move_ld==move_ru+1)) {
        ans = max(ans, depth+1);
        /*cout << ans << " " << start_y << " " << start_x  << " 현재 depth는 "<<depth<<"\n";*/
        return;
    }
}
 
 
int main() {
    //freopen("sample_input.txt", "r", stdin);
    cin >> t;
    for (int i = 1; i <= t; i++) {
        memset(map, 0, sizeof(map));
        memset(check, false, sizeof(check));
        if (i == 10) {
            int de = 1;
        }
        ans = -1;
        cin >> n;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cin >> map[j][k];
            }
        }
 
        // (0,1) 기준 (n-2) x (n-2) 사각형 좌표로 탐색 시작
        // 현재 지점으로 돌아오는 경우 depth값 갱신 (최대로) 
        for (int y = 0; y < n - 2;y++) {
            for (int x = 1; x <= n - 2;x++) {
                memset(check, false, sizeof(check));
                start_y = y;
                start_x = x;
                move_ld = 0;
                move_lu = 0;
                move_rd = 0;
                move_ru = 0;
                dfs(0,y,x);
            }
        }
 
        cout << "#" << i << " " << ans << "\n";
    }
 
    return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<limits.h>
#define MAX INT_MAX
using namespace std;

int T, N, W, H;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,-1,1 };

int stone[15][20];
// 하나의 구슬로 폭파시키는 경우 임시 맵을 통해 재귀 함수 적용
int temp_stone[15][20];

int save_top[5];
int cnt_top;
int ans;
struct Stone_info {
    int y, x, cnt;
};

void init() {
    
    memset(temp_stone, 0, sizeof(temp_stone));
    memset(stone, 0, sizeof(stone));
    memset(save_top, 0, sizeof(save_top));
    cnt_top = 0;
    ans = MAX;
}

void input() {

    cin >> N >> W >> H;
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            cin >> stone[y][x];
        }
    }

}

void down_stone(){

    // 벽돌을 내리는 경우는 빈칸 위에 1이상인 벽돌이 있는 경우이다.
    // 가장 아래칸부터 (현재 자신 - 1)부터 0까지 벽돌 값이 1이상인 경우를 찾는다.
    // 찾았으면 값을 바꾼다.
    // 0번까지 이 과정을 반복한다.

    for (int i = 0; i < W; i++) {
        for (int j = H - 1; j >= 0; j--) {
            // temp_stone[j][i]==0인 경우를 찾았으면 (현재 빈칸인 곳을 찾았으면) 0번까지 벽돌이 있는지 확인(1이상인지)
            if (temp_stone[j][i] == 0) {
                for (int k = j - 1; k >= 0; k--) {
                    // 빈칸에서 가장 가까운 벽돌과 값 변경 후 j+1후 반복문 다시 재생 
                    if (temp_stone[k][i] > 0) {
                        temp_stone[j][i] = temp_stone[k][i];
                        temp_stone[k][i] = 0;
                        break;
                    }
                }
            }
        }
    }

}

void func() {


    // save_top에 현재 구슬을 떨어뜨릴 위치가 선정이 완료된 상태

    // 하나의 구슬 조합에 대해 탐색할 벽돌 임시 맵 생성
    // 모든 구슬 조합에 대해 최대로 많이 부수는 경우를 탐색해야하기 때문
    memcpy(temp_stone, stone, sizeof(temp_stone));
    int cnt = 0;
    // N개의 구슬 쏘기
    for (int i = 0; i < N; i++) {
        // 처음 터지는 벽돌을 저장하고, 이에 대해 DFS 재진행
        queue<Stone_info>q;

        for (int j = 0; j < H; j++) {
            // save_top[i] 열에 가장 먼저 벽돌이 있는 행에서 처음으로 터짐
            if (temp_stone[j][save_top[i]] > 0) {
                // 가장 처음 터지는 벽돌의 좌표와 벽돌 값 저장
                q.push({ j,save_top[i],temp_stone[j][save_top[i]] });
                temp_stone[j][save_top[i]] = 0;
                // 하나의 구슬에 대해서 가장 먼저 터지는 벽돌을 찾았으니 반복문 종료 후 폭파 시작
                break;
            }
        }

        while (!q.empty()) {
            // 가장 먼저 터진 벽돌 꺼내기
            Stone_info cur = q.front();
            q.pop();

            // 상하좌우 탐색
            for (int j = 0; j < 4; j++) {
                Stone_info next = cur;
                // 하나의 방향에 대해서 현재 벽돌 값 -1만큼 연속 폭파
                for (int k = 0; k < cur.cnt-1; k++) {
                    next.y += + dy[j];
                    next.x += + dx[j];

                    // 허용 범위 확인 (더이상 못가면 현재 방향에 대해서 폭파 중지)
                    if (next.y < 0 || next.x < 0 || next.y >= H || next.x >= W) break;

                    // 벽돌이 아닌 경우 (벽돌 값 0인 경우)
                    if (temp_stone[next.y][next.x] == 0) {
                        // 폭파 중지가 아닌 건너 뛰기
                        continue;
                    }

                    // 터지는 벽돌인 경우 큐에 담아서 다음 폭파 진행
                    // 벽돌의 좌표, 값 그대로 담고 벽돌 값 0으로 변경(큐에는 정상으로 들어가지만, 폭파를 완료했다는 의미로 0)
                    next.cnt = temp_stone[next.y][next.x];
                    q.push(next);
                    temp_stone[next.y][next.x] = 0;

                }
            }
        }

        // 하나의 구슬로 폭파 완료 후 위에 벽돌 밑으로 떨어뜨리기
        down_stone();

    }
    // 결과 확인
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (temp_stone[i][j] > 0) {
                cnt++;
            }
        }
    }
    if (ans > cnt) {
        ans = cnt;
    }

}


void choose_top(int depth) {
    if (depth == N) {
        // 현재 N개의 출발 지점 선택이 완료
        // dfs 시작
        func();
        return;
    }
    for (int i = 0; i < W; i++) {
        save_top[depth] = i;
        choose_top(depth + 1);
    }


}

int main() {
   // freopen("sample_input.txt", "r", stdin);
    cin >> T;
    for (int i = 1; i <= T; i++) {
        init();
        input();

        // 0~W-1까지의 열 중 중복순열로 떨어뜨릴 위치를 구한다.
        choose_top(0);
        

        cout << "#" << i << " " << ans << "\n";
        
    }

    return 0;
}
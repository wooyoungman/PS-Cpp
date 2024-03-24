#include <iostream>
#include <deque>
using namespace std;

int n, k,ans=1;
deque<int>belt;
deque<int>robot;

bool func() {

    // 벨트 회전
    int b_tail = belt.back();
    belt.pop_back();
    belt.push_front(b_tail);


    // 로봇이 올라가 있으면 같이 회전 (내구도 감소 x)   
    robot.pop_back();
    robot.push_front(0);

    // 회전 후 로봇이 n-1칸에 존재하면 제거
    if (robot.back() == 1) {
        robot[n - 1] = 0;
    }

    // 로봇 이동
    for (int i = n - 2; i >= 0; i--) {
        int cur = robot[i];
        int next = robot[i + 1];
        if (cur == 0 || next != 0 || belt[i + 1] <= 0) continue;
        robot[i + 1] = 1;
        robot[i] = 0;
        belt[i + 1]--;
    }

    // 로봇 올리기
    if (belt[0] > 0) {
        belt[0]--;
        robot[0] = 1;
    }

    int cnt = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (belt[i] == 0)cnt++;
        if (cnt >= k)return true;
    }
    return false;
}

int main() {
    cin >> n >> k;
    belt.resize(2 * n);
    robot.resize(n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> belt[i];
    }
    while (!func()) {
        ans++;
    }
    cout << ans;
    return 0;
}
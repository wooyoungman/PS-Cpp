#include<iostream>

#include<vector>
using namespace std;

int n, m;
vector<int>nums[2001];
bool visited[2001];
int ans;
void func(int depth, int cur) {

    if (depth == 4)ans = 1;
    if (ans == 1)return;

    for (auto p : nums[cur]) {
        if (visited[p])continue;
        visited[p] = true;
        func(depth + 1, p);
        visited[p] = false;
    }
    
}

int main() {

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        nums[a].push_back(b);
        nums[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        if (nums[i].empty())continue;
        if (ans == 1)break;
        visited[i] = true;
        func(0, i);
        visited[i] = false;
    }

    cout << ans;


    return 0;
}


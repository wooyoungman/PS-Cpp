#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int n;
int arr1[100];
int arr2[100];
bool check[100];
int start_num;
int cnt;
int save;
int temp;
vector<int>same;
vector<int>chain;
set<int>ans;
// 1 2 3
// 3 2 1
// -> 1 -> 3 -> 1 
// 출발 지점과 마지막 지점이 동일하면 가능한 것
// 거기에 서로 숫자가 같은 것 더해서 정답 출력 
// 즉 사이클이 있으면 모두 담기 !

// 1. 첫째 둘째 줄의 값이 같은 것 먼저 체크 후 개수 파악
// 2. 첫째 줄의 첫번째 부터 재귀로 가장 긴 연결 부분 찾고 개수 파악
// 첫째(1) -> 둘째(3) -> 첫째(3) -> 둘째(1) (둘째 줄 값이 첫째 줄 값과 동일한 연결 고리)
// 3. 둘의 합 출력

void recur(int idx) {
    if (arr2[idx] == arr1[arr2[idx]-1] && !check[arr2[idx]-1]) {
        check[arr2[idx] - 1] = true;
        save++;
        chain.push_back(arr1[idx]);
        if (arr2[idx] == start_num) {
            
            for (auto p : chain) {
                ans.insert(p);
            }
            
        }
        recur(arr2[idx]-1);
        save--;
        chain.pop_back();
        check[arr2[idx] - 1] = false;
    }
    return;

}

int main() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        arr1[i] = i + 1;
        cin >> arr2[i];
        if (arr1[i] == arr2[i]) {
            cnt++;
            check[i] = true;
            same.push_back(i+1);
        }
    }
    for (int i = 0; i < n; i++) {
        if (check[i])continue;
        start_num = arr1[i];
        save = 0;
        recur(i);
    }
    cnt += ans.size();
    cout << cnt<<"\n";

    for (auto p : same) {
        ans.insert(p);
    }
    //sort(ans.begin(), ans.end());
    for (auto p : ans) {
        cout << p << "\n";
    }
    return 0;
}
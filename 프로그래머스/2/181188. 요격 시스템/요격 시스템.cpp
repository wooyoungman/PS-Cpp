#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 처음에 map을 이용하여 x좌표 범위에 해당하는 개수를 저장하여 풀이를 진행하려고 했다.
// 그러나 for문이 2개 이상 나오는 방법 밖에 생각이나지 않았다.
// DP로 풀어야 하나 생각하던 중 일부분을 이용해서 뒤에 까지 계산이 불가능 한 것을 알았다.
// 전체 경우를 따져야 하는 Greedy기법을 떠올렸고 아래와 같이 해결하게 되었다.

// 우선 [s,e]에서 시작 지점인 s,e를 기준으로 오름차순 정렬을 한다.
// 현재 e(end)가 다음 시작 지점인 s(start)보다 큰 경우 추가 요격이 필요하지 않다. (하나의 미사일로 동시 격추 가능)
// 이 경우 현재 end를 다음 종료 지점과 비교하였을 때 더 작은 것으로 한다. (이후에도 동시 격추 가능 판단을 위해)
// 반대로 같거나 작은 경우 동시 격추가 불가능한 범위에 존재하므로 추가 요격이 필요하다.
// 이 경우 현재 start와 end 모두 갱신한다.

// bool cmp(vector<int>a,vector<int>b){
//     if(a[0]==b[0]) return a[1]>b[1];
//     return a[0]>b[0];
// }

int solution(vector<vector<int>> targets) {
    int answer = 0,cur_end=0,next_start=0,next_end=0;
    sort(targets.begin(),targets.end());
    for(int i=0;i<targets.size();i++){
        next_start=targets[i][0];
        next_end=targets[i][1];
        if(cur_end>next_start){
            cur_end=min(cur_end,next_end);
        }
        else{
            answer++;
            cur_end=next_end;
        }
    }
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int dp1[1000001];
int dp2[1000001];

int solution(vector<int> money) {
    int answer = 0;
    int last_idx=money.size()-1;
    
    // 원형 탐색 -> 첫번째 유무에 따라 끝 배열 선택이 달라진다.
    // 배열을 2개로 나누어 탐색 (첫번째 유무 따라)
    // dp1 (첫번째 선택 o), dp2 (첫번째 선택 x)
    
    dp1[0]=money[0];
    dp1[1]=money[0];
    
    dp2[0]=0;
    dp2[1]=money[1];
    
    for(int i=2;i<=last_idx;i++){
        dp1[i]=max(dp1[i-2]+money[i],dp1[i-1]);
        dp2[i]=max(dp2[i-2]+money[i],dp2[i-1]);
    }
    
    answer=max(dp1[last_idx-1],dp2[last_idx]);
    return answer;
}
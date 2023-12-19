#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 1. rocks 배열을 오름차순으로 정렬하기
// 2. 거리를 최대부터 이분탐색으로 줄여나갔을 때 n개 이하를 삭제하였다면 정답 갱신하기

// 2 9 3 3 4 4

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    rocks.push_back(distance);
    sort(rocks.begin(),rocks.end());
    
    int left=0,right=distance;
    while(left<=right){
        int mid=(left+right)/2;
        int prev_rock=0,rm_rock_cnt=0;
        for(auto d:rocks){
            if(d-prev_rock<mid){
                rm_rock_cnt++;
            }
            else{
                prev_rock=d;
            }
        }
        if(rm_rock_cnt<=n){
            answer=max(mid,answer);
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    
    return answer;
}
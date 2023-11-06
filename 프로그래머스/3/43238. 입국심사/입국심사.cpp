#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 이분탐색 활용 문제
// 처음에는 timer를 이용하여 현재 경과 시간이 각 심사대 별 소요시간으로 나누어 떨어지면
// 사람을 하나씩 넣는 방법을 생각하였다.
// 하지만 시간초과와 더 빨리 끝나는 심사대가 있을 때 효율적인 처리 방법을 생각해내지 못했다.
// 따라서 최소 시간과 최대 시간의 그래프를 그리고
// mid 값이 모든 사람을 심사할 수 있는지 판단하며 이분 탐색을 활용하기로 했다.

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long timer=0;
    int judge_people=times.size();

    sort(times.begin(),times.end());
    
    long long min_time=1;
    long long max_time=(long long)n*(long long)times.back();
    long long mid;
    
    while(min_time<=max_time){
        long long cnt=0;
        mid=(min_time+max_time)/2;
        for(int i=0;i<judge_people;i++){
            cnt+=mid/(long long)times[i];
        }
        if(cnt>=n){
            max_time=mid-1;
            answer=mid;
        }
        else{
            min_time=mid+1;         
        }
    }
    return answer;
}
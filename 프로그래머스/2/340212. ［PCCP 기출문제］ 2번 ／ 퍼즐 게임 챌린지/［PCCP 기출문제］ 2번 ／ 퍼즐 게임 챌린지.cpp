#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    // 틀릴 때 마다 쓰는 시간 (cur + prev) + 푸는 데 쓰는 시간(cur)
    
    // 1. diff <= level : cur만 사용해서 해결
    // 2. diff > level : diff - level만큼 틀리고 풀기
    
    long long level_right=100000;
    long long level_left=1;
    
    while(level_left<=level_right){
        
        long long level_mid = (level_right+level_left)/2;
        long long cur_times=0;
        for(int i=0;i<diffs.size();i++){
            if(diffs[i]<=level_mid){
                cur_times+=times[i];
            }
            else{
                cur_times+=(diffs[i]-level_mid)*(times[i]+times[i-1])+times[i];
            }
        }
        //cout<<level_mid<<" "<<cur_times<<"\n";
        if(cur_times<=limit){
            level_right=level_mid-1;
            answer=level_mid;
        }
        else{
            level_left=level_mid+1;
        }
    }

    
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

// 작업시간이 작은 순서대로 처리
// 대기시간(앞 작업의 소요시간) - 요청시간(현재 작업의 요청시간) + 소요시간(현재 작업의 소요시간) 

bool cmp(vector<int>a, vector<int>b){
    return a[1]<=b[1];
}


int solution(vector<vector<int>> jobs) {    
    int answer = 0;
    int time=0;
    int jobs_size=jobs.size();
    // 작업 소요 시간이 작은 순 (오름차순)으로 정렬
    sort(jobs.begin(),jobs.end(),cmp);
    
    while(1){
        // 현재 경과 시간 >= 현재 작업 요청 시간인 경우 
        // 현재 경과시간에 작업 소요 시간만큼 추가
        
        // answer에는 (현재 경과 시간 - 현재 작업 요청 시간) 추가
        // 작업을 처리 했으니 jobs 벡터에서 제거
        // 현재 경과 시간에서 처리할 작업이 없으면 현재 경과 시간 +=1
        
        for(int i=0;i<jobs.size();i++){
            if(time>=jobs[i][0]){
                time+=jobs[i][1];
                answer+=(time - jobs[i][0]);
                jobs.erase(jobs.begin()+i);
                break;
            }
            if(i==jobs.size()-1)time++;
        }
        if(jobs.empty()) break;
    }
    return answer/jobs_size;
}
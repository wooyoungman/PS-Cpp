#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

bool compare(vector<string> a,vector<string> b){
    if(a[1]==b[1]){
        return a[0]<b[0];
    }
    else{
        return a[1]<b[1];
    }
}

// 우선 compare 함수를 만들어서 시작 시간이 빠른 순서로 정렬한다.
// 복잡한 시간을 분 단위로 단순화 시킨다.
// 현재 진행 중인 과제가 끝나지 않았다면 다른 벡터에 진행 중이었던 과제 이름과 남은 시간을 저장한다.
// 다음 과제를 진행한다.
// 만약 과제가 먼저 끝난다면 정답 벡터에 추가한다.
// 남은 시간동안 멈추었던 과제를 진행한다.
// 만약 멈추었던 과제가 남은 시간 안에 종료되면 정답 벡터에 추가, 그렇지 않으면 남은 시간만 감소한다.
// 주어진 시작 시간에 대한 탐색을 마친 후 남아 있는 멈춘 과제들을 최근 순서대로 정답 벡터에 추가한다.

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    sort(plans.begin(),plans.end(),compare);
    vector<pair<string,int>>stop_mission;
    int cur_time=0;
    for(int i=0;i<plans.size();i++){
        int start_time=(stoi(plans[i][1].substr(0,2))*60+stoi(plans[i][1].substr(3,2)));
        
        while(cur_time<start_time){
            if(!stop_mission.empty()){
                stop_mission.back().second--;
                if(stop_mission.back().second==0){
                    answer.push_back(stop_mission.back().first);
                    stop_mission.pop_back();
                }
            }
            cur_time++;
        }
        stop_mission.push_back(make_pair(plans[i][0],stoi(plans[i][2])));
       }
    while(!stop_mission.empty()){
        answer.push_back(stop_mission.back().first);
        stop_mission.pop_back();
    }
    return answer;
}
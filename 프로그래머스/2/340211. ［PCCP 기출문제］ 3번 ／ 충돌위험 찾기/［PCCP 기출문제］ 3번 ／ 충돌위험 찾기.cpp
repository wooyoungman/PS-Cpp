#include <string>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;
// 포인트의 좌표
unordered_map<int,pair<int,int>> pos;
// 로봇의 시간대 별 누적 경로
vector<map<pair<int,int>,int>> path_count;
int answer;

void movePath(vector<int>&r){
    pair<int,int> final;
    int time=0;
    // r은 {1,2,3,4} 처럼 이동할 포인트에 대한 경로로 나와있으니 1->2, 2->3, 3->4 순서로 이동한다.
    for(int i=0;i<r.size()-1;i++){
        // 현재 좌표
        pair<int,int>s=pos[r[i]];
        // 다음 좌표
        pair<int,int>e=pos[r[i+1]];
        final=e;
        
        while(s!=e){
            // 현재 시간에 s라는 좌표에 로봇이 1개 이동했다는 의미
            path_count[time][s]++;
            if(path_count[time][s]==2)answer++;
            int dy=s.first-e.first;
            int dx=s.second-e.second;
            
            if(dy!=0){
                if(dy>0)s.first--;
                else s.first++;
            }
            else if(dx!=0){
                if(dx>0)s.second--;
                else s.second++;
            }
            time++;
        }
    }
    // 도착
    path_count[time][final]++;
    if(path_count[time][final]==2)answer++;
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    
    for(int i=0;i<points.size();i++){
        // 각 포인트에 대한 좌표 저장
        pos[i+1]={points[i][0],points[i][1]};
    }
    path_count.resize(100001);
    
    for(auto p:routes){
        movePath(p);
    }
    
    return answer;
}
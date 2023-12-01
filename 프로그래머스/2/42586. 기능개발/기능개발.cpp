#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<pair<int,int>>q;
    for(int i=0;i<progresses.size();i++){
        q.push(make_pair(progresses[i],speeds[i]));
    }
    while(!q.empty()){
        for(int i=0;i<q.size();i++){
            int cur_progress=q.front().first;
            int cur_speed=q.front().second;
            cur_progress+=cur_speed;
            q.pop();
            q.push(make_pair(cur_progress,cur_speed));
        }
        int cnt=0;
        while(!q.empty()&&q.front().first>=100){
            //cout<<q.front().first<<" ";
            q.pop();
            cnt++;
        }
        if(cnt>0){
            answer.push_back(cnt);
        }
    }
    return answer;
}
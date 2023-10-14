#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    int trash_cnt=score.size()%m;
    priority_queue<int,vector<int>,greater<>>q;
    for(int i=0;i<score.size();i++){        
        q.push(score[i]);
    }
    for(int i=0;i<trash_cnt;i++){
        q.pop();
    }
    int len=q.size()/m;
    for(int i=0;i<len;i++){
        answer+=(q.top()*m);
        for(int j=0;j<m;j++){
             q.pop();   
        }
    }
    return answer;
}
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int>pq; 
    int cnt_num=0;
    int cnt_lowpop=0;
    vector<int> oper;
    for(int i=0;i<operations.size();i++){
        // 숫자 입력
        if(operations[i][0]=='I'){
            cnt_num++;
            pq.push(stoi(operations[i].substr(2)));
        }
        else if(operations[i]=="D 1"&&cnt_num>0){
            // 최댓값 추출   
            pq.pop();
            cnt_num--;
        }
        else if(operations[i]=="D -1"&&cnt_num>0){
            // 최솟값 추출 횟수 세기
            cnt_lowpop++;
            cnt_num--;
        }
    }
    if(cnt_num==0){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(pq.top());
        while(pq.size()>cnt_lowpop+1){
            pq.pop();
        }
        answer.push_back(pq.top());
    }
    return answer;
}
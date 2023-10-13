#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    // min heap인 우선순위 큐 선언
    priority_queue<int,vector<int>,greater<>> temp;
    for(int i=0;i<score.size();i++){
        bool check=false;
        if(temp.size()<k){
            temp.push(score[i]);
        }
        else{
            if(temp.top()<score[i]){
                temp.pop();
                temp.push(score[i]);
            }
        }
        answer.push_back(temp.top());
    }
    return answer;
}
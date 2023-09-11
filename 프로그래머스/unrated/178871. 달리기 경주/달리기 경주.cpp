#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string,int> m1;
    map<int,string> m2;
    
    for(int i=0;i<players.size();i++){
        m1[players[i]]=i;
        m2[i]=players[i];
    }
    for(int i=0;i<callings.size();i++){
        int cur=m1[callings[i]]; // 추월할 예정인 사람의 등수 
        string cur_front=m2[cur-1]; // 앞장 서있는 사람의 이름 
        m2[cur-1]=callings[i];
        m2[cur]=cur_front;
        m1[callings[i]]=cur-1;
        m1[cur_front]=cur;
        
    }
    for(auto p:m2){
        answer.push_back(p.second);
    }
    return answer;
}
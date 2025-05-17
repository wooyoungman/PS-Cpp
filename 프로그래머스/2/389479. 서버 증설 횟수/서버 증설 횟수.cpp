#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int>add_server;
int times[25];
int solution(vector<int> players, int m, int k) {
    int answer = 0;
    int idx=-1;
    
    for(auto p:players){
    int cur_server = 1;
        idx++;
        //cout<<"현재 시각 : "<<idx<<" ";
        for(int i=0;i<add_server.size();i++){
            if(add_server[i]>0)add_server[i]--;
            if(add_server[i]>0)cur_server++;
        }
        
        int max_player=m*cur_server;
        //cout<<"현재 시각 : "<<idx<<", 추가된 서버 수 : "<<add_server.size()<<", 추가 횟수 : "<<answer<<"\n";
        //cout<<"현재 시각 : "<<idx<<" 현재 서버 수 : "<<cur_server<<"\n";
        if(p<max_player)continue;
        
        int add_cnt=(p-max_player)/m+1;
        //cout<<" 추가해야하는 서버 수 : "<<add_cnt<<"\n";
        for(int i=0;i<add_cnt;i++){
         
            add_server.push_back(k);
            answer++;   
        }
        
        //cout<<"현재 시각 : "<<idx<<", 추가된 서버 수 : "<<add_server.size()<<", 추가 횟수 : "<<answer<<"\n";
    }
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

bool connected;
bool check[10001];
int connect_cnt=0;
vector<string> answer;

bool cmp(vector<string> a,vector<string> b){
    if(a[0]==b[0]){
        return a[1]<b[1];
    }
    return a[0]<b[0];
}

void dfs(string cur_airport,vector<vector<string>> tickets){
    
    // 모든 지점을 방문했지만 도중에 연결이 끊겨있는 경우 확인
    if(connect_cnt==tickets.size()){
        connected=true;
    }
    answer.push_back(cur_airport);
    connect_cnt++;
    for(int i=0;i<tickets.size();i++){
        if(!check[i]&&cur_airport==tickets[i][0]){
            check[i]=true;
            dfs(tickets[i][1],tickets);
            if(!connected){
                answer.pop_back();
                check[i]=false;
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(),tickets.end(),cmp);
    dfs("ICN",tickets);

    return answer;
}
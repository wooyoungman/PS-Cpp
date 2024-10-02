#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool visited[201];

void dfs(vector<vector<int>>computers, int num){
    for(int i=0;i<computers[num].size();i++){
        if(!visited[i]&&computers[num][i]==1){
            visited[i]=true;
            dfs(computers,i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0;i<computers.size();i++){
        for(int j=0;j<computers[i].size();j++){
            if(i==j){
                continue;
            }
            if(!visited[j]&&computers[i][j]==1){
                visited[j]=true;
                visited[i]=true;
                dfs(computers,j);
                answer++;
            }
        }
    }
    for(int i=0;i<computers.size();i++){
        if(!visited[i])answer++;
    }
    return answer;
}
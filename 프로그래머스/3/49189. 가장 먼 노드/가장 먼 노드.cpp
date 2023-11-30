#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;



int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int cnt = 1;
    
    // 양방향 노드를 위한 벡터
    vector<vector<int>>graph(n+1);
    
    for(int i=0;i<edge.size();i++){
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    
    
    // 현재 노드 번호 저장
    queue<int>q;
    
    // 떨어진 거리 저장할 벡터
    vector<int> distance(n+1,-1);
    distance[1]=0;
    
    q.push(1);
    
    while(!q.empty()){
        int cur_node=q.front();
        q.pop();
        for(auto to_node:graph[cur_node]){
            if(distance[to_node]==-1){
                q.push(to_node);
                distance[to_node]=distance[cur_node]+1;
            }   
        }
    }
    int max_distance=*max_element(distance.begin(),distance.end());
    answer=count(distance.begin(),distance.end(),max_distance);
    return answer;
}
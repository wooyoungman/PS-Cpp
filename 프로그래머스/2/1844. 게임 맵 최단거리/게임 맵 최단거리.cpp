#include<vector>
#include<queue>
#include<iostream>
using namespace std;

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    int n=maps.size();
    int m=maps[0].size();
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int check[101][101]={0,};
    check[0][0]=1;
    queue<pair<int,int>>q;
    q.push(make_pair(0,0));
    while(!q.empty()){
        int cur_x=q.front().first;
        int cur_y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int next_x=cur_x+dx[i];
            int next_y=cur_y+dy[i];
            if(next_x>=0&&next_x<n&&next_y>=0&&next_y<m){
                if(check[next_x][next_y]==0&&maps[next_x][next_y]==1){
                    q.push(make_pair(next_x,next_y));
                    check[next_x][next_y]=check[cur_x][cur_y]+1;
                }
            }
        }
    }
    answer= (check[n-1][m-1]>0) ? check[n-1][m-1] : -1;
    return answer;
}
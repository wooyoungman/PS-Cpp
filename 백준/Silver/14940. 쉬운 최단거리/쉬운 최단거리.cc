#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

int arr[1001][1001];
bool visited[1001][1001];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n,m;


void bfs(int x,int y)
{
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    arr[x][y]=0;
    while(!q.empty())
    {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        visited[cur_x][cur_y]=true;
        q.pop();
        for(int i=0;i<4;i++){
            int next_x=cur_x+dx[i];
            int next_y=cur_y+dy[i];
            if(next_x>=0&&next_x<n&&next_y>=0&&next_y<m&&
            visited[next_x][next_y]==false)
            {
                if(arr[next_x][next_y]!=0){
                    arr[next_x][next_y]=arr[cur_x][cur_y]+1;
                    q.push(make_pair(next_x,next_y));
                    visited[next_x][next_y]=true;
                }
            }
            
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int start_x,stary_y;

    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            if(arr[i][j]==2){
                start_x=i;
                stary_y=j;
            }
        }
    }
    bfs(start_x,stary_y);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==1&&visited[i][j]==false)
            {
                cout<<-1<<" ";
            }
            else
            {
                cout<< arr[i][j]<<" ";    
            }
            
        }
        cout<<"\n";
    }
    
    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

char arr[601][601];
bool visited[601][601];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n,m,cnt=0;


void bfs(int x,int y)
{
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
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
                if(arr[next_x][next_y]=='O'||arr[next_x][next_y]=='P'){
                    q.push(make_pair(next_x,next_y));
                    visited[next_x][next_y]=true;
                    if(arr[next_x][next_y]=='P'){
                        cnt++;
                    }
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
            if(arr[i][j]=='I'){
                start_x=i;
                stary_y=j;
            }
        }
    }
    bfs(start_x,stary_y);
    if(cnt==0){
        cout<<"TT";
    }
    else
    {
        cout<<cnt;
    }
    
    return 0;
}

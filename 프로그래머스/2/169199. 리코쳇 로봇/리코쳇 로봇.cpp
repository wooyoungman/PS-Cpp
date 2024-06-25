#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
#define MAX INT_MAX
using namespace std;

int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int sy,sx;
int row,col;
bool check;
vector<string>copy_board;
struct info{
    int y,x,cnt;
};
bool isValid(int y,int x){
    return y>=0&&x>=0&&y<row&&x<col&&copy_board[y][x]!='D';
}

// 4방향으로 이동 후 각 최종 지점을 큐에 담는다.
int bfs(){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(copy_board[i][j]=='R'){
                sy=i;
                sx=j;
            }
        }
    }
    int dis=MAX;
    queue<info>q;
    bool visited[101][101]={false,};
    visited[sy][sx]=true;
    q.push({sy,sx,0});
    while(!q.empty()){
        int y=q.front().y;
        int x=q.front().x;
        int cnt=q.front().cnt;
        q.pop();
        //cout<<y<<" "<<x<<" "<<cnt<<"\n";
        if(copy_board[y][x]=='G'){
            dis=min(dis,cnt);
        }
        for(int i=0;i<4;i++){
            int ny=y;
            int nx=x;
            while(isValid(ny+dy[i],nx+dx[i])){
                ny+=dy[i];
                nx+=dx[i];
            }
            //cout<<ny<<" "<<nx<<"\n";
            if((y!=ny||x!=nx)&&!visited[ny][nx]){
                q.push({ny,nx,cnt+1});
                visited[ny][nx]=true;
            }
        }
    }
    
    return dis;
}


int solution(vector<string> board) {
    int answer = 0;
    row=board.size();
    col=board[0].length();
    copy_board=board;
    answer = bfs();
    if(answer==MAX)return -1;
    return answer;
}
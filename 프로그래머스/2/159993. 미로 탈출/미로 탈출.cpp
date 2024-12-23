#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

bool take_lever;
bool can_exit;

int start_lever_dist;
int exit_dist;

int max_y;
int max_x;

int sy;
int sx;

int ly;
int lx;

int ey;
int ex;

int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};

char maze[101][101];

inline bool isValid(int y,int x){
    return y>=0&&x>=0&&y<=max_y&&x<=max_x&&maze[y][x]!='X';
}

struct Info{
    int y,x,d;
};

void findLever(){
    queue<Info>q;
    q.push({sy,sx,0});
    bool visited[101][101]={false,};
    
    while(!q.empty()){
        Info cur = q.front();
        q.pop();
        visited[cur.y][cur.x]=true;
        for(int i=0;i<4;i++){
            int ny=cur.y+dy[i];
            int nx=cur.x+dx[i];
            if(!isValid(ny,nx))continue;
            if(visited[ny][nx])continue;
            visited[ny][nx]=true;
            int nd=cur.d+1;
            q.push({ny,nx,nd});
            if(ny==ly&&nx==lx){
                take_lever=true;
                start_lever_dist=nd;
                return;
            }
        }
    }
    
}

void moveExit(){
    queue<Info>q;
    q.push({ly,lx,start_lever_dist});
    cout<<start_lever_dist;
    bool visited[101][101]={false,};
    
    while(!q.empty()){
        Info cur = q.front();
        q.pop();
        visited[cur.y][cur.x]=true;
        for(int i=0;i<4;i++){
            int ny=cur.y+dy[i];
            int nx=cur.x+dx[i];
            if(!isValid(ny,nx))continue;
            if(visited[ny][nx])continue;
            visited[ny][nx]=true;
            int nd=cur.d+1;
            q.push({ny,nx,nd});
            if(ny==ey&&nx==ex){
                can_exit=true;
                exit_dist=nd;
                return;
            }
        }
    }
}

void init(vector<string>&maps){
    max_y=maps.size()-1;
    max_x=maps[0].length()-1;
    for(int i=0;i<maps.size();i++){
        for(int j=0;j<maps[i].length();j++){
            if(maps[i][j]=='S'){
                sy=i;
                sx=j;
            }
            else if(maps[i][j]=='L'){
                ly=i;
                lx=j;
            }
            else if(maps[i][j]=='E'){
                ey=i;
                ex=j;
            }
            maze[i][j]=maps[i][j];
        }
    }
}

int solution(vector<string> maps) {
    int answer = 0;
    init(maps);
    findLever();
    if(!take_lever)return -1;
    else{
        moveExit();
        if(!can_exit)return -1;
        else return exit_dist;
    }
}
#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
// 250000
// 2가지 방법
// 1. 시추관의 위치에 따라 포함되는 좌표를 모두 BFS (비효율적)
// 2. nxm 좌표를 한번에 탐색할 수 있는 각 영역을 모두 구한 뒤 시추관의 위치에 따라 계산
// 2번 방법을 이용해서 각 구간에 번호를 매긴 후 번호 별 영역의 크기 저장후 이를 각 시추관에 따라 합을 구하기
using namespace std;

int land_number[501][501];
int land_size[501];
bool visited[501][501];

int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};

int row;
int col;

bool isValid(int y,int x, vector<vector<int>> &land){
    return y>=0&&x>=0&&y<row&&x<col&&
        land[y][x] == 1 && !visited[y][x];
}

void setNums(vector<vector<int>> &land){
    int cur_number=1;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            // 아직 방문하지 않은 석유가 있는 지역이면 bfs로 번호, 영역의 크기 구하기
            if(!visited[i][j]&&land[i][j]==1){
                queue<pair<int,int>>q;
                q.push({i,j});
                visited[i][j]=true;
                land_number[i][j]=cur_number;
                // 현재 영역의 크기
                int cur_size=1;
                while(!q.empty()){
                    int cur_y=q.front().first;
                    int cur_x=q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++){
                        int next_y=cur_y+dy[k];
                        int next_x=cur_x+dx[k];
                        // 석유가 없거나 이미 방문했거나 맵을 벗어나면 탐색 x
                        if(!isValid(next_y,next_x,land))continue;
                        visited[next_y][next_x]=true;
                        land_number[next_y][next_x]=cur_number;
                        q.push({next_y,next_x});
                        cur_size++;
                    }
                }
                // 현재 영역의 크기 저장
                land_size[cur_number]=cur_size;
                // 땅 번호 증가
                cur_number++;
            }
        }
    }
}

int calAnswer(){
    int answer=0;
    for(int i=0;i<col;i++){
        set<int>check;
        int sum=0;
        for(int j=0;j<row;j++){
            int cur_number=land_number[j][i];
            if(cur_number==0||check.count(cur_number)!=0)continue;
            check.insert(cur_number);
            sum+=land_size[cur_number];
        }
        answer=max(answer,sum);
    }
    return answer;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    row = land.size();
    col = land[0].size();
    setNums(land);
    answer = calAnswer();
    return answer;
}
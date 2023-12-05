#include <string>
#include <vector>
#include <iostream>

using namespace std;
int answer = -1;
int first_p;
int save[8][2];
bool check[8];
void dfs(int now_cnt, vector<vector<int>> dungeons){
    if(now_cnt==dungeons.size()){
        int p=first_p;
        for(int i=0;i<dungeons.size();i++){
            if(p<save[i][0]||p-save[i][1]<0){
                answer=max(answer,i);
                return;
            }
            p-=save[i][1];
        }
        answer=max(answer,now_cnt);
        now_cnt=0;
        return;
    }
    for(int i=0;i<dungeons.size();i++){
        if(!check[i]){
            save[now_cnt][0]=dungeons[i][0];
            save[now_cnt][1]=dungeons[i][1];
            check[i]=true;
            dfs(now_cnt+1,dungeons);
            check[i]=false;
            
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    first_p=k;
    dfs(0,dungeons);
    return answer;
}
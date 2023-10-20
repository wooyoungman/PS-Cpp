#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int x, int y, int n) {
    int answer = 0;
    vector<int> visit_cnt(1000001,0);
    queue<int>q;
    q.push(x);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        if(cur==y){
            return visit_cnt[cur];
        }
        int next[3]={cur+n,cur*2,cur*3};
        for(int i=0;i<3;i++){
            if(y<next[i]||visit_cnt[next[i]]!=0){
                continue;
            }
            visit_cnt[next[i]]=visit_cnt[cur]+1;
            q.push(next[i]);
        }
    }
    return -1;
}
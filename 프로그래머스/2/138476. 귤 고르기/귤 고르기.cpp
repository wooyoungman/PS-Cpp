#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// 1, 2,2 3,3, 4, 5,5
// 귤의 크기 종류가 서로 다르면서 최소인 경우는 
// 귤의 크기가 많은 것부터 담아버린다. 
// 개수가 많은것부터 담으면 된다.
int cnt[10000001];
struct Cmp{
    bool operator()(pair<int,int> a, pair<int,int>b){
        return a.second<b.second;
    }
};
int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int max_size=0;
    for(int i=0;i<tangerine.size();i++){
        cnt[tangerine[i]]++;
        if(max_size<tangerine[i]){
            max_size=tangerine[i];
        }
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,Cmp>pq;
    for(int i=1;i<=max_size;i++){
        pq.push({i,cnt[i]});
    }
    
    while(!pq.empty()){
        if(k<=pq.top().second){
            answer++;
            break;
        }
        else{
            k-=pq.top().second;
            answer++;
        }
        pq.pop();
        if(k<=0)break;
    }
    
    return answer;
}
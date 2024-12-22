#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Info{
    int idx,sum;
};

struct Cmp{
    bool operator()(Info a,Info b){
        return a.sum<b.sum;
    }    
};

// 각 광물 별 곡괭이 종류 저장
int kind_picks[11];

// 광물의 가중치를 계산한다. (5개씩)
// 각 가중치 별로 어떤 곡괭이를 사용할 지 선택한다.

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    int total_picks=0;
    for(int i=0;i<picks.size();i++){
        total_picks+=picks[i];
    }
    vector<int>sum_minerals;
    priority_queue<Info,vector<Info>,Cmp>sort_idx;
    for(int i=0;i<minerals.size();i++){
        int cnt=0;
        int sum=0;
        int s_idx=i;
        for(int j=s_idx;j<minerals.size();j++){
            //cout<<minerals[j]<<" ";
            if(minerals[j]=="diamond"){
                sum+=25;
            }
            else if(minerals[j]=="iron"){
                sum+=5;
            }
            else{
                sum+=1;
            }
            i=j;
            cnt++;
            if(cnt==5){
                break;
            }
        }
        sum_minerals.push_back(sum);
    }
    for(int i=0;i<sum_minerals.size();i++){
        sort_idx.push({i,sum_minerals[i]});
    }
    for(int i=0;i<picks.size();i++){
        for(int j=0;j<picks[i];j++){
            while(!sort_idx.empty()){
                if(total_picks<=sort_idx.top().idx){
                    sort_idx.pop();
                    continue;
                }
                else{
                    kind_picks[sort_idx.top().idx]=i+1;
                    sort_idx.pop();
                    break;
                }
            }
        } 
    }
    int idx=0;
    for(int i=0;i<total_picks;i++){
        for(int j=0;j<5;j++){
            if(kind_picks[i]==1){
                answer+=1;
            }
            else if(kind_picks[i]==2){
                if(minerals[idx]=="diamond"){
                    answer+=5;
                }
                else{
                    answer+=1;
                }
            }
            else if(kind_picks[i]==3){
                if(minerals[idx]=="diamond"){
                    answer+=25;
                }
                else if(minerals[idx]=="iron"){
                    answer+=5;
                }
                else{
                    answer+=1;
                }
            }
            idx++;
            if(idx==minerals.size())break;    
        }
    }
    return answer;
}
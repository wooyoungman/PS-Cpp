#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(pair<string,int>a,pair<string,int>b){
    return a.second>b.second;
}

bool cmp1(pair<string,pair<int,int>>a,pair<string,pair<int,int>>b){
    return a.second.second>b.second.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,int>m;
    // 장르, 고유번호, 재생 횟수 저장 벡터 m1
    vector<pair<string,pair<int,int>>>m1;
    // 맵에 장르별 총 재생 횟수 저장 후 벡터로 옮겨 재생 횟수 순으로 정렬
    for(int i=0;i<genres.size();i++){
        m[genres[i]]+=plays[i];
        m1.push_back(make_pair(genres[i],make_pair(i,plays[i])));
    }
    // 아래 줄들이 핵심!
    vector<pair<string,int>>order_genres(m.begin(),m.end());
    // order_genres에 현재 {pop, 3100}, {classic,1450} 순으로 저장 되어 있음 
    // m1에 현재 {pop,{4,2500}}, {classic,{3,800}}, {pop,{1,600}}, {classic,{0,500}}, {classic,{2,150}} 순으로 저장 되어 있음 
    sort(order_genres.begin(),order_genres.end(),cmp);
    sort(m1.begin(),m1.end(),cmp1);
    bool del_check[10001]={false,};
    for(int i=0;i<order_genres.size();i++){
        int cnt=0;
        bool check=false;
        while(1){
            for(int j=0;j<m1.size();j++){
                if(order_genres[i].first==m1[j].first&&!del_check[j]){
                    del_check[j]=true;
                    answer.push_back(m1[j].second.first);
                    //m1.erase(m1.begin()+j);
                    cnt++;
                    break;
                }
                // 다 돌았는데 2개가 아닌경우 
                if(cnt!=2&&(j==m1.size()-1)) check=true;
            }
            if(cnt==2||check) break;
        }
        
    }
    
    return answer;
}
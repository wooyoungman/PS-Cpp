#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char,int>m;
    for(int i=0;i<keymap.size();i++){
        for(int j=0;j<keymap[i].size();j++){
            // map에 현재 알파벳이 없으면 추가하기
            if(m.find(keymap[i][j])==m.end()){
                m.insert({keymap[i][j],j+1});
            }
            // map 현재 알파벳이 있으나 더 적은 횟수라면 수정하기
            else{
                if(m[keymap[i][j]]>j+1){
                    m[keymap[i][j]]=j+1;
                }
            }
        }
    }
    for(int i=0;i<targets.size();i++){
        int cnt=0;
        bool check=false;
        for(int j=0;j<targets[i].size();j++){
            if(m[targets[i][j]]==0){
                answer.push_back(-1);
                check=true;
                break;
            }
            else{
                cnt+=m[targets[i][j]];
            }
            
        }
        if(!check){
            answer.push_back(cnt);
        }
    }
    return answer;
}
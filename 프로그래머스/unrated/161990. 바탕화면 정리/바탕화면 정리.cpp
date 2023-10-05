#include <string>
#include <vector>

using namespace std;
// rdx, rdy를 정하는 기준은 #이 들어간 기호의 최대 인덱스 값으로 선정 
// lux, luy는 마찬가지로 #이 들어간 기호의 최소 인덱스 값으로 선정
// 그러면 둘을 먼저 구하자
vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int lux=0,luy=0,rdx=0,rdy=0;
    int min_x=0,min_y=0,max_x=0,max_y=0;
    int cnt=0;
    for(int i=0;i<wallpaper.size();i++){
        for(int j=0;j<wallpaper[i].size();j++){
            if(wallpaper[i][j]=='#'){
                if(cnt==0){
                    min_x=i;
                    min_y=j;
                    max_x=i+1;
                    max_y=j+1;
                }
                else{
                    if(min_x>i){
                        min_x=i;
                    }
                    if(min_y>j){
                        min_y=j;
                    }
                    if(max_x<i+1){
                        max_x=i+1;
                    }
                    if(max_y<j+1){
                        max_y=j+1;
                    }
                }
                cnt++;
            }
        
        }
    }
    answer.push_back(min_x);
    answer.push_back(min_y);
    answer.push_back(max_x);
    answer.push_back(max_y);
    return answer;
}
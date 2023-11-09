#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n-lost.size();
    vector<bool>check_lost(lost.size(),false);
    vector<bool>check_reserve(lost.size(),false);
    sort(lost.begin(),lost.end());
    sort(reserve.begin(),reserve.end());
    
    // lost[0]=2 -> reserve.find([lost[0]]+1 or lost[0]-1)이 참이면 지우기?  
    // 여벌을 가져온 사람이 도난당한 경우 다른 사람에게 빌려주지 않고 자신이 입는다. <이거 생각 못함>

    for(int i=0;i<reserve.size();i++){
        auto it=find(lost.begin(),lost.end(),reserve[i]);
        if(it!=lost.end()&&!check_lost[it-lost.begin()]&&!check_reserve[i]){
            check_lost[it-lost.begin()]=true;
            check_reserve[i]=true;
            answer++;
        }
    }
    
    for(int i=0;i<reserve.size();i++){
        auto front_it=find(lost.begin(),lost.end(),reserve[i]-1);
        auto back_it=find(lost.begin(),lost.end(),reserve[i]+1);
        if(front_it!=lost.end()&&!check_lost[front_it-lost.begin()]&&!check_reserve[i]){
            check_lost[front_it-lost.begin()]=true;
            check_reserve[i]=true;
            answer++;
        }
        else if(back_it!=lost.end()&&!check_lost[back_it-lost.begin()]&&!check_reserve[i]){
            check_lost[back_it-lost.begin()]=true;
            check_reserve[i]=true;
            answer++;
        }
    }
    
    return answer;
}
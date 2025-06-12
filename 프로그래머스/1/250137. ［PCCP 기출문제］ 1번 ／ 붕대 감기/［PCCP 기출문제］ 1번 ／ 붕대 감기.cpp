#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    // 필요한 변수
    // 1. 현재 경과된 시간
    // 2. 연속 성공 수
    // 3. 공격 최대 시간
    // 4. 현재 공격 순서
    // 5. 최대 hp
    
    int cur_time=0;
    int cur_success=0;
    int final_time=attacks[attacks.size()-1][0];
    int cur_attack_idx=0;
    int max_hp=health;
    cout<<final_time<<"\n";
    while(cur_time<final_time){
        cur_time++;
        
        // 공격 
        if(cur_attack_idx<attacks.size()&&attacks[cur_attack_idx][0]==cur_time){
            health-=attacks[cur_attack_idx++][1];
            cur_success=0;
        }
        
        else{
            
            health+=bandage[1];
            
            cur_success++;
            
            if(cur_success==bandage[0]){
                health+=bandage[2];
                cur_success=0;
            }
            
            if(health>max_hp)health=max_hp;
            
        }
        
        //cout<<"현재 시각 : "<<cur_time<<" "<<health<<"\n";
        
        // 현재 hp 확인
        if(health<=0){
            answer=-1;
            break;
        }
        else{
            answer=health;
        }
    }
      
    return answer;
}
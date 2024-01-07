#include <string>
#include <vector>
#include <queue>
using namespace std;

// 다리의 무게 때문에 트럭이 올라가지 못하는 경우 0을 추가하는 트릭을 사용한다.
// 마지막 트럭인 경우 다리의 길이만큼 시간을 추가하고 종료한다.


int solution(int bridge_length, int max_weight, vector<int> truck_weights) {
    int answer = 0;
    int weight_sum = 0;
    int cur_idx = 0;
    queue<int>cur_trucks;
    while(1){
        
        if(cur_idx==truck_weights.size()){
            answer+=bridge_length;
            break;
        }

        if(cur_trucks.size()==bridge_length){
            weight_sum-=cur_trucks.front();
            cur_trucks.pop();
        }
        
        int cur_truck_weight=truck_weights[cur_idx];
        
        if(weight_sum+cur_truck_weight<=max_weight){
            cur_trucks.push(truck_weights[cur_idx]);
            weight_sum+=cur_truck_weight;
            cur_idx++;
        }
        else{
            cur_trucks.push(0);
        }
        answer++;
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    // 1. 세로 길이 x, 가로 길이 y라고 하면 x*y = brown+yellow (넓이)
    int total=brown+yellow;
    
    // 2. x,y 쌍을 모두 찾기
    for(int i=1;i<=total/2;i++){
        if(total%i!=0)continue;
        
        // 2-1. 불가능한 쌍 제외하기
        int temp_x=i;
        int temp_y=total/temp_x;   
        if(temp_x<3) continue;
        
        // 3. 이 쌍을 통해 노란색 격자의 수 유추해서 확인하기
        int temp_brown=(2*temp_y)+2*(temp_x-2);
        if(temp_brown==brown){
            answer.push_back(temp_y);
            answer.push_back(temp_x);
            break;
        }
        
    }       
    return answer;
}
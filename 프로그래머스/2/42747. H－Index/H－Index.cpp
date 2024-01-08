#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>()); 

    int answer = 0;
    
    // 내림차순 정렬 후 인용 횟수와 현재 인덱스 값을 비교하며 
    // 최대인 경우를 구하기 (인용 횟수 >= 현재 인덱스 + 1)인 경우 반복문 진행
    // 현재 인덱스 + 1이 h번 이상 인용된 논문의 개수를 뜻함
    for(int i=0;i<citations.size();i++){
        if(citations[i]>=i+1){
            answer=i+1;
        }
        else{
            break;
        }
    }
    
    return answer;
}

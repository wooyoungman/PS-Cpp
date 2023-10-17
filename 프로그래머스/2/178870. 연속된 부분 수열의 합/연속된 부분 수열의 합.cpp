#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 시간 복잡도  O(N^2)라서 다시 생각하기로..
// 투포인터 알고리즘 활용하기로 함
// sum<k -> end + 1 하고, sum에 sequence[e]를 더함
// sum==k -> 두가지 경우로 나누어서 answer 갱신, sum에 sequence[s]를 빼고 start -1
vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2,0); // 0으로 초기화된 2개의 원소를 갖는 벡터
    int s=0,e=0;
    int sum=sequence[0];
    int sublen=sequence.size()+1;
    while(s<=e&&e<sequence.size()){
        if(sum<k){
            sum+=sequence[++e];
        }
        else if(sum==k){
            int len=e-s;
            // 부분 문자열의 길이가 더 짧은 경우 갱신
            if(sublen>len){
                sublen=len;
                answer[0]=s;
                answer[1]=e;
            }
            // 부분 문자열의 길이가 같으나 더 작은 시작 인덱스 값으로 갱신
            else if(sublen==len){
                if(answer[0]>s){
                    answer[0]=s;
                    answer[1]=e;
                }
            }
            sum-=sequence[s++];
        }
        else{
            
            sum-=sequence[s++];
        }
    }
    return answer;
}
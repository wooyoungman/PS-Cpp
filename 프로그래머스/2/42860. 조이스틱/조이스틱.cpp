#include <string>
#include <vector>

using namespace std;

// ABABAAAAABA 조이스틱이 움직이는 경우
// 0~n-1까지 탐색하는 i, A가 연속으로 나오는 지점의 끝을 end
// 1. 0 -> i -> 0 -> end (정방향 -> 역방향) : 2i + (총길이-end)
// 2. 0 -> end -> 0 -> i (역방향 -> 정방향) : 2*(총길이-end) + i
// A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z -> 26개 
// 한 문자 - 'A' 값이 0~13인 경우, 14~25인 경우 (A는 0에서 시작, Z는 1에서 시작)
int solution(string name) {
    int answer = 0;
    int n=name.length();
    int min_side=n-1;
    for(int i=0;i<n;i++){
        if(name[i]-'A'<14){
            answer+=name[i]-'A';
        }else{
            answer+='Z'-name[i]+1;
        }
        int end=i+1;
        while(end<n&&name[end]=='A'){
            end++;
        }
        min_side=min(min(2*i+n-end,2*(n-end)+i),min_side);
    }
    answer+=min_side;
    return answer;
}
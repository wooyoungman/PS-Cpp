#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int>s;
    for(int i=0;i<prices.size();i++){
        // 스택 top의 값이 현재 가격보다 크다면 (감소) -> 현재까지의 기록을 저장, pop 및 push
        while(!s.empty()&&prices[s.top()]>prices[i]){
            answer[s.top()]=i-s.top();
            s.pop();
        }
        s.push(i);
    }
    // 남은 스택은 모두 증가하는 부분이므로 스택 최상단의 인덱스 - 나머지 인덱스 
    int last=s.top();
    s.pop();
    while(!s.empty()){
        answer[s.top()]=last-s.top();
        s.pop();
    }
    return answer;
}
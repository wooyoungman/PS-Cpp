#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    // 기본 max_heap <int,vector<int>,less<int>>
    // 문제에서는 작은 값이 head로 와야하므로 min_heap
    priority_queue<int,vector<int>,greater<int>>pq;
    int answer = 0;
    for(auto p:scoville){
        pq.push(p);
    }
    while(pq.size()>=2){
        int head1=pq.top();
        if(head1<K){
            pq.pop();
            int head2=pq.top();
            pq.pop();
            int sum=head1+2*head2;
            pq.push(sum);
            answer++;
            if(pq.top()<K&&pq.size()==1){
                return -1;
            }
        }
        else{
            return answer;
        }
        
    }
}
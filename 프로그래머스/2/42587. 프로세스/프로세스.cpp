#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

// 가장 우선순위가 높은 프로세스를 찾을 때 까지 꺼내고 넣고를 반복한다.
// 1. 우선순위 큐에 우선순위가 높은 순서부터 프로세스를 push한다.
// 2. 제공된 priorities 벡터를 앞에서 부터 확인한다.
// 2-1. 우선순위 큐의 top에 있는 값이 나올 때 까지 priorities의 값을 찾는다.
// 2-2. 찾은 경우 우선순위 큐의 top을 pop, priorities의 찾기 직전 까지의 값을 모두 erase, push_back한다.
// 2-3. 처음 주어진 프로세스의 순서를 기억해야하므로 새로운 배열을 생성한다.
// 2-4. 큐를 pop, push할 때 프로세스 순서의 큐도 같이 erase, push_back 한다.
// 3. 우선순위 큐의 top을 pop한 경우 초기 자리의 인덱스에 실행된 순서를 새로운 배열에 저장한다.


int solution(vector<int> priorities, int location) {
    int run_rank=1;
    int save_time[101]={0,};    
    vector<int> first_idx;
    priority_queue<int>pq;
    for(int i=0;i<priorities.size();i++){
        pq.push(priorities[i]);
        first_idx.push_back(i);
    }
    
    while(!pq.empty()){
        int top_process=pq.top();
        pq.pop();

        int correct_idx;
        
        for(int i=0;i<priorities.size();i++){
            int cur_process=priorities[i];
            if(cur_process==top_process&&save_time[first_idx[i]]==0){
                save_time[first_idx[i]]=run_rank++;
                correct_idx=i;
                break;
            }
        }
        
        for(int i=0;i<correct_idx;i++){
            priorities.push_back(priorities[i]);
            first_idx.push_back(first_idx[i]);
        }
        priorities.erase(priorities.begin(),priorities.begin()+correct_idx+1);
        first_idx.erase(first_idx.begin(),first_idx.begin()+correct_idx+1);
    }
    
    return save_time[location];
}
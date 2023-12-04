#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0,sum=0;
    sort(people.begin(),people.end(),greater<int>());
    deque<int> dq(people.size());
    copy(people.begin(),people.end(),dq.begin());
    
    while(!dq.empty()){
        int heavy=dq.front();
        dq.pop_front();
        int light=dq.back();
        if(heavy+light<=limit){
            if(!dq.empty()){
                dq.pop_back();
            }
        }
        answer++;
    }

    return answer;
}


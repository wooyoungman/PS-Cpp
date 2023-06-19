#include <vector>
#include <iostream>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int cnt = nums.size()/2;
    set<int>s;
    for(int i=0;i<nums.size();i++){
        s.insert(nums[i]);
    }
    if(s.size()>cnt){
        answer=cnt;
    }
    else
    {
        answer=s.size();
    }
    return answer;
}
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int stopSize;
int tar;
int ans;
void dfs(vector<int>nums,int sum, int depth){
    //cout<<sum<<" "<<depth<<"\n";
    if(depth==stopSize){
        if(sum==tar)ans++;
        return;
    }
    dfs(nums,sum+nums[depth],depth+1);
    dfs(nums,sum-nums[depth],depth+1);
}

int solution(vector<int> numbers, int target) {
    stopSize=numbers.size();
    //cout<<stopSize<<"\n";
    tar=target;
    dfs(numbers,numbers[0],1);
    dfs(numbers,numbers[0]*(-1),1);
    return ans;
}
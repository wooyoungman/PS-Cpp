#include <vector>
#include <string>
#include <iostream>
#include <climits>
#define MAX INT_MAX
#define MIN INT_MIN

using namespace std;

// 구간 [s,e]에서 길이(len)만큼 나누었을 때의 합을 구한다. -> [s, s+len], [len+1, e]
// 길이만큼 나눈다는 뜻은, 연산의 순서를 어느 구간이 먼저 수행하냐는 뜻
// ex) [1,2] + [3,4]와 [1,3] + [4,4] 일 때,
// (1+2) + (3+4) 와 (1+2+3) + 4로 수식을 이해할 수 있다.
// 단, 여기서 '-'부호가 존재하기 때문에
// '-'의 경우 앞 범위는 최대로, 뒷 범위는 최소로 해야 [s,s+len] - [len+1,e]가 최대가 된다.

int max_dp[101][101];
int min_dp[101][101];

int solution(vector<string> arr)
{
    int answer = -1;
    int max_len=arr.size()/2+1;
    
    for(int i=0;i<max_len;i++){
        for(int j=0;j<max_len;j++){
            max_dp[i][j]=MIN;
            min_dp[i][j]=MAX;
        }
    }
    
    for(int len=1;len<=max_len;len++){
        for(int s=0;s<=max_len-len;s++){
            if(len==1){
                max_dp[s][s]=stoi(arr[s*2]);
                min_dp[s][s]=stoi(arr[s*2]);
            }
            else{
                int e=s+len-1;
                for(int mid=s;mid<e;mid++){
                    string opr=arr[mid*2+1];
                    if(opr=="+"){
                        max_dp[s][e]=max(max_dp[s][e],max_dp[s][mid]+max_dp[mid+1][e]);
                        min_dp[s][e]=min(min_dp[s][e],min_dp[s][mid]+min_dp[mid+1][e]);
                    }
                    else{
                        max_dp[s][e]=max(max_dp[s][e],max_dp[s][mid]-min_dp[mid+1][e]);
                        min_dp[s][e]=min(min_dp[s][e],min_dp[s][mid]-max_dp[mid+1][e]);
                    }
                }
            }
        }
    }
    answer=max_dp[0][max_len-1];
    return answer;
}
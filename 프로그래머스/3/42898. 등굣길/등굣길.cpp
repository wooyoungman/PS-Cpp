#include <string>
#include <vector>
#include <iostream>
using namespace std;

// (4,3) 이 집에 있음 

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int arr[101][101]={0,};
    int dp[101][101]={0,};
    for(int i=0;i<puddles.size();i++){
        arr[puddles[i][0]][puddles[i][1]]=-1;
    }
    for(int i=2;i<=m;i++){
        if(arr[i][1]!=-1){
            dp[i][1]=1;    
        }
        else{
            break;
        }
    }
    for(int i=2;i<=n;i++){
        if(arr[1][i]!=-1){
            dp[1][i]=1;    
        }
        else{
            break;
        }
    }
    for(int i=2;i<=m;i++){
        for(int j=2;j<=n;j++){
            if(arr[i][j]==-1)continue;
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%1000000007;
            //cout<<i<<" "<<j<<" "<<up_cnt<<" "<<right_cnt<<"\n";
        }
    }
    return dp[m][n];
}
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n=triangle.size();
    // Top-Bottom vs Bottom-Top -> 최종적으로 맨 위에 값이 하나만 존재하는 경우이므로 Bottom-Top이 효율적이라 판단
    // 삼각형 크기에 맞는 dp 벡터 생성
    vector<vector<int>>dp(n,vector<int>(n,0));
    
    // dp 맨 아래 층 값 초기화
    for(int i=0;i<n;i++){
        dp[n-1][i]=triangle[n-1][i];
    }
    
    // dp 시작
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<=i;j++){
            dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+triangle[i][j];
        }
    }
    
    // dp[0][0]에 정답 도출
    answer=dp[0][0];
    return answer;
}
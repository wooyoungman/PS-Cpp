#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer=0;
    
    // 선수별로 승패를 저장하기위한 bool형 2차원 배열 선언
    bool check[101][101]={false,};
    
    
    // results 벡터의 값을 이용하여 선수별 승패 결과 기록
    for(int i=0;i<results.size();i++){
        check[results[i][0]][results[i][1]]=true;
    }
    
    // 정확하게 순위를 매길 수 있는 선수를 구해야한다.
    // 문제 조건에서 A가 B보다 실력이 좋다면 A는 B를 항상 이긴다.
    // 그렇다면 A가 B를 이기고, B가 C를 이긴다면? -> A는 C도 이긴다.
    // 위 조건을 캐치해야 플로이드 와샬을 이용하여 문제를 해결할 수 있다.
    
    // 1번 선수를 B, 2번 선수를 A, 3번 선수를 C라고 하자.
    // A가 B를 이기고, B가 C를 이길 때 A는 C도 이긴다.
    // 가운데 선수를 기준으로 양 옆의 선수를 탐색해야한다.
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(check[j][i]&&check[i][k]) check[j][k]=true;
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=n;j++){
            // 승리 또는 패배가 n-1인 경우 확인 가능!
            if(check[i][j]) cnt++;
            if(check[j][i]) cnt++;
        }
        if(cnt==n-1)answer++;
    }
    
    return answer;
}
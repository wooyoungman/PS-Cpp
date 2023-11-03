#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int answer = 50; // 50개의 단어이므로 정답은 최대 50까지 가능하다.
bool visited[50];
bool check(string a,string b){
    int cnt=0;
    for(int i=0;i<a.length();i++){
        if(a[i]!=b[i]){
            cnt++;
        }
    }
    return (cnt==1)?true :false;
}

void dfs(string begin,string target, vector<string>words, int depth){
    // 현재 깊이가 (단계) answer보다 크면 탐색할 이유 x
    if(depth>=answer){
        return;
    }
    if(begin==target){
        answer=min(answer,depth);
        return;
    }
    for(int i=0;i<words.size();i++){
        // 문자 변형이 가능하고 방문 x면 탐색 하기
        if(check(begin,words[i])&&!visited[i]){
            // 먼저 방문 체크 후 탐색 마친 후 다시 false로
            visited[i]=true;
            dfs(words[i],target,words,depth+1);
            visited[i]=false;
        }
    }
}


int solution(string begin, string target, vector<string> words) {
    // hit -> hot -> dot -> dog -> cog, hit -> hot -> lot -> log -> cog
    // dfs, 백트래킹
    // 우선 현재 단어와 다음 단어가 1글자의 차이인지 확인하는 함수를 만들자
    // dfs 구현 시 target을 찾아도 뒤에 돌아가서 최솟값이 있는 경우가 있을 수 있으니 백트래킹도 같이 고려해야한다.
    dfs(begin,target,words,0);
    
    return (answer==50)?0:answer;
}
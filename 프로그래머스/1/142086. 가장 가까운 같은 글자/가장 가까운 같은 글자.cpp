#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<char,int>m;
    for(int i=0;i<s.length();i++){
        // 알파벳이 처음 나온 경우
        if(m.find(s[i])==m.end()){
            // 처음 나온 인덱스 값(위치)을 저장 및 정답 벡터에 -1 저장
            answer.push_back(-1);
            m[s[i]]=i;
        }
        // 알파벳이 이미 있는 경우
        else{
            // 현재 인덱스 값(위치)을 저장 및 정답 벡터에 기존 값과의 차를 저장
            answer.push_back(i-m[s[i]]);
            m[s[i]]=i;
        }
    }
    return answer;
}
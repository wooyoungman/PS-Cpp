#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    string alpha="abcdefghijklmnopqrstuvwxyz";
    for(int i=0;i<skip.size();i++){
        alpha.erase(find(alpha.begin(),alpha.end(),skip[i]));
    }
    for(int i=0;i<s.size();i++){
        int move=(alpha.find(s[i])+index)%alpha.length();
        answer+=alpha[move];
    }
    return answer;
}
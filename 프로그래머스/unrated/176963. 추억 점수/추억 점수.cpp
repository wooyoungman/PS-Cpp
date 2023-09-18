#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    unordered_map <string,int> m;
    for(int i=0;i<name.size();i++){
        m[name[i]]=yearning[i];
    }
    for(auto p:photo){
        int temp=0;
        for(auto p1:p){
            temp+=m[p1];
        }
        answer.push_back(temp);
    }
    return answer;
}
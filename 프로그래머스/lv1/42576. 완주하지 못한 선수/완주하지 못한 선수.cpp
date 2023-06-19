#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string,int>m;
    for(auto a:completion){
        m[a]++;
    }
    for(auto b:participant){
        m[b]--;
        if(m[b]<0){
            return b;
        }
    }
}
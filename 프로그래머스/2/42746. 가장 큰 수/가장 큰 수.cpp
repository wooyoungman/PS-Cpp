#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(int a,int b){
    string ab = to_string(a)+to_string(b);
    string ba = to_string(b)+to_string(a);
    return ab>ba;
}

string solution(vector<int> numbers) {
    bool check_all_zero=true;
    for(auto p:numbers){
        if(p!=0){
            check_all_zero=false;
            break;
        }
    }
    if(check_all_zero){
        return "0";
    }
    string answer = "";
    sort(numbers.begin(),numbers.end(),cmp);
    for(auto p:numbers){
        answer+=to_string(p);
    }
    return answer;
}
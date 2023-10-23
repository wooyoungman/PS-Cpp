#include <string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> a;
    for(auto p:s){
        if(p=='('){
            cout<<p;
            a.push(p);
        }
        else{
            if(a.empty()){
                answer=false;
                break;
            }
            else{
                a.pop();
            }
        }
    }
    if(!a.empty()){
        answer=false;
    }
    return answer;
}
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = 0;
    int x_cnt=0;
    int nx_cnt=0;
    char x=s[0];
    for(int i=0;i<s.length();i++){
        if(s[i]==x){
            x_cnt++;
        }
        else{
            nx_cnt++;
        }
        if(x_cnt==nx_cnt)
        {
            cout<<s[i]<<" ";
            x=s[i+1];
            answer++;
            x_cnt=0;
            nx_cnt=0;
        }
        if((x_cnt!=nx_cnt)&&i+1==s.length())
        {
            answer++;
        }
    }
    return answer;
}
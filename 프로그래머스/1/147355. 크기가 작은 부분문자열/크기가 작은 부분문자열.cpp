#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int p_len=p.length();
    unsigned long long val_t=0;
    unsigned long long val_p=stoull(p);
    for(unsigned long long i=0;i<t.length()-p_len+1;i++){
        val_t=stoull(t.substr(i,p_len));
        if(val_t<=val_p){
            answer++;
        }
    }
    return answer;
}
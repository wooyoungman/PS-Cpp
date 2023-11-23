#include <string>
#include <vector>
#include <iostream>
using namespace std;
string solution(string number, int k) {
    int cnt=0;
    int idx=0;
    while(cnt!=k){
        if(idx<number.length()-1&&number[idx]<number[idx+1]){
            number.erase(number.begin()+idx);
            cnt++;
            idx=max(0,idx-1);
        }
        else{
            idx++;
        }
        if(idx>number.length()-1){
            number.erase(number.length()-(k-cnt),k-cnt);
            break;
        }
    }
    return number;
}
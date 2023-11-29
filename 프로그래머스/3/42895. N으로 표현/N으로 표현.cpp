#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;



int solution(int N, int number) {
    unordered_set<int>s[9];
    int mul_num=N;
    // s[1]~s[8]에 N,NN,NNN...저장
    for(int i=1;i<=8;i++){
        s[i].insert(mul_num);
        mul_num*=10;
        mul_num+=N;
    }
    // s[2] = NN + s[1]?s[1]
    // s[3] = NNN + s[1]?s[2] + s[2]?s[1]
    // s[4] = NNNN + s[1]?s[3] + s[2]?s[2] + s[3]?s[1]
    for(int i=2;i<=8;i++){
        for(int j=1;j<i;j++){
            for(auto p1:s[j]){
                for(auto p2:s[i-j]){
                    s[i].insert(p1+p2);
                    s[i].insert(p1-p2);
                    s[i].insert(p1*p2);
                    if(p2!=0) s[i].insert(p1/p2);
                }
            }
        }
    }
    for(int i=1;i<=8;i++){
        if(s[i].find(number)!=s[i].end()){
            return i;
        }
    }
    return -1;
}
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;

// 소수? -> 1과 자기 자신을 제외한 약수가 존재하지 않는 자연수 
char temp_num[8];
set<int> all_numbers;
vector<bool> check;
int cur_length;
bool func(int num){
    // 0,1일 때는 확인 x 
    if(num<2){
        return false;
    }
    int n=2;
    while(n<num){
        if(num%n==0){
            return false;
        }
        n++;
    }
    // 자기자신 -1 까지 나누어 떨어지는 수가 없으면 소수 판단 -> true 반환 
    return true;
}

void permu(string numbers,int depth){
    if(depth==cur_length){
        if(temp_num[0]!='0'){
            all_numbers.insert(stoi(temp_num));
        }
        return;
    }
    for(int i=0;i<numbers.length();i++){
        if(!check[i]){
            check[i]=true;
            temp_num[depth]=numbers[i];
            permu(numbers, depth+1);
            check[i]=false;
        }
    }
}

// 1. 소수 판단 함수 만들기
// 2. numbers 문자열에서 만들 수 있는 모든 수 만들기 
// 2-1. 순열을 이용해서 만들 수 있는 수를 저장하기
int solution(string numbers) {
    int answer = 0;
    for(int i=0;i<numbers.length();i++){
        check.push_back(false);
    }
    for(int i=0;i<numbers.length();i++){
        cur_length++;
        permu(numbers, 0);
        for(int j=0;j<check.size();j++){
            check[j]=false;
        }
    }
    for(auto p:all_numbers){
        if(func(p))answer++;
    }
    return answer;
}
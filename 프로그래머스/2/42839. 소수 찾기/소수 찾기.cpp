#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

// 1. numbers의 길이가 n일 때, 길이가 1부터 n까지 모든 순열의 경우의 수 구하기
// 2. 첫번 째 자리가 0이 아닌 경우, set에 저장 (stoi)로 정수로 저장 (최대 7자리 -> int 가능)
// 3. set에 저장된 모든 값에 대해 약수의 개수 구하기 (1부터 자기자신까지 나누었을 때 나머지가 0인 경우가 2인 것만)

char temp_str[8];
set<int> all_nums;
bool check[8];
void permu(string numbers, int len, int depth){
    if(len==depth){
        if(temp_str[0]!='0'){
            all_nums.insert(stoi(temp_str));
        }
        return;
    }
    
    for(int i=0;i<numbers.length();i++){
        if(!check[i]){
            temp_str[depth]=numbers[i];
            check[i]=true;
            permu(numbers,len,depth+1);
            check[i]=false;
        }
    }
    
}

int countAns(){
    int ans=0;
    for(auto p:all_nums){
        int cnt=0;
        //cout<<p<<"\n";
        for(int i=1;i<=p;i++){
            if(p%i==0)cnt++;
        }
        if(cnt==2){
            ans++;
            //cout<<p<<" ";
        }
    }
    return ans;
}

int solution(string numbers) {
    int answer = 0;
    
    for(int i=1;i<=numbers.length();i++){
        permu(numbers,i,0);
    }
    
    return countAns();
}
#include <string>
#include <vector>
#include <iostream>
using namespace std;
// 퇴실 시간 기준 10분간 청소 후 다음 손님 이용 가능 
// 00:00 ~ 23:59 : 0분 ~ 1439분 + 청소시간 10분 -> 0분 ~ 1449분
int cnt[1450];
int ans;
void func(string s,string e){
    
    int sh=stoi(s.substr(0,2));
    int sm=stoi(s.substr(3,2));
    
    int smin=sh*60+sm;
    
    int eh=stoi(e.substr(0,2));
    int em=stoi(e.substr(3,2));
    
    int emin=eh*60+em+9;
    
    // 각 사용시간마다 +1씩
    // 누적합 문제
    for(int i=smin;i<=emin;i++){
        cnt[i]++;
        ans=max(ans,cnt[i]);
    }
    
}
int solution(vector<vector<string>> book_time) {
    
    for(int i=0;i<book_time.size();i++){
        func(book_time[i][0],book_time[i][1]);
    }
    return ans;
}
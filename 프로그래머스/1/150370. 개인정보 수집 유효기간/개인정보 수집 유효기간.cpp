#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    // yyyy.mm.dd로 today가 주어진다.
    // terms[i][0]은 약관 종류, terms[i][1]은 약관 기간

    // A~Z까지의 약관 종류를 0~26의 인덱스 값, 약관 기간을 저장함.
    int arr[26];
    for(int i=0;i<terms.size();i++){
        string term=terms[i].substr(2);
        arr[terms[i][0]-'A']=stoi(term);
    }
    for(int i=0;i<privacies.size();i++){
        // 우선, 개인 정보에 해당하는 약관 종류를 찾는다.
        // 해당 약관 종류에 해당하는 약관 기간을 찾는다.
        // 개인정보 수집일자에 찾은 약관 기간을 더한다.
        // today와 비교한다.
        char kind=privacies[i][11];
        int term=arr[kind-'A'];
        int today_year=stoi(today.substr(0,4));
        int today_month=stoi(today.substr(5,2));
        int today_day=stoi(today.substr(8,2));
        int year=stoi(privacies[i].substr(0,4));
        int month=stoi(privacies[i].substr(5,2));
        int day=stoi(privacies[i].substr(8,2));
        int sum_m=term+month;
        while(sum_m>12){
            sum_m-=12;
            year++;
        }
        month=sum_m;
        cout<<year<<" "<<month<<" "<<day<<" ";
        if(today_year>year){
            answer.push_back(i+1);
        }
        else if(today_year==year){
            if(today_month>month){
                answer.push_back(i+1);
            }
            else if(today_month==month){
                if(today_day>=day){
                    answer.push_back(i+1);
                }
            }
        }
    }
    return answer;
}
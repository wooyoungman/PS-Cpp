#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int no1[]={1,2,3,4,5};
    int no2[]={2,1,2,3,2,4,2,5};
    int no3[]={3,3,1,1,2,2,4,4,5,5};
    int cnt[3]={0,};
    for(int i=0;i<answers.size();i++){
        if(no1[i%5]==answers[i]){
            cnt[0]++;
        }
        if(no2[i%8]==answers[i]){
            cnt[1]++;
        }
        if(no3[i%10]==answers[i]){
            cnt[2]++;
        }
    }
    int max=0;
    for(int i=0;i<3;i++){
        if(max<cnt[i]){
            max=cnt[i];
        }
    }
    for(int i=0;i<3;i++){
        if(max==cnt[i]){
            answer.push_back(i+1);
        }
    }
    return answer;
}
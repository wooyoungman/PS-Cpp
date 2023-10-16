#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(vector<int> food) {
    string answer = "";
    string left_answer="";
    for(int i=1;i<food.size();i++){
        if(food[i]>=2){
            for(int j=0;j<food[i]/2;j++){
                left_answer+='0'+i;
            }
        }
    }
    answer+=left_answer;
    answer+='0';
    for(int i=left_answer.size()-1;i>=0;i--){
        answer+=left_answer[i];
    }
    return answer;
}
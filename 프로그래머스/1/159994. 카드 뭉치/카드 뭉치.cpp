#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer="Yes";
    int x_1=0,x_2=0;
    for(int i=0;i<goal.size();i++){
        if(goal[i]==cards1[x_1]){
            x_1++;
            continue;
        }
        else if(goal[i]==cards2[x_2]){
            x_2++;
            continue;
        }
        else{
            answer="No";
        }
    }

    return answer;
}
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int max_row=0,max_col=0;
    int answer_row=0,answer_col=0;
    for(int i=0;i<sizes.size();i++){
        max_row=max(max_row,sizes[i][0]);
        max_col=max(max_col,sizes[i][1]);
    }
    if(max_row>=max_col){
        for(int i=0;i<sizes.size();i++){
            if(sizes[i][0]!=max_row&&sizes[i][1]>sizes[i][0]){
                swap(sizes[i][0],sizes[i][1]);
            }
        }
    }
    else{
        for(int i=0;i<sizes.size();i++){
            if(sizes[i][1]!=max_col&&sizes[i][1]<sizes[i][0]){
                swap(sizes[i][0],sizes[i][1]);
            }
        }
    }
    for(int i=0;i<sizes.size();i++){
        cout<<sizes[i][0]<<" "<<sizes[i][1]<<"\n";
        answer_row=max(answer_row,sizes[i][0]);
        answer_col=max(answer_col,sizes[i][1]);
    }
    answer=answer_row*answer_col;
    
    return answer;
}
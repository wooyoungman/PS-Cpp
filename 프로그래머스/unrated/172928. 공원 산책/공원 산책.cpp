#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    pair<int,int>start_pos;
    for(int i=0;i<park.size();i++){
        for(int j=0;j<park[i].size();j++){
            if(park[i][j]=='S'){
                start_pos=make_pair(i,j);
            }
        }
    }
    
    for(int i=0;i<routes.size();i++){
        char op=routes[i][0];
        int dist=routes[i][2]-'0';
        int d_x=0,d_y=0;
        bool check=false;
        switch(op){
            case 'N':
                d_y=-1;
                break;
            case 'S':
                d_y=1;
                break;
            case 'W':
                d_x=-1;
                break;
            case 'E':
                d_x=1;
                break;
        }
        if(start_pos.first+d_y*dist<park.size()&&start_pos.first+d_y*dist>=0&&
           start_pos.second+d_x*dist<park[0].size()&&start_pos.second+d_x*dist>=0)
        {
            for(int j=1;j<=dist;j++){
                if(park[start_pos.first+d_y*j][start_pos.second+d_x*j]=='X'){
                    check=true;
                    break;
                }
            }
            if(!check){
                start_pos.first+=d_y*dist;
                start_pos.second+=d_x*dist;
            }
        }
    }
    answer.push_back(start_pos.first);
    answer.push_back(start_pos.second);
    return answer;
}
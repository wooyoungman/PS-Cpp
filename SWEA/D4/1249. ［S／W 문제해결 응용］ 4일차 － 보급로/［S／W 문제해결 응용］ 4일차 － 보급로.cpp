#include<iostream>
#include<queue>
using namespace std;

int arr[100][100];
int time_arr[100][100];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
queue<pair<int,int>>q;
void bfs(int size,int x,int y){
    while(!q.empty()){
        int cur_x=q.front().first;
        int cur_y=q.front().second;
    	q.pop();
        for(int i=0;i<4;i++){
        	int next_x=cur_x+dx[i];
            int next_y=cur_y+dy[i];
            if(next_x>=0&&next_y>=0&&next_x<size&&next_y<size){
            	int temp_sum=time_arr[cur_x][cur_y]+arr[next_x][next_y];
            	if(temp_sum<time_arr[next_x][next_y]){
                	time_arr[next_x][next_y]=temp_sum;
                    q.push(make_pair(next_x,next_y));
                }
            }
        }
    }
}


int main(int argc, char** argv)
{
	int test_case;
	int T,n;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin>>n;
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            for(int j=0;j<n;j++){
            	arr[i][j]=s[j]-'0';
                time_arr[i][j]=99999999;
            }
        }
        time_arr[0][0]=0;
       // bfs를 통해 arr 탐색과 각 지점 별 복구 시간 저장하기
        q.push(make_pair(0,0));
        bfs(n,0,0);
        cout<<"#"<<test_case<<" "<<time_arr[n-1][n-1]<<"\n";
	}
	return 0;
}
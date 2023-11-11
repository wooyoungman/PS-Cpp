#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
    
    for(int i=0;i<10;i++){
        int arr[1001][256]={0,};        
        int n,high,answer=0;
    	cin>>n;
        for(int j=0;j<n;j++){
            cin>>high;
            for(int k=0;k<high;k++){
                arr[j][k]=1;
            }
        }
        
        for(int j=2;j<n-2;j++){
            for(int k=0;k<255;k++){
                if(arr[j][k]==0) break;
                
                else if(arr[j][k]==1&&arr[j-1][k]==0&&arr[j-2][k]==0&&arr[j+1][k]==0&&arr[j+2][k]==0){
                	answer++;
                }
            }
        }
        cout<<"#"<<i+1<<" "<<answer<<"\n";
    }
    
	return 0;
}
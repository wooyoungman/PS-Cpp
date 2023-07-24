
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a,n,cnt=0;
    float sum=0,end=0,avr=0.15;
    vector<int> v;
    cin>>n;
    if(n==0){
        cout<<0;
        return 0;
    }
    
    int start= (int) round(avr*n);
    for(int i=0;i<n;i++){
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    for(int i=start;i<n-start;i++){
        cnt++;
        sum+=v[i];
    }
    end=sum/cnt;
    cout<<round(end);
    return 0;
}

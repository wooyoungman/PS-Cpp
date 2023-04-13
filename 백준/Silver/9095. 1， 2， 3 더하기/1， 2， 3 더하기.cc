#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[11];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,t;
	cin >> t;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	
	for (int i = 4; i <= 10; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}
	
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		cout << arr[n]<<"\n";
	}
	return 0;
}
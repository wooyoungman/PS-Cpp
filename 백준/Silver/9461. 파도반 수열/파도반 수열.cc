#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>
#include<map>
#include<string>
long long arr[101];

using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,num;
	cin >> n;
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	for (int i = 5; i <= 100; i++)
	{
		arr[i] = arr[i - 2] + arr[i - 3];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		cout << arr[num] << "\n";
	}
	return 0;
}

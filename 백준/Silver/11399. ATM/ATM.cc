#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001];
int main()
{
	int n,sum=0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			sum += arr[j];
		}
	}
	cout << sum;
}
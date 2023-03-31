#include<iostream>

using namespace std;


int arr[100];
int main()
{
	int n, m,sum=0,b_sum;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n-2; i++)
	{
		for (int j = i+1; j < n-1; j++)
		{
			for (int w = j+1; w < n; w++)
			{
				b_sum = 0;
				b_sum = arr[i] + arr[j] + arr[w];
				if ((sum < b_sum)&&(b_sum<=m))
				{
					sum = b_sum;
				}
			}
		}
	}
	cout << sum;
	return 0;
}
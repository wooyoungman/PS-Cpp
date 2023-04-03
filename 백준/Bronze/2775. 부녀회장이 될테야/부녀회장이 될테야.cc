#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int k, n, t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> k >> n;
		vector<int>arr[15];
		for (int j = 1; j < 15; j++)
		{
			arr[0].push_back(j);
		}
		for (int j = 1; j <= k; j++)
		{
			int sum = 0;
			for (int w = 0; w < n; w++)
			{
				sum += arr[j - 1][w];
				arr[j].push_back(sum);
			}
		}
		cout << arr[k][n - 1] << "\n";
	}
	return 0;
}
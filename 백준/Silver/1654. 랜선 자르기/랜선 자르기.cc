#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k, n,length,ans=0;
	vector<int>v;
	cin >> k >> n;
	for (int i = 0; i < k; i++)
	{
		cin >> length;
		v.push_back(length);
	}
	sort(v.begin(), v.end());
	unsigned int max_length = v[k-1];
	int left = 1;
	unsigned int right = max_length, sum_piece = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		sum_piece = 0;
		for (int i = 0; i < k; i++)
		{
			sum_piece += v[i] / mid;
		}
		if (sum_piece >= n)
		{
			left = mid + 1;
			if (ans < mid)
			{
				ans = mid;
			}
		}
		else
		{
			right = mid - 1;
		}
	}
	cout << ans;
	return 0;
}
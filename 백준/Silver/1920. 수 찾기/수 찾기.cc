#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

vector<int>v;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(),v.end());
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int left = 0, right = v.size()-1,mid;
		bool check = false;
		cin >> num;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (num == v[mid])
			{
				cout << 1<<"\n";
				check = true;
				break;
			}
			else if (num < v[mid])
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		if (check == false)
		{
			cout << 0<<"\n";
		}
		
	}
	return 0;
}

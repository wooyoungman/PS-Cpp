#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;
stack<int>s;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,num,sum=0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (num != 0)
		{
			s.push(num);
		}
		else
		{
			s.pop();
		}
	}
	while (!s.empty())
	{
		sum += s.top();
		s.pop();
	}
	cout << sum;
	return 0;
}

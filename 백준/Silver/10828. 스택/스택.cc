#include <iostream>
#include <stack>
#include <string>
using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,x,val;
	string s;
	stack<int>k;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (s == "push")
		{
			cin >> x;
			k.push(x);
		}
		else if (s == "pop")
		{
			if (k.empty() == true)
			{
				cout << -1<<"\n";
			}
			else
			{
				cout << k.top()<< "\n";
				k.pop();
			}
		}
		else if (s == "size")
		{
			cout << k.size()<< "\n";
		}
		else if (s == "empty")
		{
			if (k.empty() == true)
			{
				cout << 1<< "\n";
			}
			else
			{
				cout << 0<< "\n";
			}
		}
		else
		{
			if (k.empty() == true)
			{
				cout << -1<< "\n";
			}
			else
			{
				cout << k.top()<< "\n";
			}
		}
	}
	return 0;
}
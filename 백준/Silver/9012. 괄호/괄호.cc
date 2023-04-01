
#include <iostream>
#include <stack>

using namespace std;

int n;

bool vps(string _a)
{
	stack<char>s;
	for (int i = 0; i < _a.size(); i++)
	{
		if (_a[i] == '(')
		{
			s.push(_a[i]);
		}
		else
		{
			// 스택이 안비었다 -> ')'와 짝을 이루는'('가 있다
			if (!s.empty())
			{
				s.pop();
			}
			// 스택이 비었다 -> ')'와 짝을 이루는 '('가 없다
			else
			{
				return false;
			}
		}
	}
	if (!s.empty())
	{
		return false;
	}
	else
	{
		return true;
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string a;
		cin >> a;
		if (vps(a) == true)
		{
			cout << "YES"<<"\n";
		}
		else
		{
			cout << "NO"<<"\n";
		}
	}
	return 0;
}

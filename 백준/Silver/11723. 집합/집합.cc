#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, num,bit=0;
	string s;
	cin >> n;
	// 각 숫자에 해당하는 비트의 자리에 마스킹한다.
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (s == "add")
		{
			cin >> num;
			bit |= 1<<num;
		}
		else if (s == "check")
		{
			cin >> num;
			if (bit & (1 << num))
			{
				cout << 1 << "\n";
			}
			else
			{
				cout << 0 << "\n";
			}
		}
		else if (s == "remove")
		{
			cin >> num;
			bit &= ~(1 << num);
		}
		else if (s == "toggle")
		{
			cin >> num;
			if (bit & (1 << num))
			{
				bit &= ~(1 << num);
			}
			else
			{
				bit |= 1 << num;
			}
		}
		else if (s == "all")
		{
			for (int i = 1; i <= 20; i++)
			{
				bit |= 1 << i;
			}
		}
		else
		{
			bit &= 0;
		}
	}
	return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (1)
	{
		bool check = true;
		string s;
		char left, right;
		cin >> s;
		if (s == "0")
		{
			break;
		}
		if ((s.size() / 2) == 0)
		{
			for (int i = 0; i < (s.size() / 2); i++)
			{
				if (s[i] != s[s.size()-1-i])
				{
					check = false;
				}
			}
		}
		else
		{
			for (int i = 0; i < (s.size() / 2) + 1; i++)
			{
				if (s[i] != s[s.size() - 1 - i])
				{
					check = false;
				}
			}
		}
		if (check == false)
		{
			cout << "no";
		}
		else
		{
			cout << "yes";
		}
		cout << "\n";
	}
	return 0;
}

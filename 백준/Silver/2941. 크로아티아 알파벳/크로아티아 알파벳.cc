#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a;
	int t = 0;
	cin >> a;
	t = a.length();
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == 'c' && a[i + 1] == '=')
		{
			t = t - 1;
		}
		else if (a[i] == 'c' && a[i + 1] == '-')
		{
			t = t - 1;
		}
		else if (a[i] == 'd' && a[i + 1] == 'z'&&a[i+2]=='=')
		{
			t = t - 1;
		}
		else if (a[i] == 'd' && a[i + 1] == '-')
		{
			t = t - 1;
		}
		else if (a[i] == 'l' && a[i + 1] == 'j')
		{
			t = t - 1;
		}
		else if (a[i] == 'n' && a[i + 1] == 'j')
		{
			t = t - 1;
		}
		else if (a[i] == 's' && a[i + 1] == '=')
		{
			t = t - 1;
		}
		else if (a[i] == 'z' && a[i + 1] == '=')
		{
			t = t - 1;
		}
	}
	cout << t;
	return 0;
}
	
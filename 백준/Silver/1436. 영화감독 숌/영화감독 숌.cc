#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <vector>
using namespace std;



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,cnt=0;
	int val = 666;
	cin >> n;
	while (1)
	{
		string s = to_string(val);
		for (int i = 0; i < s.length() - 2; i++)
		{
			if (s[i] == '6' && s[i + 1] == '6' && s[i + 2] == '6')
			{
				cnt++;
				if (cnt == n)
				{
					cout << val;
					return 0;
				}
				break;
			}
		}
		val++;
	}
	return 0;
}
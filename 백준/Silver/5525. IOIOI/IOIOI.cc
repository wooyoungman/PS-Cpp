#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>
#include<map>
#include<string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m,cnt=0;
	string s, s1 = "I";
	cin >> n >> m >> s;
	for (int i = 0; i < n; i++)
	{
		s1.append("OI");
	}

	for (int i = 0; i < m; i++)
	{
		if (s[i] == 'I')
		{
			if (s.find(s1, i) != string::npos)
			{
				cnt++;
				i = s.find(s1, i);
			}
		}
	}
	cout << cnt;
	return 0;
}

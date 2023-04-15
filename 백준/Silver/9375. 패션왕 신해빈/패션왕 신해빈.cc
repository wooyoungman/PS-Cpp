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
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int cnt_arr[31] = { 0, };
		int cnt = 1;
		string s1, s2;
		map<string, int>m;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> s1 >> s2;
			if (m.find(s2) == m.end())
			{
				m.insert(make_pair(s2, 1));
			}
			else
			{
				// 이미 있는 카테고리인 경우 value값 ++
				m[s2]++;
			}
		}
		for (auto p : m)
		{
			cnt *= (p.second + 1);
		}
		cout << cnt - 1 << "\n";
		
	}
	return 0;
}

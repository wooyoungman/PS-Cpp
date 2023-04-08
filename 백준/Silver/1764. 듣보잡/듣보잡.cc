#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
map<string,string >p;
vector<string>v;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m,cnt=0;
	string _s;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> _s;
		p.insert(make_pair(_s, _s));
	}
	for (int i = 0; i < m; i++)
	{
		cin >> _s;
		if (p.find(_s) != p.end())
		{
			v.push_back(_s);
			cnt++;
		}
	}
	cout << cnt << "\n";
	sort(v.begin(), v.end());
	for (auto p : v)
	{
		cout << p << "\n";
	}
	return 0;
}

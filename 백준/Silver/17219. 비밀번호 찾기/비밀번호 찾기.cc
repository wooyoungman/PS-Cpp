#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>
#include<map>
#include<string>

using namespace std;

map<string, string>site;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	string s1, s2;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s1 >> s2;
		site.insert(make_pair(s1, s2));
	}
	for (int i = 0; i < m; i++)
	{
		cin >> s1;
		cout<<site.find(s1)->second<<"\n";
	}
	return 0;
}

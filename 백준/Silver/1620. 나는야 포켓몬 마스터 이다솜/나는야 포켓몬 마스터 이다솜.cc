#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
map<string, string>dogam_s;
map<string, string>dogam_n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	string s;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		dogam_s.insert(make_pair(s,to_string(i+1)));
		dogam_n.insert(make_pair(to_string(i+1),s));
	}
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		if (dogam_s.find(s) != dogam_s.end())
		{
			cout << dogam_s.find(s)->second<<"\n";
		}
		else
		{
			cout << dogam_n.find(s)->second<<"\n";
		}
	}
	return 0;
}

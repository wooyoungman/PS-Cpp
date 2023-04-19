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
	int n, m,cnt=0,len=0,temp=0;
	string s, s1 = "I";
	cin >> n >> m >> s;
	for (int i = 0; i < n; i++)
	{
		s1.append("OI");
	}

	while (s.find(s1, len) != string::npos)
	{
		len = s.find(s1, len)+1;
		cnt++;
	}
	cout << cnt;
	return 0;
}

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<map>
#include<queue>
using namespace std;

vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> q;
int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int s, e;
		cin >> s >> e;
		v.push_back({ s, e });
	}
	sort(v.begin(), v.end());
	q.push(v[0].second);
	int m = 1;
	for (int i = 1; i < n; i++)
	{
		while (!q.empty() && q.top() <= v[i].first)
			q.pop();
		q.push(v[i].second);
		m = max(m, (int)q.size());

	}
	cout << m;
}
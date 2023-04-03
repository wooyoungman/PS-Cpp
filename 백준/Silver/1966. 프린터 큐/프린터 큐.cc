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
	int t, n, m, num;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n >> m;
		int cnt = 0;
		priority_queue<int>pq;
		queue<pair<int, int>>q;
		for (int j = 0; j < n; j++)
		{
			cin >> num;
			pq.push(num);
			q.push(make_pair(j, num));
		}
		while (!q.empty())
		{
			int idx = q.front().first;
			int val = q.front().second;
			q.pop();
			if (pq.top() == val)
			{
				pq.pop();
				cnt++;
				if (idx == m)
				{
					cout << cnt << "\n";
					break;
				}
			}
			// 내가 찾는 수가 아니면 다시 큐로 삽입
			else
			{
				q.push(make_pair(idx, val));
			}
		}
	}
	
	return 0;
}
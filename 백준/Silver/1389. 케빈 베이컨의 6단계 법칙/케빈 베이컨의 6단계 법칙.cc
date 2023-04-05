#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int n, m,a,b,cnt=0;
int arr[101][101];
int visited[101];
int _min = 99999999;

// 1에서 n번까지 가는데 얼마나 걸리는지
// visited에 한번에 가면 1씩 한 번 더 돌면 +1 해서 
// 총 걸리는 시간을 visited 배열에 저장한다

void init()
{
	for (int i = 1; i <= n; i++)
	{
		visited[i] = 0;
	}
}

void bfs(int start)
{
	queue<int>q;
	visited[start] = 1;
	q.push(start);
	while (!q.empty())
	{
		int loc = q.front();
		q.pop();
		for (int i = 1; i <= n; i++)
		{
			if (arr[loc][i] == 1 && visited[i] == 0)
			{
				visited[i] = visited[loc] + 1;
				q.push(i);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int ans;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		init();
		bfs(i);
		int sum = 0;
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
			{
				continue;
			}
			else
			{
				sum += (visited[j] - 1);
			}
		}
		if (sum < _min)
		{
			_min = sum;
			ans = i;
		}
	}
	cout << ans;
	return 0;
}
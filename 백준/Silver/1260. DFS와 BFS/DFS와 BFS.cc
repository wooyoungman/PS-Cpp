#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m, v;
int arr[1001][1001];
bool visited[1001];
queue<int>q;

void dfs(int v)
{
	visited[v] = true;
	cout << v << " ";
	for (int i = 1; i <= n; i++)
	{
		if (arr[v][i] == 1 && visited[i] == false)
		{
			dfs(i);
		}
	}
}

void bfs(int v)
{
	q.push(v);
	visited[v] = true;
	cout << v << " ";

	while (!q.empty())
	{
		v = q.front();
		q.pop();
		for (int i = 1; i <= n; i++)
		{
			if (arr[v][i] == 1 && visited[i] == false)
			{
				q.push(i);
				visited[i] = true;
				cout << i << " ";
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	dfs(v);
	cout << "\n";
	memset(visited, 0, sizeof(visited));
	bfs(v);
	return 0;
}
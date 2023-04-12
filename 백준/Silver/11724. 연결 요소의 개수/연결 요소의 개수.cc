#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[1001][1001];
bool visited[1001];
int n, m, x, y;
bool check = false;
int cnt = 0;
void dfs(int x)
{
	visited[x] = true;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i]&&arr[x][i]==1)
		{
			dfs(i);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			cnt++;
			dfs(i);
		}

	}
	cout << cnt;
	return 0;
}
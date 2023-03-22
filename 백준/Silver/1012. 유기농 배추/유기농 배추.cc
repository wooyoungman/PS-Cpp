#include <iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
bool arr[50][50];
bool visited[50][50];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int t, m, n, k, x, y;
bool dfs(int y, int x)
{
	if (visited[y][x])
	{
		return false;
	}
	visited[y][x] = true;
	int temp_x, temp_y;
	for (int i = 0; i < 4; i++)
	{
		temp_x = x + dx[i];
		temp_y = y + dy[i];
		if (temp_x >= 0 &&temp_x < m && temp_y >= 0 && temp_y < n && arr[y][x] == 1)
		{
			dfs(temp_y, temp_x);
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int cnt = 0;
		memset(arr, 0, sizeof(arr));
		memset(visited, 0, sizeof(visited));
		cin >> m >> n >> k;
		for (int j = 0; j < k; j++)
		{
			cin >> x>>y;
			arr[y][x] = 1;
		}
		for (int j = 0; j < n; j++)
		{
			for (int l = 0; l < m; l++)
			{
				if (arr[j][l] == true && visited[j][l] == false)
				{
					if (dfs(j, l) == true)
					{
						cnt++;
					}
				}
			}
		}
		cout << cnt<<"\n";
	}
	return 0;
}
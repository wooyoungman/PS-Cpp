#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>
#include<map>
#include<string>

using namespace std;

int n,m;
int arr[500][500];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool visited[500][500];
int ans;

bool isin(int x, int y)
{
	if (x < 0 || x >= n || y < 0 || y >= m) {
		return false;
	}
	return true;
}

void reset()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			visited[i][j] = false;
		}
	}
}

void dfs(int x, int y, int d, int sum)
{
	if (d == 3)
	{
		ans = max(ans, sum);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int cur_x = x + dx[i];
		int cur_y = y + dy[i];
		if (!isin(cur_x, cur_y))
		{
			continue;
		}
		if (visited[cur_x][cur_y])
		{
			continue;
		}
		visited[cur_x][cur_y] = true;
		dfs(cur_x, cur_y, d+1, sum + arr[cur_x][cur_y]);
		visited[cur_x][cur_y] = false;
	}
}

// ㅗ모양은 dfs로 탐색이 불가능하여 별도로 탐색, (ㅗ, ㅏ, ㅜ, ㅓ) 4가지 만들어주기
void s1(int x, int y)
{
	int sum = 0;
	sum = arr[x][y] + arr[x - 1][y] + arr[x][y - 1] + arr[x][y + 1];
	ans = max(ans, sum);
}

void s2(int x, int y)
{
	int sum = 0;
	sum = arr[x][y] + arr[x - 1][y] + arr[x][y + 1] + arr[x + 1][y];
	ans = max(ans, sum);
}

void s3(int x, int y)
{
	int sum = 0;
	sum = arr[x][y] + arr[x][y - 1] + arr[x][y + 1] + arr[x + 1][y];
	ans = max(ans, sum);
}

void s4(int x, int y)
{
	int sum = 0;
	sum = arr[x][y] + arr[x][y - 1] + arr[x - 1][y] + arr[x + 1][y];
	ans = max(ans, sum);
}



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			visited[i][j] = true;
			dfs(i, j, 0, arr[i][j]);
			visited[i][j] = false;
			if (i - 1 >= 0 && j - 1 >= 0 && j + 1 < m)
			{
				s1(i, j);
			}
			if (i - 1 >= 0 && i + 1 < n && j + 1 < m)
			{
				s2(i, j);
			}
			if (i + 1 < n && j -1 >= 0 && j + 1 < m)
			{
				s3(i, j);
			}
			if (i - 1 >= 0 && i + 1 < n && j - 1 >= 0)
			{
				s4(i, j);
			}
		}
	}
	cout << ans;

	return 0;
}

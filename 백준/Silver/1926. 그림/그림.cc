#include<iostream>
#include<queue>

using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int arr[501][501];
int cnt = 0, max_area = 0,max_cnt=0;
bool visited[501][501];
int n, m;
void bfs(int x, int y)
{
	queue<pair<int, int>>q;
	q.push(make_pair(x, y));
	cnt = 0;
	while (!q.empty())
	{
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		visited[x][y] = true;
		q.pop();
		cnt++;
		for (int i = 0; i < 4; i++)
		{
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];
			if (next_x >= 0 && next_y >= 0 && next_x < n && next_y < m && arr[next_x][next_y]
				== 1&&visited[next_x][next_y]==0)
			{
				q.push(make_pair(next_x, next_y));
				visited[next_x][next_y] = 1;
			}
		}
	}
	max_area = max(max_area, cnt);
}

int main()
{
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
			if (visited[i][j] == 0 && arr[i][j] == 1)
			{
				bfs(i, j);
				max_cnt++;
			}
		}
	}
	cout << max_cnt << "\n" << max_area;
	return 0;
}
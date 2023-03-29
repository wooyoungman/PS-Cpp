#include<iostream>
#include<queue>

using namespace std;

int map[1001][1001];
int visit_day[1001][1001] = { 0, };
bool visited[1001][1001];
int m, n, day = -1;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
queue<pair<int, int>>q;
void bfs()
{
	while (!q.empty())
	{
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];
			if (next_x >= 0 && next_y >= 0 && next_x < n && next_y < m && visited[next_x][next_y] == false)
			{
				if (map[next_x][next_y] ==0&&visit_day[next_x][next_y]==0)
				{
					visit_day[next_x][next_y] = visit_day[cur_x][cur_y] + 1;
					q.push(make_pair(next_x,next_y));
					visited[next_x][next_y] = true;
				}
			}
		}
	}
}

int main()
{
	int flag = 0;
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 0)
			{
				flag = 1;
			}
			else if (map[i][j] == 1)
			{
				q.push(make_pair(i, j));
				visited[i][j] = true;
			}
		}
	}
	if (flag == 0)
	{
		cout << 0;
		return 0;
	}
	bfs();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)

		{
			if (map[i][j] == 0&&visit_day[i][j]==0)
			{
				cout << -1;
				return 0;
			}
			if (visit_day[i][j] > day)
			{
				day = visit_day[i][j];
			}
		}
	}
	cout << day;
	return 0;
}
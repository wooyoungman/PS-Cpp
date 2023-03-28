#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
char map[101][101];
bool visited[101][101];
int n,cnt_R=0,cnt_G=0,cnt_B=0,cnt_RG=0,cnt_RGB=0;

void bfs_R(int x, int y)
{
	queue<pair<int,int>>q;
	q.push(make_pair(x, y));
	while (!q.empty())
	{
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		visited[cur_x][cur_y] = true;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];
			if (next_x >= 0 && next_y >= 0 && next_x < n && next_y < n && visited[next_x][next_y] == false)
			{
				if (map[next_x][next_y] == 'R')
				{
					q.push(make_pair(next_x, next_y));
					visited[next_x][next_y] = true;
				}
			}
		}
	}
}
void bfs_G(int x, int y)
{
	queue<pair<int, int>>q;
	q.push(make_pair(x, y));
	while (!q.empty())
	{
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		visited[cur_x][cur_y] = true;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];
			if (next_x >= 0 && next_y >= 0 && next_x < n && next_y < n && visited[next_x][next_y] == false)
			{
				if (map[next_x][next_y] == 'G')
				{
					q.push(make_pair(next_x, next_y));
					visited[next_x][next_y] = true;
				}
			}
		}
	}
}

void bfs_B(int x, int y)
{
	queue<pair<int, int>>q;
	q.push(make_pair(x, y));
	while (!q.empty())
	{
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		visited[cur_x][cur_y] = true;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];
			if (next_x >= 0 && next_y >= 0 && next_x < n && next_y < n && visited[next_x][next_y] == false)
			{
				if (map[next_x][next_y] == 'B')
				{
					q.push(make_pair(next_x, next_y));
					visited[next_x][next_y] = true;
				}
			}
		}
	}
}

void bfs_RG(int x, int y)
{
	queue<pair<int, int>>q;
	q.push(make_pair(x, y));
	while (!q.empty())
	{
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		visited[cur_x][cur_y] = true;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];
			if (next_x >= 0 && next_y >= 0 && next_x < n && next_y < n && visited[next_x][next_y] == false)
			{
				if (map[next_x][next_y] == 'G'||map[next_x][next_y]=='R')
				{
					q.push(make_pair(next_x, next_y));
					visited[next_x][next_y] = true;
				}
			}
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j] == false&&map[i][j]=='R')
			{
				bfs_R(i, j);
				cnt_R++;
			}
			else if (visited[i][j] == false && map[i][j] == 'G')
			{
				bfs_G(i, j);
				cnt_G++;
			}
			else if (visited[i][j] == false && map[i][j] == 'B')
			{
				bfs_B(i, j);
				cnt_B++;
			}
		}
	}
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j] == false && (map[i][j] == 'R'||map[i][j]=='G'))
			{
				bfs_RG(i, j);
				cnt_RG++;
			}
			else if (visited[i][j] == false && map[i][j] == 'B')
			{
				bfs_B(i, j);
				cnt_RGB++;
			}
		}
	}
	cout << cnt_R+cnt_G+cnt_B<<"\n"<<cnt_RG+cnt_RGB;
	return 0;
}
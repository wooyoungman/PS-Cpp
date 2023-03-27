#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int dx[8] = { -1,0,1,-1,1,-1,0,1 };
int dy[8] = { 1,1,1,0,0,-1,-1,-1};
int map[51][51];
bool visited[51][51];
int w, h,cnt=0;

void bfs(int x, int y)
{
	queue<pair<int, int>>q;
	q.push(make_pair(x, y));
	while (!q.empty())
	{
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		visited[cur_x][cur_y] = true;
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];
			if (next_x >= 0 && next_y >= 0 && next_x < w && next_y < h && visited[next_x][next_y] == false && map[next_x][next_y] == 1)
			{
				q.push(make_pair(next_x, next_y));
				visited[next_x][next_y] = true;
			}
		}
	}
}

int main()
{
	while (1)
	{
		cin >> w >> h;
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
		if (w == 0 && h == 0)
		{
			break;
		}
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[j][i];
			}
		}
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (map[j][i] == 1 && visited[j][i] == false)
				{
					bfs(j, i);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
		cnt = 0;
	}
	return 0;
}
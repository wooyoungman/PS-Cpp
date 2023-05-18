#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>
#include<map>
#include<string>
#include <string.h>
using namespace std;

int n;
int arr[101][101];
int safe[101][101];
bool visited[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = {0, 0, 1, -1};
int cnt = 0;
vector<int>v;
queue<pair<int, int>>q;


void reset()
{
	memset(visited, 0, sizeof(visited));
	memset(safe, 0, sizeof(safe));
	cnt = 0;
}

void bfs(int x,int y)
{
	visited[x][y] = true;
	q.push(make_pair(x, y));
	while (!q.empty())
	{
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];
			if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n && safe[next_x][next_y]&&!visited[next_x][next_y])
			{
				q.push(make_pair(next_x, next_y));
				visited[next_x][next_y] = true;
			}
		}
	}
}




int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int maxhigh = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (maxhigh < arr[i][j])
			{
				maxhigh = arr[i][j];
			}
		}
	}

	for (int h = 1; h <= maxhigh; h++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (arr[i][j] < h)
				{
					safe[i][j] = 0;
				}
				else
				{
					safe[i][j] = 1;
				}
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (safe[i][j] && !visited[i][j])
				{
					bfs(i, j);
					cnt++;
				}
			}
		}
		v.push_back(cnt);
		reset();


	}
	sort(v.begin(), v.end());
	cout << v[v.size()-1];
	return 0;
}

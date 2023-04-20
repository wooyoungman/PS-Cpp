#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>
#include<map>
#include<string>

using namespace std;
int m, n, h;
int arr[101][101][101];
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
bool visited[101][101][101];
int days[101][101][101];
int day = -1;
queue<tuple<int, int, int>>q;
// 처음으로 토마토가 있는 위치를 넣고 시작하기
void bfs(int x, int y,int z)
{

	while (!q.empty())
	{
		int cur_x = get<0>(q.front());
		int cur_y = get<1>(q.front());
		int cur_z = get<2>(q.front());
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];
			int next_z = cur_z + dz[i];
			if (next_x >= 0 && next_y >= 0 && next_z >= 0 && next_x < n && next_y < m && next_z < h
				&& !visited[next_x][next_y][next_z] && arr[next_x][next_y][next_z] !=-1&&arr[cur_x][cur_y][cur_z]==1)
			{
				visited[next_x][next_y][next_z] = true;
				if (arr[next_x][next_y][next_z] == 0)
				{
					arr[next_x][next_y][next_z] = 1;
					days[next_x][next_y][next_z] = days[cur_x][cur_y][cur_z] + 1;
					if (days[next_x][next_y][next_z] > day)
					{
						day = days[next_x][next_y][next_z];
					}
				}
				q.push(make_tuple(next_x, next_y, next_z));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> m >> n >> h;
	bool flag = true;
	int s_x, s_y, s_z;
	for (int k = 0; k < h; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 0)
				{
					flag = false;
				}
				else if(arr[i][j][k]==1)
				{
					q.push(make_tuple(i, j, k));
				}
			}
		}
	}
	if (flag)
	{
		cout << 0;
		return 0;
	}
	else
	{
		bfs(get<0>(q.front()), get<1>(q.front()), get<2>(q.front()));
		for (int k = 0; k < h; k++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{

					if (visited[i][j][k] == false && arr[i][j][k] == 0)
					{
						cout << -1;
						return 0;
					}

				}
			}
		}
		cout << day;
	}
	return 0;
}

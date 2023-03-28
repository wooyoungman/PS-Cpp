#include<iostream>
#include<cstring>
#include<queue>

using namespace std;


// bfs 함수는 하나로 구현한다. (인접해 있는 경우에만 큐에 넣는 방법)
// 그리고 main 함수에서 for문을 이용하여 탐색할 때
// 적록색약인 경우와 아닌경우를 나누어 R=G를 처리하여 탐색한다.
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
bool visited[101][101];
char map[101][101];
int cnt = 0,n;
void bfs(int x, int y)
{
	queue<pair<int, int>>q;
	q.push(make_pair(x, y));
	visited[x][y] = true;
	while (!q.empty())
	{
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];
			if (next_x >= 0 && next_y >= 0 && next_x < n && next_y < n && visited[next_x][next_y] == false && map[cur_x][cur_y] == map[next_x][next_y])
			{
				q.push(make_pair(next_x, next_y));
				visited[next_x][next_y] = true;
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
			if (visited[i][j] == false)
			{
				bfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << "\n";
	cnt = 0;
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j]=='R')
			{
				map[i][j] = 'G';
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j] == false)
			{
				bfs(i, j);
				cnt++;
			}
		}
	}
	cout <<cnt;
	return 0;
}
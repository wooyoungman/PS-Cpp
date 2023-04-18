#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>
#include<map>
#include<string>
// DFS로 풀려다가 실패하고... 
// 다시 생각해보니 BFS로 방문 하는 노드들의 
// 방문 순서를 배열에 저장해준다면 
// 이는 곧 그 노드까지의 최단 거리가 된다는 생각이..?
using namespace std;
int arr[101][101];
int cnt[101][101];
int n, m, f = 1;
bool visited[101][101];
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };
queue<pair<int, int>>q;
void bfs(int x, int y)
{
	visited[x][y] = true;
	q.push(make_pair(x, y));
	cnt[1][1] = 1;
	while (!q.empty())
	{
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];
			if (next_x >= 1 && next_y >= 1 && next_x <= n && next_y <= m && !visited[next_x][next_y] &&
				arr[next_x][next_y] == 1)
			{
				visited[next_x][next_y] = true;
				q.push(make_pair(next_x, next_y));
				cnt[next_x][next_y] = cnt[cur_x][cur_y] + 1;
			}
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	string s;
	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		for (int j = 1; j <= m; j++)
		{
			arr[i][j] = s[j - 1] - '0';
		}
	}
	bfs(1, 1);
	cout << cnt[n][m];
	return 0;
}

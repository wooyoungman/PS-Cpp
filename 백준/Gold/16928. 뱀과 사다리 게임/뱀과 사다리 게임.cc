#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>
#include<map>
#include<string>

using namespace std;

int n, m, x, y, u, v;
// cross는 뱀, 사다리가 있는 경우를 넣는 배열
// arr는 각 칸별로 굴린 주사위 횟수
int cross[101];
int arr[101];
bool visited[101];
queue<pair<int, int>>q;
void bfs()
{
	while (!q.empty())
	{
		int cur_x = q.front().first;
		int cnt = q.front().second;
		arr[cur_x] = cnt;
		visited[cur_x] = true;
		if (cur_x == 100)
		{
			return;
		}
		q.pop();
		// 사다리나 뱀이 있는 경우 무조건 가야하므로
		for (int i = 1; i <= 6; i++)
		{
			if (cur_x + i >= 1 && cur_x + i <= 100 && !visited[cur_x + i])
			{
				if (cross[cur_x + i] != 0)
				{
					q.push(make_pair(cross[cur_x + i], cnt + 1));
					visited[cross[cur_x + i]] = true;
				}
				else
				{
					q.push(make_pair(cur_x + i, cnt + 1));
					visited[cur_x + i] = true;
				}
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
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		cross[x] = y;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		cross[u] = v;
	}
	q.push(make_pair(1, 0));
	bfs();
	cout << arr[100];
	return 0;
}

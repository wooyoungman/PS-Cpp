#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
int arr[101][101];
int visited[101];
int cnt = 0;
int n, num;
void dfs(int a)
{
	cnt++;
	visited[a] = 1;
	for (int i = 1; i <= num; i++)
	{
		if (arr[a][i] == 1 && visited[i] == 0)
		{
			dfs(i);
		}
	}
}
//queue<int>q;
//void bfs(int a)
//{
//	visited[a] = true;
//	q.push(a);
//	while (!q.empty())
//	{
//		int v = q.front();
//		q.pop();
//		for (int i = 1; i <= num; i++)
//		{
//			if (visited[v] == 0 && arr[v][i] == 1)
//			{
//				q.push(i);
//				visited[i] = true;
//				cnt++;
//			}
//		}
//	}
//}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int x, y;
	cin >> num >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		arr[x][y] = arr[y][x] = 1;
	}
	dfs(1);
	cout << cnt-1;
	return 0;
}

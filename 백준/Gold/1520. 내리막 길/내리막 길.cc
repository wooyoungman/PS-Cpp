#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#define INF 987654321
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int N, M;
int map[501][501];
int visit[501][501];
stack<pair<int, int>> q;

int cnt;

int state = 0;
int dcnt;
int dfs(int y,int x)
{
	
	
	int temp;
	if (y == N - 1 && x == M - 1)
	{
		return 1;
	}

	for (int i = 0; i < 4; i++)
	{
		int ny = dy[i] + y;
		int nx = dx[i] + x;


		if (nx<0 || ny<0 || nx>M - 1 || ny>N - 1) continue;

		if (map[ny][nx] >= map[y][x]) continue;

		if (visit[ny][nx] == -1) continue;

		if (visit[ny][nx] > 0)
		{
			visit[y][x] += visit[ny][nx];
			continue;
		}

		temp=dfs(ny, nx);

		if (temp != -1)
		{
			visit[y][x] = visit[y][x] + temp;
		}


	}

	if (visit[y][x] > 0)
	{
		return visit[y][x];
	}
	else
	{
		visit[y][x] = -1;
		return -1;
	}

}



int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	int temp;
	if (N == 1 && M == 1)
	{
		cout << 1;
	}
	else
	{
		temp=dfs(0, 0);
		if (temp == -1)
		{
			cout << 0;
		}
		else
		{
			cout << visit[0][0];
		}
	}

	/*
	cout << endl;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%d ", visit[i][j]);
		}
		printf("\n");
	}*/
}






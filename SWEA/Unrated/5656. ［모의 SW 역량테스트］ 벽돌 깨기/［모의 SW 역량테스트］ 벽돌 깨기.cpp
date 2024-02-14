#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#define INF 987654321
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int N, W,H;
int answer;
int map[15][12];

int minn = 21e8;

struct poctane {
	int y;
	int x;
	int pow;

};


queue<poctane> q;

stack<int> qq;
void boom(int y,int x)
{
	q.push({ y,x,map[y][x]});
	map[y][x] = 0;

	while (!q.empty())
	{
		y = q.front().y;
		x = q.front().x;
		int power = q.front().pow;
		q.pop();

		
		for (int i = 0; i < 4; i++)
		{
			for (int j = 1; j <= power - 1; j++)
			{
				int ny = y + dy[i]*j;
				int nx = x + dx[i]*j;

				if (ny<0 || nx<0 || ny>H - 1 || nx>W - 1) break;

				if (map[ny][nx] == 0) continue;

				if (map[ny][nx] == 1)
				{
					map[ny][nx] = 0;
					continue;
				}
				
				q.push({ ny,nx,map[ny][nx]});
				map[ny][nx] = 0;

			}
		}
	}

	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j < H; j++)
		{
			if (map[j][i] != 0) qq.push(map[j][i]);
			map[j][i] = 0;
		}
		int temp = H-1;
		while (!qq.empty())
		{

			map[temp][i] = qq.top();
			qq.pop();
			temp--;
		}

	}




}

void check()
{

	int cnt = 0;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (map[i][j] != 0)
			{
				cnt++;
			}
		}
	}
	/*
	printf("\n");
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}*/

	minn = min(cnt, minn);


}


void func(int dep)
{
	int temp[15][12] = { 0, };
	if (dep == N)
	{
		check();
		return;
	}

	copy(&map[0][0], &map[0][0] + 180, &temp[0][0]);

	for (int i = 0; i < W; i++)
	{
		int state = 0;
		for (int j = 0; j < H; j++)
		{
			
			if (map[j][i] != 0)
			{
				boom(j,i);
				state = 1;
				break;
			}
		}
		if (state == 0) continue;
		func(dep + 1);
		copy(&temp[0][0], &temp[0][0] + 180, &map[0][0]);

	}

}


int main()
{
	//freopen("sample_input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int k = 1; k <= T; k++)
	{
		minn = 21e8;
		
		cin >> N >> W >> H;
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}


		func(0);
		if (minn == 21e8)
		{
			minn = 0;
		}
		printf("#%d %d\n", k, minn);
	}
}




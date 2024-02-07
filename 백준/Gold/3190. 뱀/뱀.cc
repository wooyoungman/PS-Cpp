#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#define INF 987654321
using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int map[100][100];

deque<pair<int, int>> snake;

int N, K, L;
int main()
{
	cin >> N;
	cin >> K;
	int a, b;
	char c;
	for (int i = 0; i < K; i++)
	{
		scanf("%d %d", &a, &b);
		map[a-1][b-1] = 1;
	}


	cin >> L;
	snake.push_front({ 0,0 });
	int state = 1;
	int seconds = 0;
	map[0][0] = 2;
	int dir = 1;
	int x = 0;
	int y = 0;

	for (int i = 0; i < L; i++)
	{
		scanf("%d %c", &a, &c);
		while(seconds<a)
		{
			
			int ny = snake.front().first + dy[dir];
			int nx = snake.front().second +dx[dir];
			//cout << ny << " " << nx << " " << dir<<endl;
			if (ny<0 || nx<0 || ny>N - 1 || nx>N - 1||map[ny][nx]==2)
			{
				state = 0;
				break;
			}
			
			if (map[ny][nx] == 1)
			{
				snake.push_front({ny,nx });
				
			}
			else
			{
				map[snake.back().first][snake.back().second] = 0;
				snake.push_front({ ny,nx });
				snake.pop_back();
				
			}
			map[ny][nx] = 2;
			/*
			for (int k = 0; k < N; k++)
			{
				for (int l = 0; l < N; l++)
				{
					printf("%d ", map[k][l]);
				}
				printf("\n");
			}*/

			y = ny;
			x = nx;
			seconds++;

		}
		if (c == 'L')
		{
			//cout<<"good";
			dir = (dir + 1) % 4;
		}
		else
		{
			dir = (dir - 1);
			if (dir < 0) dir=dir + 4;
		}
		
		if (state == 0)break;
	}
	if (state == 1)
	{
		while (1)
		{

			int ny = snake.front().first + dy[dir];
			int nx = snake.front().second + dx[dir];
			//cout << ny << " " << nx << " " << dir << endl;
			if (ny<0 || nx<0 || ny>N - 1 || nx>N - 1 || map[ny][nx] == 2)
			{
				state = 0;
				break;
			}

			if (map[ny][nx] == 1)
			{
				snake.push_front({ ny,nx });

			}
			else
			{
				map[snake.back().first][snake.back().second] = 0;
				snake.push_front({ ny,nx });
				snake.pop_back();

			}
			map[ny][nx] = 2;
			/*
			for (int k = 0; k < N; k++)
			{
				for (int l = 0; l < N; l++)
				{
					printf("%d ", map[k][l]);
				}
				printf("\n");
			}
			*/
			y = ny;
			x = nx;
			seconds++;

		}
		
	}


	cout << seconds+1;
}







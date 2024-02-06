#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#define INF 987654321
using namespace std;

int N, M;
vector<string> str;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int suc = 0;
int state = 0;
int minn = 987654321;
void func(int dep,int ry,int rx, int by,int bx)
{

	int ry1 = ry;
	int rx1 = rx;
	int by1 = by;
	int bx1 = bx;
	
	if (dep == 10)
	{
		state = -1;
		return;
	}
	//printf("%d %d %d %d\n", ry, rx, by, bx);
	

	for (int i = 0; i < 4; i++)
	{
		int fail = 0;
		//int suc = 0;
		ry = ry1;
		rx = rx1;
		by = by1;
		bx = bx1;
		int ny;
		int nx;
		int bluesec=0;
		int redsec=0;
		while (1)  //파란 구슬
		{
			ny = by + dy[i];
			nx = bx + dx[i];
			if (str[ny][nx] == '#')
			{
				break;
			}
			if (str[ny][nx] == 'O')
			{
				fail = 1;
				break;
			}
			
			by = ny;
			bx = nx;
			bluesec++;

		}
		if (fail == 1) continue;
		while (1)  //빨강 구슬
		{
			ny = ry + dy[i];
			nx = rx + dx[i];
			if (str[ny][nx] == '#')
			{
				break;
			}

			if (str[ny][nx] == 'O')
			{
				//cout << "good" << endl;
				suc = 1;
				minn = min(minn, dep+1);
				return;
				
				
			}

			ry = ny;
			rx = nx;
			redsec++;
		}

		if (ry == by && rx == bx) //겹쳐지면
		{
			if (bluesec > redsec)
			{
				by = by + dy[(i + 2) % 4];
				bx = bx + dx[(i + 2) % 4];
			}
			else 
			{
				ry = ry + dy[(i + 2) % 4];
				rx = rx + dx[(i + 2) % 4];
			}
		}
		func(dep + 1, ry, rx, by, bx);

	}
}

int main()
{
	string temp;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		str.push_back(temp);
	}
	int ry, rx;
	int by, bx;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (str[i][j] == 'R')
			{
				ry = i;
				rx = j;
				str[i][j] = '.';
			}

			if (str[i][j] == 'B')
			{
				by = i;
				bx = j;
				str[i][j] = '.';
			}
		}
	}
	func(0, ry, rx, by, bx);
	if (suc == 0) cout << -1;
	else cout << minn;
}







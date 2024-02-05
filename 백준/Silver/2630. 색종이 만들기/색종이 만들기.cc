#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int arr[128][128];
int blue = 0;
int white = 0;
void func(int sy,int sx, int ey, int ex)
{
	//int state = -1;
	int cnt = 0;
	//printf("%d %d %d %d\n", sy, sx, ey, ex);
	for (int i = sy; i < ey; i++)
	{
		for (int j = sx; j < ex; j++)
		{
			cnt = cnt + arr[i][j];
		}
	}
	if (cnt == (ey-sy) * (ex-sx))
	{
		blue++;
		return;
	}
	else if (cnt == 0)
	{
		white++;
		return;
	}
	//4개로 divide

	func(sy, sx, (ey+sy) /2, (ex+sx) / 2);

	func((sy+ey)/2, sx, ey, (ex + sx) /2);

	func(sy, (ex + sx) /2, (sy + ey) /2 , ex );

	func((sy + ey) /2, (ex + sx) /2, ey, ex);


}


int main() 
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	func(0, 0, N, N);
	cout << white << endl << blue;



}







#include <iostream>
using namespace std;



int land[500][500];

// 채우기, 제거하기, 인벤토리블럭수
// 높이 0~256까지 모든 경우의 수 판단 -> 브루트 포스 
// 최소시간을 매번 갱신해야함
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, b;
	int min_time = 0x7fffffff;
	int max_height = -1;
	cin >> n >> m >> b;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> land[i][j];
		}
	}
	for (int h = 0; h <= 256; h++)
	{
		// 쌓아야하는 블록 개수
		int create = 0;
		// 지워야하는 블록 개수
		int remove = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				// 쌓아야하는 블록 개수 추가
				if (land[i][j] - h < 0)
				{
					create -= (land[i][j] - h);
				}
				// 제거해야하는 블록 개수 추가
				else
				{
					remove += (land[i][j] - h);
				}
			}
		}
		// 보유한 블록 수 + 제거해야하는 블록 수 >= 쌓아야하는 블록 수
		// 인 경우에 땅고르기가 가능하므로 최소 시간 갱신
		if (b + remove >= create)
		{
			int time = 2 * remove + create;
			if (min_time >= time)
			{
				min_time = time;
				max_height = h;
			}
		}
	}
	cout << min_time << ' ' << max_height;
	return 0;
}
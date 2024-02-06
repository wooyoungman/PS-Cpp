#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#define INF 987654321
using namespace std;


int N;
int map[20][20];

int maxx = 0;


void func(int dep)
{
	int temp[20][20] = {0,};
	if (dep == 5)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				maxx = max(maxx, map[i][j]);
			}
			
		}
		return;
	}
	copy(&map[0][0], &map[0][0] + 400, &temp[0][0]);
	
	for (int i = 0; i < N; i++) // 왼쪽으로 붙이기
	{
		int first=-1;
		int second = -1;
		for (int j = 0;  j < N;  j++) //첫번째 합칠거 찾기
		{

			if (map[i][j] != 0 && first != -1 && second == -1)
			{
				second = j;
			}

			if (map[i][j] != 0 && first == -1)
			{
				first = j;
			}

			if (second != -1 && first != -1)
			{
				
				if (map[i][first] == map[i][second])
				{
					int tep= map[i][first] * 2;
					map[i][first] = 0;
					map[i][second] = 0;
					for (int k = 0; k <= second; k++) //0위치 찾기
					{
						if (map[i][k] == 0)
						{
							map[i][k] = tep;
							
							first = -1;
							second = -1;
							
							break;
						}		
					}
				}
				else
				{
					for (int k = 0; k <= first; k++) //0위치 찾기
					{
						if (map[i][k] == 0)
						{							
							map[i][k] = map[i][first];
							map[i][first] = 0;							
							break;
						}
					}
					first = second;
					second = -1;
				}
			}	
		}
		
		if (first != -1 && second == -1)
		{
			//cout << i;
			for (int k = 0; k <= first; k++) //0위치 찾기
			{
				if (map[i][k] == 0)
				{
					map[i][k] = map[i][first];
					map[i][first] = 0;
					break;
				}
			}
		}
	}
	/*
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}*/
	

	func(dep + 1);
	copy(&temp[0][0], &temp[0][0] + 400, &map[0][0]); 
	
	for (int i = 0; i < N; i++) // 위로 붙이기
	{
		int first = -1;
		int second = -1;
		for (int j = 0; j < N; j++) //첫번째 합칠거 찾기
		{

			if (map[j][i] != 0 && first != -1 && second == -1)
			{
				second = j;
			}

			if (map[j][i] != 0 && first == -1)
			{
				first = j;
			}

			if (second != -1 && first != -1)
			{

				if (map[first][i] == map[second][i])
				{
					int tep = map[first][i] * 2;
					map[first][i] = 0;
					map[second][i] = 0;
					for (int k = 0; k <= second; k++) //0위치 찾기
					{
						if (map[k][i] == 0)
						{
							map[k][i] = tep;

							first = -1;
							second = -1;

							break;
						}
					}
				}
				else
				{
					for (int k = 0; k <= first; k++) //0위치 찾기
					{
						if (map[k][i] == 0)
						{
							map[k][i] = map[first][i];
							map[first][i] = 0;
							break;
						}
					}
					first = second;
					second = -1;
				}
			}
		}
		if (first != -1 && second == -1)
		{
			//cout << i;
			for (int k = 0; k <= first; k++) //0위치 찾기
			{
				if (map[k][i] == 0)
				{
					map[k][i] = map[first][i];
					map[first][i] = 0;
					break;
				}
			}
		}
	}

	

	func(dep + 1);
	copy(&temp[0][0], &temp[0][0] + 400, &map[0][0]);

	

	for (int i = 0; i < N; i++) // 오른쪽으로 붙이기
	{
		int first=-1;
		int second = -1;
		for (int j = N-1;  j >= 0;  j--) //첫번째 합칠거 찾기
		{

			if (map[i][j] != 0 && first != -1 && second == -1)
			{
				second = j;
			}

			if (map[i][j] != 0 && first == -1)
			{
				first = j;
			}

			if (second != -1 && first != -1)
			{

				if (map[i][first] == map[i][second])
				{
					int tep= map[i][first] * 2;
					map[i][first] = 0;
					map[i][second] = 0;
					for (int k = N-1; k >= second-1; k--) //0위치 찾기
					{
						if (map[i][k] == 0)
						{
							map[i][k] = tep;

							first = -1;
							second = -1;

							break;
						}
					}
				}

				else
				{
					for (int k = N-1; k >= first; k--) //0위치 찾기
					{
						if (map[i][k] == 0)
						{
							map[i][k] = map[i][first];
							map[i][first] = 0;
							break;
						}
					}
					first = second;
					second = -1;
				}
			}
		}
		if (first != -1 && second == -1)
		{
			//cout << i;
			for (int k =N-1; k >= first; k--) //0위치 찾기
			{
				if (map[i][k] == 0)
				{
					map[i][k] = map[i][first];
					map[i][first] = 0;
					break;
				}
			}
		}
	}

	

	func(dep + 1);
	copy(&temp[0][0], &temp[0][0] + 400, &map[0][0]); 
	
	
	for (int i = 0; i < N; i++) // 아래로 붙이기
	{
		int first = -1;
		int second = -1;
		for (int j = N-1; j >= 0; j--) //첫번째 합칠거 찾기
		{

			if (map[j][i] != 0 && first != -1 && second == -1)
			{
				second = j;
			}

			if (map[j][i] != 0 && first == -1)
			{
				first = j;
			}

			if (second != -1 && first != -1)
			{

				if (map[first][i] == map[second][i])
				{
					int tep = map[first][i] * 2;
					map[first][i] = 0;
					map[second][i] = 0;
					for (int k = N-1; k >= second; k--) //0위치 찾기
					{
						if (map[k][i] == 0)
						{
							map[k][i] = tep;

							first = -1;
							second = -1;

							break;
						}
					}
				}
				else
				{
					for (int k = N-1; k >= first; k--) //0위치 찾기
					{
						if (map[k][i] == 0)
						{
							map[k][i] = map[first][i];
							map[first][i] = 0;
							break;
						}
					}
					first = second;
					second = -1;
				}
			}
		}
		if (first != -1 && second == -1)
		{
			//cout << i;
			for (int k = N-1; k >= first; k--) //0위치 찾기
			{
				if (map[k][i] == 0)
				{
					map[k][i] = map[first][i];
					map[first][i] = 0;
					break;
				}
			}
		}
	}


	func(dep + 1);
	

}


int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	
	func(0);
	cout << maxx;
}







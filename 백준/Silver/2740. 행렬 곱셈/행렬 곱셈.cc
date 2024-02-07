#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#define INF 987654321
using namespace std;

int A[100][100];
int B[100][100];
int C[100][100];
int main()
{
	int N, M, K;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}
	

	cin >> M >> K;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < K; j++)
		{
			scanf("%d", &B[i][j]);
		}
	}

	


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			int temp;
			for (int k = 0; k < M; k++)
			{
				C[i][j]= C[i][j]+A[i][k] * B[k][j];
			}

		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{

			printf("%d ", C[i][j]);
		}
		printf("\n");
	}



}







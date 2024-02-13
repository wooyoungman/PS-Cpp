#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#define INF 987654321
using namespace std;

int tree[1000000];

int N, M;
int answer;
void func(int start,int end)
{
	if (start > end)
	{
		return;
	}

	int mid = (start + end) / 2;

	long long sum = 0;
	long long sum2 = 0;
	for (int i = 0; i < N; i++)
	{
		if (tree[i] > mid)
		{
			sum = sum + tree[i] - mid;
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (tree[i] > mid+1)
		{
			sum2 = sum2 + tree[i] - mid-1;
		}
	}

	if (sum >= M && sum2 < M)
	{
		answer = mid;
		return;
	}
	else if (sum>M )
	{
		func(mid + 1, end);
	}
	else
	{
		func(start, mid-1);
	}




}


int main()
{
	cin >> N >> M;
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &tree[i]);
	}
	func(1, 1000000000);
	cout << answer;

}




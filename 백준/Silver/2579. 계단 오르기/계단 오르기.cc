#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>
#include<map>
#include<string>
//1 -> 1
//2 -> 1, 2
//3 -> 1, 3 | 2, 3
//4 -> 1, 2, 4 | 1, 3, 4 |
//5 -> 1, 2, 4, 5 | 1, 2, 3, 5
//->dp[n - 2] + arr[n] or dp[n - 3] + arr[n - 1] + arr[n]

int stair[301];
long long score[301];

using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,num;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> stair[i];
		if (i == 1)
		{
			score[i] = stair[1];
		}
		else if (i == 2)
		{
			score[i] = stair[1] + stair[2];
		}
		else if (i == 3)
		{
			score[i] = max(stair[1] + stair[3], stair[2] + stair[3]);
		}
	}
	if (n >= 4)
	{
		for (int i = 4; i <= n; i++)
		{
			score[i] = max(score[i - 2] + stair[i], score[i - 3] + stair[i - 1] + stair[i]);
		}
	}
	cout << score[n];
	return 0;
}

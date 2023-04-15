#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>
#include<map>
#include<string>

using namespace std;
int dp[50001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,temp;
	cin >> n;
	for (int i = 1; i*i <=n; i++)
	{
		// 제곱수는 개수가 1개
		dp[i * i] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j*j <= i; j++)
		{
			if (!dp[i])
			{
				dp[i] = dp[j * j] + dp[i - j * j];
			}
			else
			{
				dp[i] = min(dp[i], dp[j * j] + dp[i - j * j]);
			}
		}
	}
	cout << dp[n];
	return 0;
}

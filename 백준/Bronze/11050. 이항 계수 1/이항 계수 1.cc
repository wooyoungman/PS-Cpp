#include <iostream>


using namespace std;
int dp[100][100];
int main()
{
	int n, k;
	cin >> n >> k;
	// nCk = n-1Ck + n-1Ck-1 임을 DP로 구현해보자
	for (int i = 1; i<=n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			if (i == j || j == 0)
			{
				dp[i][j] = 1;
			}
			else
			{
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
			}
		}
	}
	cout << dp[n][k];
	return 0;
}
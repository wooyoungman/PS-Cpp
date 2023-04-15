#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>
#include<map>
#include<string>

using namespace std;
int dp[1001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// 이 문제는 5번째 항까지 직접 구한 후 규칙을 찾아냈다.
	// 짝수 번째는 + 2 홀수 번째는 +1 (앞선 모든 항의 합) 이다.
	int n,sum;
	cin >> n;
	dp[1] = 1;
	dp[2] = 3;
	sum = dp[1] + dp[2];
	if (n <= 2)
	{
		cout << dp[n];
	}
	else
	{
		for (int i = 3; i <= n; i++)
		{
			if (i % 2 == 0)
			{
				dp[i] = (sum + 2) % 10007;
			}
			else
			{
				dp[i] = (sum + 1) % 10007;
			}
			sum += (dp[i]%10007);
			sum %= 10007;

		}
		cout << dp[n];
	}
	return 0;
}

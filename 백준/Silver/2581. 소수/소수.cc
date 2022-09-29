#include <iostream>
using namespace std;
int main()
{
	int n, m;
	int min_num=0;
	int sum = 0;
	int cnt = 0;
	// 소수란 약수가 자기 자신과 1인 수
	// 그렇다면 2,3,5,7,11,13,... 등등등이 있다.
	// 2부터 입력받은 수 n-1까지 나누었을 때 나누어지는 수가 없다면 소수로 판별한다.
	cin >> m >> n;
	if (n == 1)
	{
		cout << -1;
		return 0;
	}
	else if (n == 2)
	{
		cout << n <<"\n"<< n;
		return 0;
	}
	for (int i = m; i <= n; i++)
	{
		if (i == 2)
		{
			sum += 2;
			min_num = 2;
		}
		else
		{
			bool flag = false;
			for (int q = 2; q < i; q++)
			{
				if (i % q == 0)
				{
					flag = true;
					break;
				}
				
			}
			if (flag==false && i>2)
			{
				sum += i;
				if (min_num == 0)
				{
					min_num = i;
				}
			}
		}
	}
	if (sum == 0)
	{
		cout << -1;
	}
	else
	{
		cout << sum << "\n" << min_num;
	}
	return 0;
}
#include <iostream>
using namespace std;
int main()
{
	int n;
	int num;
	int cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		bool flag=false;
		cin >> num;
		// 소수란 약수가 자기 자신과 1인 수
		// 그렇다면 2,3,5,7,11,13,... 등등등이 있다.
		if (num == 1) // 1인경우 예외처리
		{
			continue;
		}
		else if (num == 2) // 2인경우 예외처리
		{
			cnt++;
			continue;
		}
		else // 3이상부터 별도로 소수 판별하기
		{
			for (int q = 2; q < num; q++)
			{
				if (num % q == 0)
				{
					flag = false;
					break;
				}
				else
				{
					flag = true;
				}
			}
			if (flag == true)
			{
				cnt++;
			}
		}
		
	}
	cout << cnt;
	return 0;
}
#include <iostream>
using namespace std;
int main()
{
	int n,cnt_3=0,cnt_5=0;
	bool flag5, flag3;
	cin >> n;
	if (n / 5 != 0)
	{
		for (int i = 1; i <= n/5; i++)
		{
			int temp = n - 5 * i;
			if (temp % 3 == 0)
			{
				cnt_5 = i;
				cnt_3 = temp / 3;
			}
		}
		if (cnt_3 != 0)
		{
			cout << cnt_5 + cnt_3;
			return 0;
		}
	}
	if(n%5==0)
	{
		cout << n / 5;
		return 0;
	}
	if (cnt_3 == 0)
	{
		if (n % 3 == 0)
		{
			cnt_3 = n / 3;
			cout << cnt_3;
		}
		else
		{
			cout << -1;
		}
		return 0;
	}
	return 0;
}
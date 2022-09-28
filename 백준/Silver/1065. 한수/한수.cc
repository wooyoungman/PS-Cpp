#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int a;
	int cnt = 0;
	cin >> a;
	// 110의 결과 값이 99이므로 일의 자리와 십의 자리 수의 한수 개수 99개
	for (int q = 1; q <= a; q++)
	{
		if (q < 100)
		{
			cnt++;
		}
		else
		{
			if (((q/100)+(q%10))==2*((q/10)%10))
			{
				cnt++;
			}

		}

	}
	cout << cnt;
	return 0;
}
	
#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,check=0;
	// 245의 분해합은 245+2+4+5 = 256, 이때 245는 256의 생성자이다.
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int sum = 0,temp=i;
		while (temp != 0)
		{
			sum += temp % 10;
			temp /= 10;
		}
		sum += i;
		if (sum == n)
		{
			check = 1;
			cout << i;
			break;
		}
	}
	if (check == 0)
	{
		cout << 0;
	}
	return 0;
}
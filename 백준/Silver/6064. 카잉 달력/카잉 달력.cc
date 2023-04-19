#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>
#include<map>
#include<string>
// 단순 수식을 이용하여 경우의 수를 나누어 풀어보았지만.... 어려워서 힌트를 보고 풀이 방법을 찾았다.
// m=10, n=12 이고 51번째 해를 x,y로 표현하려면?

//51은 10이 5번 들어가고 1년이 지나면 51->x = 1
//51은 12가 4번 들어가고 3년이 지나면 51->y = 3
//
//그러나 나머지가 0이면 최대값으로(멸망해)
//-> 50번째 해는 x로 표현하면 10, m과 n이 동시에 나누어지는 최소값이 멸망해가 된다.즉, 최소 공배수
//
//그렇다면 우리가 구하려는 x가 3이라면 x가 3이 되는 해에서 y값을 구하고 이 y값이 우리가 구하려는 y가 맞는지 비교하면 된다.
//
//그렇다면 m = 10 일 때 x = 3, 13, 23 ....씩 증가시키고
//이 때 n = 12라면 y는 x를 12로 나눈 나머지의 값인 y = 3, 1, 11 ... 이런식이다.
// 최대공약수 15 10 (유클리드 호제법)
int gcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	return gcd(b, a % b);
}
// 최대공배수
int lcm(int a, int b)
{
	return (a * b) / gcd(a, b);
}
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int m, n, x, y,ans=-1;
		cin >> m >> n >> x >> y;
		int max = lcm(m, n);
		for (int i = x; i <= max; i += m)
		{
			int ny = i % n;
			if (ny == 0)
			{
				// 이 때, y가 최대값
				ny = n;
			}
			if (ny == y)
			{
				ans = i;
				break;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

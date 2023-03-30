#include <iostream>

using namespace std;

int t, h, w, n,val;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, h, w,n;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> h >> w >> n;
		// 꼭대기 층
		if (n % h == 0)
		{
			val = h * 100 + (n / h);
		}
		else
		{
			val = (n % h) * 100 + (n / h) + 1;
		}
		cout << val << "\n";
	}
	return 0;
}
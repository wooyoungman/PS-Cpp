#include <iostream>
#include <algorithm>

using namespace std;

int a,b,ga,gb;


int main()
{
	cin >> a >>b;
	int m = min(a, b);
	for (int i = 1; i <= m; i++)
	{
		if ((a % i == 0) && (b % i == 0))
		{
			ga = i;
		}
	}
	gb = ga * (a / ga) * (b / ga);
	cout << ga<<"\n" << gb;
	return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;
int check[250000] = { 0, };
void func(int n)
{
	check[0] = 1;
	check[1] = 1;
	for (int i = 2; i <= 2*n; i++)
	{
		for (int w = i * 2; w <= 2 * n; w += i)
		{
			check[w] = 1;
		}
	}
	return;
}
void print(int n)
{
	int cnt = 0;
	for (int i = n+1; i <= 2 * n; i++)
	{
		if (check[i] == 0)
		{
			cnt++;
		}
	}
	cout << cnt << "\n";
}

int main()
{
	int n;
	func(123456);
	while (1)
	{
		cin >> n;
		if (n == 0)
		{
			break;
		}
		print(n);
	}
	return 0;
}
#include <iostream>
using namespace std;
int check[10000] = { 0, };

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int a = 0; a <= 10000; a++)
		{
			check[a] = 0;
		}
		check[0] = 1;
		check[1] = 1;
		for (int i = 2; i <= 10000; i++)
		{
			for (int w = 2 * i; w <= 10000; w += i)
			{
				check[w] = 1;
			}
		}
		int num;
		int idx = 0;
		cin >> num;
		for (int w = 2; w <= num/2; w++)
		{
			if (check[w] == 0&&check[num-w]==0)
			{
				idx = w;
			}
		}
		cout << idx << ' ' << num - idx<<"\n";
	}
	return 0;
	// check = 0 이면 소수.

}
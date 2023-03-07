#include <iostream>
using namespace std;

int arr[100][100] = { 0, };

int main()
{
	int n, ld, dd,cnt=0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> ld >> dd;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (arr[ld+i][dd+j] == 0)
				{
					arr[ld+i][dd+j] = 1;
					cnt++;
				}
			}
		}
	}

	cout << cnt << endl;
	return 0;
}
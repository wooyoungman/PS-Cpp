#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, cnt_2 = 0, cnt_5 = 0, cnt_10 = 0,temp;
	cin >> n;
	for (int i = n; i >= 1; i--)
	{	
		temp = i;
		while (1)
		{
			if (temp % 2 == 0)
			{
				temp /= 2;
				cnt_2++;
			}
			else
			{
				break;
			}
		}
		temp = i;
		while (1)
		{
			if (temp % 5 == 0)
			{
				temp /= 5;
				cnt_5++;
			}
			else
			{
				break;
			}
		}
	}
	while (1)
	{
		if (cnt_2 == 0 || cnt_5 == 0)
		{
			break;
		}
		cnt_2--;
		cnt_5--;
		cnt_10++;
	}
	cout << cnt_10;
	return 0;
}

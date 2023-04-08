#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
int arr[130][130];
int cnt[2];

void dc(int x, int y, int size)
{
	bool check = false;
	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			if (arr[x][y] != arr[i][j])
			{
				check = true;
				break;
			}
		}
		if (check)
		{
			break;
		}
	}
	if (!check)
	{
		cnt[arr[x][y]]++;
		return;
	}
	dc(x, y, size / 2);
	dc(x + size / 2,y, size / 2);
	dc(x, y + size / 2, size / 2);
	dc(x + size / 2, y + size / 2, size / 2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	dc(0, 0, n);
	cout << cnt[0] << "\n" << cnt[1] << "\n";
	return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
int arr[2200][2200];
int cnt[3];
void dc(int x, int y, int size)
{
	bool check = false;
	int first_num = arr[x][y];
	for (int i = x; i < x+size; i++)
	{
		for (int j = y; j < y+size; j++)
		{
			if (arr[i][j] != first_num)
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
		cnt[arr[x][y] + 1]++;
		return;
	}
	dc(x, y, size / 3);
	dc(x, y + size / 3, size / 3);
	dc(x, y + 2 * size / 3, size / 3);
	dc(x + size / 3, y, size / 3);
	dc(x + size / 3, y + size / 3, size / 3);
	dc(x + size / 3, y + 2 * size / 3, size / 3);
	dc(x + 2 * size / 3, y, size / 3);
	dc(x + 2 * size / 3, y + size / 3, size / 3);
	dc(x + 2 * size / 3, y + 2 * size / 3, size / 3);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	dc(0, 0, n);
	cout << cnt[0] << "\n" << cnt[1] << "\n" << cnt[2];
	return 0;
}

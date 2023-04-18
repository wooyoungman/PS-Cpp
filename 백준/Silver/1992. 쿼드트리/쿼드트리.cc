#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>
#include<map>
#include<string>
using namespace std;
int arr[64][64];
int n;
void func(int x, int y, int size_x,int size_y)
{
	bool check = false;
	for (int i = x; i < size_x; i++)
	{
		for (int j = y; j < size_y; j++)
		{
			if (arr[x][y] != arr[i][j])
			{
				check = true;
				// 왼쪽 위 오른쪽 위 왼쪽 아래 오른쪽 아래 순서로 분할 탐색
				break;
			}
		}
		if (check)
		{
			break;
		}
	}
	if (check)
	{
		if (x + 2 == size_x || y + 2 == size_y)
		{
			cout << '(';
			for (int i = x; i < size_x; i++)
			{
				for (int j = y; j < size_y; j++)
				{
					cout << arr[i][j];
				}
			}
			cout << ')';
			return;
		}
		// (x+size_x)/2
		cout << '(';
		func(x, y, (x+size_x) / 2, (y+size_y) / 2);
		func(x, (y + size_y) / 2, (size_x+x) / 2, size_y);
		func((x + size_x) / 2, y, size_x, (y + size_y) / 2);
		func((x + size_x) / 2, (y + size_y) / 2, size_x, size_y);
		cout << ')';
	}
	else
	{
		cout << arr[x][y];
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = s[j] - '0';
		}
	}
	func(0, 0, n,n);
	return 0;
}

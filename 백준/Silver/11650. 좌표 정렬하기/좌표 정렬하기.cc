#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
// 구조체 풀이

typedef struct {
	int x;
	int y;
}pos;

bool cmp(pos& p1, pos& p2)
{
	if (p1.x == p2.x)
	{
		return p1.y < p2.y;
	}
	else
	{
		return p1.x < p2.x;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	pos* arr = new pos[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].x >> arr[i].y;
	}
	sort(arr, arr + n,cmp);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i].x << ' ' << arr[i].y << "\n";
	}
	delete[] arr;
	return 0;
}
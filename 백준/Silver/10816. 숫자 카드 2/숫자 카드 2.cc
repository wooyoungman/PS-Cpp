#include <iostream>
#include <algorithm>

using namespace std;

int arr[20000001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, num, m, num_2;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		arr[num+10000000]++;
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> num_2;
		cout << arr[num_2 + 10000000]<<' ';
	}
	return 0;
}
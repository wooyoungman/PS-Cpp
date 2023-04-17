#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>
#include<map>
#include<string>
int arr[100011];
int cnt_arr[100011];
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, num1, num2, cnt = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		cnt += arr[i];
		cnt_arr[i] = cnt;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> num1 >> num2;
		cout << cnt_arr[num2] - cnt_arr[num1-1] << "\n";
	}
	return 0;
}

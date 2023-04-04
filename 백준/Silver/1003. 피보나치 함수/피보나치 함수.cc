#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int cnt_0 = 0, cnt_1 = 0;
int arr[42][2];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int t,n;
    cin >> t;
    arr[0][0] = 1;
    arr[0][1] = 0;
    arr[1][0] = 0;
    arr[1][1] = 1;
    for (int i = 2; i <= 40; i++)
    {
        arr[i][0] = arr[i - 1][0] + arr[i - 2][0];
        arr[i][1] = arr[i - 1][1] + arr[i - 2][1];
    }
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cout << arr[n][0] << " " << arr[n][1]<<"\n";
    }
	return 0;
}
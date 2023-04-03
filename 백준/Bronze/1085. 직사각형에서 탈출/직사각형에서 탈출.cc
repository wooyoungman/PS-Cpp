#include <iostream>
#include <algorithm>

using namespace std;



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	// 상하좌우 가장 작은 값만 따지기
	int arr[4];
	arr[0]=h - y;
	arr[1]= y;
	arr[2]=x;
	arr[3]= w - x;
	cout<< *min_element(arr, arr + 4);
	return 0;
}
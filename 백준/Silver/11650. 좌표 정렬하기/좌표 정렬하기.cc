#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// 벡터 풀이 (벡터에서 sort를 이용하면 first 기준으로 정렬
// first가 같으면 알아서 second를 비교
vector <pair<int, int>> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n,x,y;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		v.push_back({x, y});
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
	{
		cout << v[i].first << ' ' << v[i].second << "\n";
	}
	return 0;
}

// 구조체 풀이

//typedef struct {
//	int x;
//	int y;
//}pos;
//
//bool cmp(pos& p1, pos& p2)
//{
//	if (p1.x == p2.x)
//	{
//		return p1.y < p2.y;
//	}
//	else
//	{
//		return p1.x < p2.x;
//	}
//}
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	int n;
//	cin >> n;
//	pos* arr = new pos[n];
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i].x >> arr[i].y;
//	}
//	sort(arr, arr + n, cmp);
//	for (int i = 0; i < n; i++)
//	{
//		cout << arr[i].x << ' ' << arr[i].y << "\n";
//	}
//	delete[] arr;
//	return 0;
//}
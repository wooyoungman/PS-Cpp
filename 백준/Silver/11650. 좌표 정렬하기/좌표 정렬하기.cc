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
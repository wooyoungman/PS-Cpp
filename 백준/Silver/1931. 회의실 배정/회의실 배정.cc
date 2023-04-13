#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <pair<int, int>>v;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, st, et, cnt = 1;
	cin >> n;
	// sort를 간단히 하기 위해 끝나는 시간을 앞에
	for (int i = 0; i < n; i++)
	{
		cin >> st >> et;
		v.push_back(make_pair(et, st));
	}
	// first에 끝나는 시간이 오름차순으로 정렬
	sort(v.begin(), v.end());
	int now = 0;
	for (int i = 1; i < n; i++)
	{
		if (v[now].first <= v[i].second)
		{
			cnt++;
			now = i;
		}
	}
	cout << cnt;
	return 0;
}
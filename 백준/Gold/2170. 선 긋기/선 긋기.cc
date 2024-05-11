#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, ans;
vector<pair<int, int>>v;
void func() {

	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		v.push_back({ s,e });
	}
	sort(v.begin(), v.end());
	int s = 0;
	int e = 0;
	int temp = 0;
	for (auto p : v) {
		if (s == 0 && e == 0) {
			s = p.first;
			e = p.second;
			continue;
		}
		int ns = p.first;
		int ne = p.second;
		// 1. 완전히 포함되는 경우
		if (s <= ns && ne <= e)continue;
		// 2. 일부만 이어지는 경우
		else if ((ns<s && ne >= s || ns <= e && ne>e)) {
			s = min(s, ns);
			e = max(e, ne);
		}
		// 3. 새롭게 선이 생기는 경우
		else {
			ans += (e - s);
			s = ns;
			e = ne;
		}
	}
	// 4. 마지막 선 길이 추가
	ans += e - s;
	cout << ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	func();

	return 0;
}
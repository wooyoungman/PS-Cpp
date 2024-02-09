#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int h, w;
int ans;
vector<pair<int, int>>v;

// 백트래킹으로 모든 계란에 대해
// 깨본 후 최대 결과를 저장? 


void recur(int depth) {

	if (depth == n) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int now_h = v[i].first;
			if (now_h <= 0)cnt++;
		}
		ans = max(ans, cnt);
		return;
	}

	// 현재 들고있는 계란이 깨진 경우 다음 계란으로 진행
	if (v[depth].first <= 0) {
		recur(depth + 1);
		return;
	}

	bool isBroken = false;
	for (int i = 0; i < n; i++) {
		if (i != depth && v[i].first > 0) {
			v[depth].first -= v[i].second;
			v[i].first -= v[depth].second;
			isBroken = true;
			recur(depth + 1);
			v[depth].first += v[i].second;
			v[i].first += v[depth].second;
		}
	}

	if (!isBroken) recur(depth + 1);

}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h >> w;
		v.push_back({ h,w });
	}

	recur(0);
	cout << ans;
	return 0;
}
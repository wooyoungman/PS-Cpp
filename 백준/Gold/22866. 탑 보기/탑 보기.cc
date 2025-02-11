#include<iostream>
#include<stack>
#include<cmath>
using namespace std;

int n;
int height[100001], cnt[100001], near_one[100001];

// 건물의 높이, 인덱스 저장 (좌->우, 우->좌 1회씩 저장)
stack<pair<int, int>>s1, s2;

void solve() {

	// 정방향 (좌->우)
	s1.push({ height[1],1 });
	for (int i = 2; i <= n; i++) {
		// 현재 스택의 top의 높이가 현재 건물의 높이보다 작거나 같으면 교체
		while (!s1.empty() && s1.top().first <= height[i])s1.pop();
		cnt[i] += s1.size();
		if (!s1.empty() && near_one[i] == 0)near_one[i] = s1.top().second;
		s1.push({ height[i],i });
	}

	// 역방향 (우->좌)
	s2.push({ height[n],n });
	for (int i = n-1; i >= 1; i--) {
		// 현재 스택의 top의 높이가 현재 건물의 높이보다 작거나 같으면 교체
		while (!s2.empty() && s2.top().first <= height[i])s2.pop();
		cnt[i] += s2.size();
		if (!s2.empty() && near_one[i] == 0)near_one[i] = s2.top().second;
		else if (!s2.empty() && near_one[i] != 0) {
			if (abs(i - near_one[i]) > abs(i - s2.top().second))near_one[i] = s2.top().second;
		}
		s2.push({ height[i],i });
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> height[i];
	}
	solve();
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 0)cout << 0 << "\n";
		else cout << cnt[i] << " " << near_one[i] << "\n";
	}
	return 0;
}
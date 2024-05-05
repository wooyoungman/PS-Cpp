#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int w, h, ans;
vector<int>v(500);
int main() {
	cin >> h >> w;
	for (int i = 0; i < w; i++) {
		cin >> v[i];
	}
	// 자기 자신 기준 왼쪽 오른쪽에 대해 
	// 가장 큰 높이 2개를 찾는다.
	// 그 두 높이 중 작은 것과의 차이를 더한다.
	for (int i = 1; i < w - 1; i++) {
		int left = 0;
		int right = w - 1;
		int highL = 0;
		int highR = 0;
		for (int j = left; j < i; j++) {
			highL = max(highL, v[j]);
		}
		for (int j = i+1; j <= right; j++) {
			highR = max(highR, v[j]);
		}
		if (highL <= v[i] || highR <= v[i])continue;
		ans += (min(highL, highR) - v[i]);
	}
	cout << ans;
	return 0;
}
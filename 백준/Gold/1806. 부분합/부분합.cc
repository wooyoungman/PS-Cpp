#include <iostream>
#include <limits.h>
#include <algorithm>
#define MAX INT_MAX
using namespace std;

int n, s;
int num[100001];

int main() {
	
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	int left = 0;
	int right = 0;
	int sum = 0;
	int cnt = 0;
	int ans = MAX;
	while (left <= right) {
		if (sum >= s) {
			// 현재 sum이 s 이상이면 현재 길이와 이전까지의 길이 비교 후 저장
			ans = min(right - left, ans);
			// sum에서 현재 num[left]값 빼고 left 한 칸 우측이동
			sum -= num[left++];
		}
		// 탐색 범위 넘어가면 종료
		else if (right == n)break;
		else {
			sum += num[right++];
		}
	}
	if (ans == MAX) {
		cout << 0;
	}
	else {
		cout << ans;
	}
	
	return 0;
}
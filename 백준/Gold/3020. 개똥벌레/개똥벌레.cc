#include<iostream>
#include<climits>
#include<algorithm>
#define MAX INT_MAX
using namespace std;

int n, h;

int bottom[500001];
int top[500001];
int sum[500001];
int main() {
	cin >> n >> h;
	// 1~7까지 높이 입력 (h=7 일 때, 높이 7인 경우 0이 되어버리기 때문에 + 1)
	for (int i = 0; i < n; i++) {
		int v;
		cin >> v;
		if (i % 2 == 0)bottom[v]++;
		else top[h - v + 1]++;
	}

	for (int i = h - 1; i >= 0; i--) {
		bottom[i] += bottom[i + 1];
		top[h - i] += top[h - i - 1];
	}
	
	
	for (int i = 1; i <= h; i++) {
		sum[i] += top[i] + bottom[i];
	}

	sort(sum, sum + h);

	int min_sum = sum[1];
	int cnt = 0;

	for (int i = 1; i <= h; i++) {
		if (sum[i] == min_sum)cnt++;
	}
	cout << min_sum << " " << cnt;
	return 0;
}
// 누적합
#include <iostream>

using namespace std;

int n, h;

// 높이가 5 (0-1, 1-2, 2-3, 3-4, 4-5) 5개의 구간이 존재
// 석순의 경우 가장 긴 높이부터 역순으로 누적합 진행
// 5의 높이인 석순이 있다 -> 1,2,3,4 구간에도 존재한다.
// 석순[i] += 석순[i+1] (i=h-1 부터 감소)

// 4의 높이인 종유석이 있다. -> (1-2, 2-3, 3-4, 4-5) 4개의 구간에 존재
// 종유석[i] += 종유석[i-1] (i=1 부터 증가)

int bottom[500001];
int top[500001];
int sum[500001];
int main() {
	
	cin >> n >> h;
	
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (i % 2 == 0)bottom[num]++;
		else top[h - num + 1]++;
	}

	for (int i = h - 1; i >= 1; i--) {
		bottom[i] += bottom[i + 1];
	}
	
	int cnt = 0;
	int min_sum = 999999;

	for (int i = 1; i <= h; i++) {
		top[i] += top[i - 1];
		sum[i] = top[i] + bottom[i];
		if (min_sum > sum[i]) {
			min_sum = sum[i];
			cnt = 1;
		}
		else if (min_sum == sum[i] && cnt != 0) {
			cnt++;
		}
	}

	cout << min_sum << " " << cnt;



	return 0;
}
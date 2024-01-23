#include<iostream>
#include<deque>
#define MAX 100001

using namespace std;

int n, k;

int dist[MAX];

int main() {

	cin >> n >> k;
	if (n > k) {
		cout << n - k;
		return 0;
	}
	else if (n == k) {
		cout << 0;
		return 0;
	}
	else {

		deque<int>dq;
		dq.push_front(n);
		dist[n] = 1;

		while (!dq.empty()) {
			int cur = dq.front();
			dq.pop_front();
			if (cur == k)break;

			// 순간이동의 경우
			int ntel_pos = cur * 2;
			if (ntel_pos < MAX && dist[ntel_pos] == 0) {
				dq.push_front(ntel_pos);
				dist[ntel_pos] = dist[cur];
			}
			// -1인 경우
			int nminus_pos = cur - 1;
			if (nminus_pos >= 0 && dist[nminus_pos] == 0) {
				dq.push_back(nminus_pos);
				dist[nminus_pos] = dist[cur] + 1;
			}



			// +1인 경우
			int nplus_pos = cur + 1;
			if (nplus_pos < MAX && dist[nplus_pos] == 0) {
				dq.push_back(nplus_pos);
				dist[nplus_pos] = dist[cur] + 1;
			}
		}
		cout << dist[k] - 1;

		return 0;
	}
}
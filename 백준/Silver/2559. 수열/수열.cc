#include <iostream>
#include <deque>
using namespace std;

int main() {

	deque<int>dq;
	int n, k, t, max=0,cur_sum=0;
	cin >> n >> k;
	// deque에 우선 입력되는 온도의 수열 저장하기
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (dq.size() != k) {
			dq.push_back(t);
			max += t;
			cur_sum += t;
		}
		else {
			cur_sum = cur_sum - dq.front() + t;
			if (cur_sum > max) {
				max = cur_sum;
			}
			dq.pop_front();
			dq.push_back(t);
		}
	}
	cout << max;
	return 0;
}
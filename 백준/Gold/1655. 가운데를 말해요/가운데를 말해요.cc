#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;
priority_queue<int>max_pq;
priority_queue<int, vector<int>, greater<int>>min_pq;
int n;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	int num;
	cin >> num;
	min_pq.push(num);
	cout << num << "\n";
	for (int i = 0; i < n-1; i++) {
		cin >> num;
		// 현재 숫자 개수가 짝수인 경우
		if (i % 2 == 0) {
			// 최대 힙에 넣어야 하지만, 현재 최소 힙의 top보다 크다면 바꾸어 저장한다.
			if (num > min_pq.top()) {
				int temp = min_pq.top();
				min_pq.pop();
				max_pq.push(temp);
				min_pq.push(num);
			}
			else {
				max_pq.push(num);
			}
			cout << max_pq.top() << "\n";
		}
		// 현재 숫자 개수가 홀수인 경우
		else {
			// 최소 힙에 넣어야 하지만, 현재 최대 힙의 top보다 작다면 바꾸어 저장한다.
			if (num < max_pq.top()) {
				int temp = max_pq.top();
				max_pq.pop();
				min_pq.push(temp);
				max_pq.push(num);
			}
			else {
				min_pq.push(num);
			}

			cout << min_pq.top() << "\n";
		}
	}

	return 0;
}

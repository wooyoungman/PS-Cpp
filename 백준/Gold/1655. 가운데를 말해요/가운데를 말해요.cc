#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;
priority_queue<int>max_pq;
priority_queue<int, vector<int>, greater<int>>min_pq;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	register int n;
	cin >> n;
	register int num;
	cin >> num;
	min_pq.push(num);
	cout << num << "\n";
	for (register int i = 0; i < n - 1; i++) {
		cin >> num;
		if (i % 2 == 0) {
			if (num > min_pq.top()) {
				register int temp = min_pq.top();
				min_pq.pop();
				max_pq.push(temp);
				min_pq.push(num);
			}
			else {
				max_pq.push(num);
			}
			cout << max_pq.top() << "\n";
		}
		else {
			if (num < max_pq.top()) {
				register int temp = max_pq.top();
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

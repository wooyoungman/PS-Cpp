#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, m;
vector<int>quizs[32001];
int preSolved[32001];

void func() {
	priority_queue<int,vector<int>,greater<>>pq;
	for (int i = 1; i <= n; i++) {
		if (preSolved[i] == 0)pq.push(i);
	}
	while (!pq.empty()) {
		int num = pq.top();
		pq.pop();
		cout << num << " ";
		for (auto p : quizs[num]) {
			preSolved[p]--;
			if (preSolved[p] == 0) {
				pq.push(p);
			}
		}
	}
}

int main() {

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		quizs[a].push_back(b);
		preSolved[b]++;
	}
	func();
	return 0;
}
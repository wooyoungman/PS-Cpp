#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

priority_queue<int, vector<int>, greater<int>>pq;
vector<pair<int, int>>v;

int n;
int ans;
int main() {
	
	int s, f;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s >> f;
		v.push_back({ s,f });
	}

	sort(v.begin(), v.end());

	
	// 현재 종료시간이 다음 시작시작과 같거나 작은경우 현재를 pop
	for (int i = 0; i < v.size(); i++) {
		pq.push(v[i].second);
		if (pq.top() <= v[i].first)pq.pop();
	}
	cout << pq.size();
	return 0;
}
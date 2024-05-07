#include<iostream>
#include<queue>
#include<vector>
#include<climits>
#define MAX INT_MAX
using namespace std;

int n, m;
vector<pair<int,int>>v[50001];
int dist[50001];
struct Cmp {
	bool operator()(pair<int, int>a, pair<int, int>b) {
		return a.second > b.second;
	}
};
void func() {
	// 1 -> n까지 갈 때 최소비용으로 = 다익스트라
	for (int i = 1; i <= n; i++) {
		dist[i] = MAX;
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp>pq;
	for (auto p : v[1]) {
		pq.push({ p.first,p.second });
		dist[p.first] = p.second;
	}
	while (!pq.empty()) {
		pair<int, int> now = pq.top();
		pq.pop();
		if (dist[now.first] == MAX)dist[now.first] = now.second;
		for (auto p : v[now.first]) {
			if (p.first == 1)continue;
			if (dist[p.first] <= dist[now.first] + p.second) {
				continue;
			}
			dist[p.first] = dist[now.first] + p.second;
			pq.push({ p.first,dist[p.first] });
		}
	}
	cout << dist[n];
}

int main() {
	cin >> n >> m;
	func();
	return 0;
}
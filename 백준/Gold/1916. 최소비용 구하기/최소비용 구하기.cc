#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>

#define N 1001
#define INF INT_MAX

using namespace std;


// 시작 정점, 가중치, 도착 정점 순으로 저장
vector<pair<int, int>>nodes[N];

// 출발점 -> 도착점 거리 저장 배열
int dist[N];

void dijkstra(int start) {

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	pq.push(make_pair(0, start));
	dist[start] = 0;

	while (!pq.empty()) {
		int cur_cost = pq.top().first;
		int cur_pos = pq.top().second;
		pq.pop();
		if (cur_cost > dist[cur_pos])continue;
		for (int i = 0; i < nodes[cur_pos].size(); i++) {
			int next_cost = cur_cost + nodes[cur_pos][i].first;
			if (next_cost < dist[nodes[cur_pos][i].second]) {
				dist[nodes[cur_pos][i].second] = next_cost;
				pq.push(make_pair(next_cost, nodes[cur_pos][i].second));
			}
		}
	}

}

int main() {
	int n, m, u, v, w, start, end;
	cin >> n;
	cin >> m;
	
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}

	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		nodes[u].push_back(make_pair(w, v));
	}

	cin >> start >> end;
	dijkstra(start);
	cout << dist[end];
	return 0;
}
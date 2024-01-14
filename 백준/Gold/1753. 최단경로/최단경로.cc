#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
#define N 20001
#define INF INT_MAX
using namespace std;

// u에서 v로 가는 가중치w 간선 저장 벡터
vector<pair<int, int>>nodes[N];

// 시작점으로부터 최단거리 저장 배열(INF로 모든 값 초기화)
int dist[N];

void dijkstra(int start) {

	// 가중치가 낮은 간선부터 저장
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

	// 비용과 시작지점 추가
	pq.push(make_pair(0,start));

	// 시작점-시작점 거리 0 초기화
	dist[start] = 0;

	while (!pq.empty()) {
		// 시작점으로부터의 비용, 현재 위치 추출
		int cur_cost = pq.top().first;
		int cur_pos = pq.top().second;
		pq.pop();

		// 최단 거리가 아닌경우 스킵
		if (dist[cur_pos] < cur_cost)continue;

		for (int i = 0; i < nodes[cur_pos].size(); i++) {
			// 현재 정점 까지의 비용 + 다음 정점으로 이동하는 비용
			int next_cost = cur_cost + nodes[cur_pos][i].first;

			// 저장된 비용보다 작은 경우 값 갱신 후 큐에 추가
			// 1->2, 1->4가 초기에 INF였으나, 가중치 2,1을 갖고 있으면 갱신 후 
			// 다음 방문 노드로 저장하는 코드임 (간선의 가중치가 낮은 것이 우선순위 높음)
			if (next_cost < dist[nodes[cur_pos][i].second]) {
				dist[nodes[cur_pos][i].second] = next_cost;
				pq.push(make_pair(next_cost, nodes[cur_pos][i].second));
			}
				
		}
	}

}

int main() {

	int V, E, start, u, v, w;
	cin >> V >> E;
	cin >> start;
	for (int i = 1; i <= V; i++) {
		dist[i] = INF;
	}
	for (int i = 1; i <= E; i++) {
		cin >> u >> v >> w;
		nodes[u].push_back(make_pair(w, v));
	}
	dijkstra(start);
	for (int i = 1; i <= V; i++) {
		if (i == start) cout << 0 << "\n";
		else {
			if (dist[i] == INF)cout << "INF" << "\n";
			else cout << dist[i] << "\n";
		}
	}


	return 0;
}
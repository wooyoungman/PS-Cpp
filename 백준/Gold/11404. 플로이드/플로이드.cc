#include<iostream>
#include<vector>
#include<limits.h>

#define INF INT_MAX
using namespace std;

int n, m;
int main() {

	// 정점 n개(1~n까지), 간선 m개
	// 간선에 대한 정보 (출발 지점, 도착 지점, 가중치)
	cin >> n;
	cin >> m;

	vector<vector<int>>dist(n + 1, vector<int>(n + 1, INF));

	int s, e, w;
	for (int i = 1; i <= n; i++) {
		dist[i][i] = 0;
	}

	for (int i = 1; i <= m; i++) {
		cin >> s >> e >> w;
		dist[s][e] = min(w,dist[s][e]);
	}


	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][k]!=INF&&dist[k][j]!=INF)
					dist[i][j] = min(dist[i][k] + dist[k][j],dist[i][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == INF)cout << 0 << " ";
			else cout << dist[i][j] << " ";
		}
		cout << "\n";
	}

	// 플로이드 와샬 : 모든 정점으로부터 모든 정점으로까지의 최단거리
	// 3중 반복문 (경유지점, 출발지점, 도착지점)



	return 0;
}
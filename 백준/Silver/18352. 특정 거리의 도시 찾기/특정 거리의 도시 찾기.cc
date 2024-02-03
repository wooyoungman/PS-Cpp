#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
#define MAX INT_MAX


using namespace std;
int n, m, k, x;
int dist[300001];
bool visited[300001];
vector<int>v[300001];
vector<int>ans;
// 도시 X에서 도달할 수 있는 모든 도시로의 최단거리가 K인 
// 도시들의 번호를 출력 

void bfs(int start) {
	queue<int>q;
	q.push(start);
	dist[start] = 0;
	while (!q.empty()) {
		int cur = q.front();
		visited[cur] = true;
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (visited[next])continue;
			visited[next] = true;
			dist[next] = dist[cur] + 1;
			q.push(next);
			if (dist[next] == k) {
				ans.push_back(next);
			}
		}
	}
}

int main() {

	int s, e;
	cin >> n >> m >> k >> x;
	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		v[s].push_back(e);
	}
	for (int i = 1; i <= n; i++) {
		dist[i] = MAX;
	}

	bfs(x);



	if (ans.empty()) {
		cout << -1;
	}
	else {
		sort(ans.begin(), ans.end());
		for (auto p : ans) {
			cout << p << "\n";
		}
	}
	return 0;
}
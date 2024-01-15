#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>
#define INF INT_MAX
#define N 1001

using namespace std;

vector<pair<int, int>>nodes[N];
vector<pair<int, int>>reverse_nodes[N];
int dist[N],reverse_dist[N];

// 파티 지점에서 각 집으로의 최단거리
void dijkstra(int x) {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    pq.push(make_pair(0, x));
    dist[x] = 0;

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

// 각 집에서 파티 지점으로의 최단거리
void reverse_dijkstra(int x) {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    pq.push(make_pair(0, x));
    reverse_dist[x] = 0;

    while (!pq.empty()) {
        int cur_cost = pq.top().first;
        int cur_pos = pq.top().second;
        pq.pop();
        if (cur_cost > reverse_dist[cur_pos])continue;
        for (int i = 0; i < reverse_nodes[cur_pos].size(); i++) {
            int next_cost = cur_cost + reverse_nodes[cur_pos][i].first;
            if (next_cost < reverse_dist[reverse_nodes[cur_pos][i].second]) {
                reverse_dist[reverse_nodes[cur_pos][i].second] = next_cost;
                pq.push(make_pair(next_cost, reverse_nodes[cur_pos][i].second));
            }
        }
    }
}

int main() {

    int n, m, x, u, v, w;
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        reverse_dist[i] = INF;
    }
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        nodes[u].push_back(make_pair(w, v));
        reverse_nodes[v].push_back(make_pair(w, u));
    }

    
    dijkstra(x);
    reverse_dijkstra(x);
    int answer = dist[1] + reverse_dist[1];
    for (int i = 2; i <= n; i++) {
        answer = max(answer, dist[i] + reverse_dist[i]);
    }
    cout << answer;
    return 0;
}
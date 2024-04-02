#include<iostream>
#include<queue>
#include<vector>
#include<climits>
#define MAX INT_MAX
using namespace std;
int n, e;
int v1, v2, ans;
int dist[801];
struct node {
	int e, l;
};
vector<node>edges[801];
// 벡터에 간선의 정보 저장
// pq에 경로 길이가 짧은 순서로 저장
// dist배열보다 작으면 갱신 

struct Cmp {
	bool operator()(node a,node b) {
		return a.l > b.l;
	}
};

int func(int start, int end) {
	if (start == end)return 0;
	for (int i = 1; i <= n; i++) {
		dist[i] = MAX;
	}
	priority_queue<node,vector<node>,Cmp>pq;
	for (int i = 0; i < edges[start].size(); i++) {
		pq.push({ edges[start][i].e,edges[start][i].l });
		dist[edges[start][i].e] = edges[start][i].l;
	}
	while (!pq.empty()) {
		node now = pq.top();
		pq.pop();
		for (int i = 0; i < edges[now.e].size(); i++) {
			node next = edges[now.e][i];
			if (dist[next.e] < dist[now.e] + next.l)continue;
			pq.push(next);
			dist[next.e] = dist[now.e] + next.l;
		}
	}
	return dist[end];
}

int main() {
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].push_back({ b,c });
		edges[b].push_back({ a,c });
	}
	cin >> v1 >> v2;
	long long c1 = (long long)func(1, v1) + func(v1, v2) + func(v2, n);
	long long c2 = (long long)func(1, v2) + func(v2, v1) + func(v1, n);
	if (c1 >= MAX && c2 >= MAX)cout << -1;
	else {
		cout << min(c1, c2);
	}

	return 0;
}

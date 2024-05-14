#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 집의 수 m, 길의 수 n
int m, n;
int parent[200001];
int total;
struct node {
	int s, e, w;
};

vector<node>nodes;

// 전체 비용을 더한 후 최소 비용으로 연결한 값을 빼면
// 절약할 수 있는 최대 치를 구할 수 있음
bool cmp(node a, node b) {
	return a.w < b.w;
}

void input() {
	for (int i = 0; i < n; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		total += w;
		node a = { s,e,w };
		node b = { e,s,w };
		nodes.push_back(a);
		nodes.push_back(b);
	}
	sort(nodes.begin(), nodes.end(), cmp);
}

void init() {
	total = 0;
	nodes.clear();
	for (int i = 0; i < m; i++) {
		parent[i] = i;
	}
}

int find(int tar) {
	if (tar == parent[tar])return tar;
	int ret = find(parent[tar]);
	parent[tar] = ret;
	return ret;
}

void setUnion(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);
	if (t1 == t2)return;
	parent[t2] = t1;
}

void Kruskal() {
	int target = n - 1;
	int result = 0;
	int selectCount = 0;

	for (auto p : nodes) {
		int s = p.s;
		int e = p.e;
		int w = p.w;
		if (find(s) == find(e))continue;
		setUnion(s, e);
		result += w;
		selectCount++;
		if (selectCount == target)break;
	}
	cout << total - result << "\n";
}

int main() {
	while (1) {
		cin >> m >> n;
		if (m == 0 && n == 0)break;
		init();
		input();
		Kruskal();

	}
	return 0;
}

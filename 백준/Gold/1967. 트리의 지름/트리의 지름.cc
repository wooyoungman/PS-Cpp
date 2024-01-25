#include <iostream>
#include <vector>
using namespace std;

int n,start,answer;
vector<pair<int, int>>nodes[10001];
bool check[10001];

void dfs(int root, int dist) {
	check[root] = true;

	if (dist > answer) {
		answer = dist;
		start = root;
	}

	for (int i = 0; i < nodes[root].size(); i++) {
		int next_node = nodes[root][i].first;
		int next_weight = nodes[root][i].second + dist;
		if (!check[next_node]) {
			check[next_node] = true;
			dfs(next_node, next_weight);
			check[next_node] = false;
		}
	}

}

int main() {

	int p, c, w;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		cin >> p >> c >> w;
		nodes[p].push_back(make_pair(c, w));
		nodes[c].push_back(make_pair(p, w));
	}
	dfs(1, 0);
	answer = 0;
	for (int i = 1; i <= n; i++) {
		check[i] = false;
	}
	dfs(start, 0);
	cout << answer;
	return 0;
}
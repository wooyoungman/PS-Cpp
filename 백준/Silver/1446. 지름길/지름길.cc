#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>>nodes[10001];
int dist[10001];
int main() {

	int n, d;
	cin >> n >> d;
	
	int start, end, length;

	for (int i = 0; i < n; i++) {
		cin >> start >> end >> length;
		if ((end-start)<length)continue;
		nodes[start].push_back(make_pair(end, length));
	}

	for (int i = 0; i <= d; i++) {
		dist[i] = i;
	}

	for (int i = 0; i <= d; i++) {
		if (i > 0) {
			dist[i] = min(dist[i], dist[i - 1] + 1);
		}
		for (auto p : nodes[i]) {
			if (dist[p.first] > dist[i] + p.second) {
				dist[p.first] = dist[i] + p.second; 
			}
		}
	}
	cout << dist[d];
	return 0;
}
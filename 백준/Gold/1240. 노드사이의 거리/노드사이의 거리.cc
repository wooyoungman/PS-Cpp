#include <iostream>
#include <vector>
using namespace std;


int n, m;
vector<pair<int, int>>v[1001];
vector<pair<int, int>>mv;
vector<int>answer;
bool visited[1001];
int goal1, goal2;
void dfs(int start, int end, int weight) {
	
	if (start == end) {
		answer.push_back(weight);
		return;
	}

	visited[start] = true;
	for (auto next : v[start]) {
		int next_pos = next.first;
		int next_weight = next.second;

		if (!visited[next_pos]) {
			dfs(next_pos, end, weight + next_weight);
		}

	}
	visited[start] = false;
}

int main() {

	cin >> n >> m;
	int start,end, weight;
	for (int i = 0; i < n - 1; i++) {
		cin >> start >> end >> weight;
		v[start].push_back({ end,weight });
		v[end].push_back({ start,weight });
	}


	int s, e;
	for (int i = 0; i < m; i++) {
		cin >> goal1 >> goal2;
		dfs(goal1, goal2, 0);
	}

	for (auto p : answer) {
		cout << p << "\n";
	}

	return 0;
}
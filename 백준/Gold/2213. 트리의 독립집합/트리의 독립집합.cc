#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
int weights[10001];
vector<int>trees[10001];
bool visited[10001];
int dp_selected[10001];
int dp_unselected[10001];
vector<int>selected_route[10001];
vector<int>unselected_route[10001];
void dp(int cur) {
	visited[cur] = true;
	dp_selected[cur] = weights[cur];
	selected_route[cur].push_back(cur);
	for (auto next : trees[cur]) {
		if (visited[next])continue;

		dp(next);
		dp_selected[cur] += dp_unselected[next];
		for (auto p : unselected_route[next]) {
			selected_route[cur].push_back(p);
		}
		
		dp_unselected[cur] += max(dp_selected[next], dp_unselected[next]);

		if (dp_selected[next] >= dp_unselected[next]) {
			for (auto p : selected_route[next]) {
				unselected_route[cur].push_back(p);
			}
		}
		else {
			for (auto p : unselected_route[next]) {
				unselected_route[cur].push_back(p);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> weights[i];
	}
	for (int i = 0; i < n - 1; i++) {
		int s, e;
		cin >> s >> e;
		trees[s].push_back(e);
		trees[e].push_back(s);
	}
	dp(1);
	cout << max(dp_selected[1], dp_unselected[1]) << "\n";
	if (dp_selected[1] >= dp_unselected[1]) {
		sort(selected_route[1].begin(),selected_route[1].end());
		for (auto p : selected_route[1]) {
			cout << p << " ";
		}
	}
	else {
		sort(unselected_route[1].begin(), unselected_route[1].end());
		for (auto p : unselected_route[1]) {
			cout << p << " ";
		}
	}

	return 0;
}
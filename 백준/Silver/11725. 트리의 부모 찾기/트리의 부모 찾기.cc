#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int>arr[100001];
int par[100001];
bool visited[100001];

void dfs(int start) {
	visited[start] = true;
	for (int i = 0; i < arr[start].size(); i++) {
		int next = arr[start][i];
		if (!visited[next]) {
			par[next] = start;
			dfs(next);
		}
	}
}

int main() {

	int a,b;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	dfs(1);
	for (int i = 2; i <= n; i++) {
		cout << par[i]<<"\n";
	}
	return 0;
}
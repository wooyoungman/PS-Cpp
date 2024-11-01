#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int n;

int population[10050];
vector<int>v[10050];
int dp[10050][2];
bool visited[10050];
void findTree(int node) {
	visited[node] = true;

	dp[node][0] = population[node];
	dp[node][1] = 0;
	
	for (int i = 0; i < v[node].size(); i++) {
		int nextNode = v[node][i];
		if (visited[nextNode])continue;
		findTree(nextNode);

		dp[node][0] += dp[nextNode][1];
		dp[node][1] += max(dp[nextNode][0], dp[nextNode][1]);
	}
}

void func() {

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> population[i];
	}
	int a, b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	findTree(1);
	cout << max(dp[1][0], dp[1][1]);
}

int main() {
	func();
	return 0;
}
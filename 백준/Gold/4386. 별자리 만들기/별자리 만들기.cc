#include<iostream>
#include<climits>
#include<queue>
#include<algorithm>
#include<vector>
#include<cmath>
#define MAX DBL_MAX
using namespace std;

double pos[101][2];
vector<pair<double, int>>info[101];
bool visited[101];
int n;
double ans;

void calDist() {
	for (int i = 1; i <= n; i++) {
		double a, b;
		cin >> a >> b;
		pos[i][0] = a;
		pos[i][1] = b;
	}
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			double d = sqrt(pow(pos[i][0] - pos[j][0], 2) + pow(pos[i][1] - pos[j][1], 2));
			info[i].push_back({ d,j });
			info[j].push_back({ d,i });
		}
	}

}

void Prim() {
	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>>pq;
	for (int i = 0; i < info[1].size(); i++) {
		pq.push(info[1][i]);
	}
	visited[1] = true;
	// 임의의 정점 하나 선택 후 연결된 모든 간선 저장
	// 가장 비용이 작은 간선의 정점부터 연결 
	while (!pq.empty()) {
		double dis = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		
		if (visited[now])continue;
		visited[now] = true;
		ans += dis;
		
		for (int i = 0; i < info[now].size(); i++) {
			double next_dis = info[now][i].first;
			int next = info[now][i].second;
			if (!visited[next])pq.push(info[now][i]);
		}

	}
}

int main() {
	cin >> n;
	calDist();
	Prim();
	cout << ans;
	return 0;
}
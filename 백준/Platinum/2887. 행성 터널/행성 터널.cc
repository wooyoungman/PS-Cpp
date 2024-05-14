#include<iostream>
#include<cmath>
#include<queue>
#include<algorithm>

using namespace std;

int n;
int parent[100001];
// x,y,z에 대해 (좌표, 번호를 저장)
vector<pair<int, int>>pos[3];
// 간선 저장
struct info {
	int dis, s, e;
};

bool cmp(info a, info b) {
	return a.dis < b.dis;
}

vector<info>edges;
void input() {
	for (int i = 0; i < n; i++) {
		parent[i] = i;
		int x, y, z;
		cin >> x >> y >> z;
		pos[0].push_back({ x,i });
		pos[1].push_back({ y,i });
		pos[2].push_back({ z,i });
	}
	// x,y,z의 좌표를 정렬
	sort(pos[0].begin(), pos[0].end());
	sort(pos[1].begin(), pos[1].end());
	sort(pos[2].begin(), pos[2].end());
	for (int i = 0; i < n-1; i++) {
		int dis_x = abs(pos[0][i].first - pos[0][i + 1].first);
		int dis_y = abs(pos[1][i].first - pos[1][i + 1].first);
		int dis_z = abs(pos[2][i].first - pos[2][i + 1].first);
		edges.push_back({ dis_x,pos[0][i].second,pos[0][i + 1].second });
		edges.push_back({ dis_y,pos[1][i].second,pos[1][i + 1].second });
		edges.push_back({ dis_z,pos[2][i].second,pos[2][i + 1].second });
	}
	sort(edges.begin(), edges.end(), cmp);
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
	int selectCount = 0;
	long long int result = 0;
	for (auto p : edges) {
		int start = p.s;
		int end = p.e;
		int dis = p.dis;
		// 사이클 검사
		if (find(start) == find(end))continue;
		setUnion(start, end);
		result += dis;
		selectCount++;
		if (selectCount == n - 1)break;
	}
	cout << result;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	input();
	Kruskal();
	
	return 0;
}
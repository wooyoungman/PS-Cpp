#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int n, m, ans;
int parent[1001];
struct Info {
	int start, end, cost;
};

bool compare(Info a, Info b) {
	if (a.cost != b.cost) {
		return a.cost < b.cost;
	}
	else {
		if (a.start != b.start) {
			return a.start < b.start;
		}
		else {
			return a.end < b.end;
		}
	}
}

void init() {

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
}

int find(int tar) {
	if (tar == parent[tar])return tar;
	int ret = find(parent[tar]);
	parent[tar] = ret;
	return ret;
}

void setUnion(int a,int b) {
	int t1 = find(a);
	int t2 = find(b);
	if (t1 == t2)return;
	parent[t2] = t1;
}
int main() {
	cin >> n;
	cin >> m;
	vector<Info>v(m);
	for (int i = 0; i < m; i++) {
		cin >> v[i].start >> v[i].end >> v[i].cost;
	}
	sort(v.begin(), v.end(), compare);
	init();
	for (int i = 0; i < v.size(); i++) {
		Info now = v[i];
		int now_start = now.start;
		int now_end = now.end;
		int now_cost = now.cost;
		if (find(now_start) != find(now_end)) {
			setUnion(now_start, now_end);
			ans += now_cost;
			n--;
			if (n == 0) {
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
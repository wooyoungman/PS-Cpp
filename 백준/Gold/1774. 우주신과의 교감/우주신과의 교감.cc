#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;
set<pair<int, int>>s;
int n, m;
int parents[1001];
bool isConnected[1001];
vector<pair<int, int>>connection;

struct Info {
	int n1, n2;
	double dis;
};
vector<pair<int, int>>pos;
vector<Info>infos;

struct Cmp {
	bool operator()(Info a, Info b) {
		return a.dis < b.dis;
	}
};

// 입력
void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		pos.push_back({ x,y });
	}

	for (int i = 0; i < m; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		connection.push_back({ n1,n2 });
		isConnected[n1] = true;
		isConnected[n2] = true;
	}
	for (int i = 0; i < pos.size(); i++) {
		for (int j = i+1; j < pos.size(); j++) {
			
			if (i == j)continue;
			double dis = sqrt(pow(pos[i].first-pos[j].first,2)+pow(pos[i].second-pos[j].second,2));
			//cout << dis << "\n";
			infos.push_back({ i+1,j+1,dis });
		}
	}
	sort(infos.begin(), infos.end(), Cmp());
}

// 초기화(자신의 조상)
void init() {
	for (int i = 1; i <= n; i++) {
		parents[i] = i;
	}
}

// 정렬


// find
int find(int tar) {
	if (tar == parents[tar])return tar;
	int ret = find(parents[tar]);
	parents[tar] = ret;
	return ret;
}

// setUnion
void setUnion(int t1, int t2) {
	int f1 = find(t1);
	int f2 = find(t2);
	if (f1 == f2)return;
	parents[f2] = f1;
}

// 현재 연결 되어 있는 것 중에서
// 가장 조상을 기준으로 연결
int main() {
	input();
	init();
	int cnt = 0;
	for (int i = 0; i < connection.size(); i++) {
		int n1 = connection[i].first;
		int n2 = connection[i].second;
		if (find(n1) == find(n2))continue;
		if (n1 < n2) {
			setUnion(n1,n2);
		}
		else {
			setUnion(n2, n1);
		}
		cnt++;
	}
	int goal = n - 1;
	if (cnt == goal) {
		cout << 0.00;
		return 0;
	}
	double ans = 0;
	for (auto p : infos) {
		
		int ret1 = find(p.n1);
		int ret2 = find(p.n2);
		if (ret1==ret2) continue;
		setUnion(ret1, ret2);
		cnt++;
		ans += p.dis;
		if (cnt == goal)break;

	}
	cout << fixed;
	cout.precision(2);
	cout << ans;
	return 0;
}
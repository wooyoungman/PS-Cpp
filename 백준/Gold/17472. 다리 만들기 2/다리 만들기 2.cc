// 1. 섬을 구한다 (종류별로 값 다르게)
// 2. 각 섬의 지점에서 다른 섬으로 직선으로 이을 수 있는 다리를 만든다.
// 3. 유니온파인드를 통해 n개의 섬을 잇는다.
// 4. 이 때, MST 방법을 이용하여 최소 연결 비용을 구한다.

#include<iostream>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
int map[11][11];
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
bool visited[11][11];

int num_land;

int parent[7];

struct Bridge {
	int start, end, length;
};

bool compare(Bridge a, Bridge b) {
	return a.length < b.length;
}

vector<Bridge>v;

bool isIndex(int y, int x) {
	return y >= 0 && x >= 0 && y < n && x < m;
}
bool isValid(int y, int x) {
	return isIndex(y,x) && !visited[y][x] && map[y][x] == 1;
}

bool isWater(int y, int x) {
	return isIndex(y,x) && map[y][x] == 0;
}


void bfs(int y,int x) {

	visited[y][x] = true;
	map[y][x] = num_land;
	queue<pair<int, int>>q;
	q.push({ y,x, });
	while (!q.empty()) {
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_y = cur_y + dy[i];
			int next_x = cur_x + dx[i];
			if (!isValid(next_y, next_x))continue;
			visited[next_y][next_x] = true;
			q.push({ next_y,next_x });
			map[next_y][next_x] = num_land;
		}
	}

}

// 상, 하, 좌, 우 1방향에 대해서 격자의 끝까지 가도록 설계 
void make_bridge(int y, int x) {

	int cur_y = y;
	int cur_x = x;
	for (int i = 0; i < 4; i++) {
		int cur_bridge_length = 0;
		int next_y = cur_y + dy[i];
		int next_x = cur_x + dx[i];
		while (isWater(next_y, next_x)) {

			cur_bridge_length++;
			next_y += dy[i];
			next_x += dx[i];
			//cout << next_y << " " << next_x << " " << map[next_y][next_x] << "\n";
		}
		// cur와 next에 해당하는 좌표에 섬의 번호 등록 후 길이 추가
		if (map[next_y][next_x] != map[cur_y][cur_x] && map[next_y][next_x]>0 && cur_bridge_length > 1 && isIndex(next_y,next_x)) {
			v.push_back({ map[cur_y][cur_x],map[next_y][next_x],cur_bridge_length });
			//cout << map[cur_y][cur_x] << " " << map[next_y][next_x] << " " << cur_bridge_length << "\n";
		}
	}
	
}

// 섬의 부모 자기자신으로 초기화 (유니온 파인드)
void init() {
	for (int i = 0; i < 7; i++) {
		parent[i] = i;
	}
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

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	// 1. 섬 번호 붙이기 완료
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]&&map[i][j]==1) {
				num_land++;
				bfs(i, j);
			}
		}
	}

	// 2. 다리 만들기 완료
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != 0) {
				make_bridge(i, j);
			}
		}
	}

	// 3. MST 
	init();

	// 3-1. 다리의 길이가 작은 것 기준으로 정렬 (오름차순)
	sort(v.begin(), v.end(), compare);

	// 3-2. 유니온파인드
	
	int ans = 0;
	// 섬의 개수 -1 만큼의 다리로 연결해야 MST 만족 (사이클 없이)
	int goal_land = num_land - 1;
	int cur_land = 0;
	for (auto p : v) {
		int start = p.start;
		int end = p.end;
		int length = p.length;
		if (find(start) == find(end))continue;
		setUnion(start, end);
		ans += length;
		cur_land++;
		if (cur_land == goal_land)break;
	}

	if (cur_land == goal_land) {
		cout << ans;
	}
	else {
		cout << -1;
	}


	return 0;
}
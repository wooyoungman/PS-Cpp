#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int n, m, t;
int map[101][101];
bool visited[101][101];
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
struct info {
	int y, x;
	bool get_sword;
	int cnt;
};


bool isValid(int y,int x) {
	return y >= 0 && y < n&& x >= 0 && x < m;
}

void func() {
	queue<info>q;
	q.push({ 0,0,false,0 });
	visited[0][0] = true;
	bool arrived = false;
	int ans = 10001;
	bool visited2[101][101] = { false, };
	while (!q.empty()) {
		info now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			bool nget_sword = now.get_sword;
			int ncnt = now.cnt + 1;
			if (ncnt > t)continue;
			if (!isValid(ny,nx))continue;
			if (nget_sword&&!visited2[ny][nx]) {
				q.push({ ny,nx,nget_sword,ncnt });
				visited2[ny][nx] = true;
			}
			else {
				if (map[ny][nx] == 1||visited[ny][nx])continue;
				if (map[ny][nx] == 2) {
					nget_sword = true;
					visited2[ny][nx] = true;
				}
				q.push({ ny,nx,nget_sword,ncnt });
			}
			visited[ny][nx] = true;
			if (ny == n - 1 && nx == m - 1) {
				arrived = true;
				ans = min(ans, ncnt);
			}
		}
	}
	if (!arrived)cout << "Fail";
	else cout << ans;
}

int main() {
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	func();
	return 0;
}
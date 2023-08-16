#include<iostream>
#include<queue>
using namespace std;

int a, b, ans = -1;
void bfs(int v,int c) {

	queue<pair<long, long>>q;
	q.push(make_pair(v, c));
	while (!q.empty()) {
		long cur = q.front().first;
		long cnt = q.front().second;
		q.pop();
		if (cur == b) {
			ans = cnt;
			return;
		}
		if (cur * 10 + 1 <= b) {
			q.push(make_pair(cur * 10 + 1, cnt + 1));
		}
		if (cur * 2 <= b) {
			q.push(make_pair(cur * 2, cnt + 1));
		}
	}
}

int main() {

	cin >> a >> b;
	bfs(a,1);
	cout << ans;
	return 0;
}

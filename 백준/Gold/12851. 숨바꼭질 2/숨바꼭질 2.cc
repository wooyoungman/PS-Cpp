#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int dx[3] = { -1,1,2 };
int dist[100001];
int cnt[100001];
int main() {

	int n, k;
	cin >> n >> k;
	cnt[n] = 1;
	// 1. 수빈이가 동생보다 오른쪽에 있는 경우
	if (n > k) {
		cout << n - k << "\n" << 1;
		return 0;
	}
	// 2. 동일 선상에 존재
	else if (n == k) {
		cout << 0 << "\n" << 1;
		return 0;
	}
	// 3. 수빈이가 동생보다 왼쪽에 있는 경우
	else {
		queue<int>map;
		map.push(n);
		while (!map.empty()) {
			int cur = map.front();
			map.pop();
			vector<int>next;
			next.push_back(cur - 1);
			next.push_back(cur + 1);
			next.push_back(cur * 2);
			for (int i = 0; i < 3; i++) {
				if (next[i] >= 0 && next[i] <= 100000) {
					if (dist[next[i]] == 0) {
						dist[next[i]] = dist[cur] + 1;
						map.push(next[i]);
						cnt[next[i]] = cnt[cur];
					}
					else {
						if (dist[next[i]] > dist[cur] + 1) {
							dist[next[i]] = dist[cur] + 1;
						}
						else if (dist[next[i]] == dist[cur] + 1) {
							cnt[next[i]] += cnt[cur];
						}
					}
				}
			}
		}
		cout << dist[k] << "\n" << cnt[k];
	}
	return 0;
}

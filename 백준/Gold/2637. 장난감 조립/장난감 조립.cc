#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m;

struct Info {
	int out, cnt;
};

vector<Info>infos[101];

// 진입차수
int cnt[101];

// 곱해야되는 초기 개수
int cnt2[101];

// 기본 부품인지 판별
bool isParent[101];
void func() {

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, k;
		cin >> x >> y >> k;
		infos[x].push_back({ y,k });
		cnt[y]++;
		isParent[x] = true;
	}

	queue<int>q;

	q.push(n);
	cnt2[n] = 1;

	while (!q.empty()) {
		// n번 최종 부품부터 시작
		int now = q.front();
		q.pop();
		// 7 5 2, 7 6 3, 7 4 5 탐색
		for (auto p : infos[now]) {
			// 상위 부품 개수 x 만드는데 필요한 하위 부품 개수 추가
			// 7 5 2의 경우 7은 최종 부품 1개, 5의 개수 2개
			// 1*2가 cnt2[5]에 추가 (5를 2개 만들어야한다.)
			cnt2[p.out] += cnt2[now] * p.cnt;

			// 진입 차수 감소 및 0일 때 큐에 추가
			cnt[p.out]--;
			if (cnt[p.out] == 0)q.push(p.out);

		}
	}

	for (int i = 1; i <= n; i++) {
		if (!isParent[i]) {
			cout << i << " " << cnt2[i] << "\n";
		}
	}

}

int main() {
	func();
	return 0;
}
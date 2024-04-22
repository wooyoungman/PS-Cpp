#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int>v[32001];
int cnt[32001];
int n, m;
queue<int>ans;
//
//1 4
//1 5
//2 1
//3 1
// -> 2,3,1, x, x,

//	가장 크기가 작은 녀석인 2가 맨 앞에(크기가 작다는 건 우선순위가 높다는 것)
//	출력 : 2 3 1 4 5
void func() {
	// 일부 학생들의 키만 비교?
	// cnt의 값이 0인 경우 -> 내가 우선순위가 가장 높다
	queue<int>q;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 0) {
			q.push(i);
			ans.push(i);
		}
	}
	while (!q.empty()) {
		// 우선순위가 높은 학생을 세운 후 뒤에 서야 하는 학생들 탐색
		// 현재 앞에 하나의 학생이 섰으므로 cnt 1 감소
		// 만약 cnt가 0이라면 현재 및 정답 큐에 추가
		// cnt가 0이라는 뜻은 자신의 앞에 있어야 할 학생들이 더이상 없으니 내가 서야한다는 뜻
		int now = q.front();
		q.pop();
		for (auto p : v[now]) {
			cnt[p]--;
			if (cnt[p] == 0) {
				q.push(p);
				ans.push(p);
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		// a는 b의 뒤에 있어야 한다라는 뜻
		v[a].push_back(b);
		// b앞에 있어야 할 수의 개수 저장
		cnt[b]++;
	}
	func();
	while (!ans.empty()) {
		cout << ans.front() << " ";
		ans.pop();
	}

	return 0;
}
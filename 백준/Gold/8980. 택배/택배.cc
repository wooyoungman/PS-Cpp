#include<iostream>
#include<algorithm>
using namespace std;

int n, c, m;

struct Info {
	int s, e, num;
};

// 박스 정보
Info infos[10001];

// 마을 용량
int remainAmount[2001];

// 도착 지점이 빠른 순서부터, 같다면 박스 수가 큰 것 부터
bool Cmp(Info a, Info b) {
	if (a.e != b.e) {
		return a.e < b.e;
	}
	return a.num > b.num;
}

void func() {
	cin >> n >> c;
	cin >> m;

	int ans = 0;

	for (int i = 0; i < m; i++) {
		int s, e, num;
		cin >> s >> e >> num;
		infos[i] = { s,e,num };
	}

	sort(infos, infos + m, Cmp);

	// 마을마다 실을 수 있는 최대 무게는 c로 시작
	for (int i = 1; i <= n; i++) {
		remainAmount[i] = c;
	}

	// 박스 순서대로 탐색
	for (int i = 0; i < m; i++) {
		Info now = infos[i];
		// s부터 e-1까지의 마을 모두 실을 수 있는 최대무게 측정
		// 1 : 30, 2: 20, 3: 25의 무게 만큼 실을 수 있을 때 20을 뽑아내는 것!
		int maxWeight = 10001;
		for (int j = now.s; j < now.e; j++) {
			maxWeight = min(remainAmount[j], maxWeight);
		}

		// 현재 택배 박스의 개수를 모두 담아낼 수 있다면
		// s부터 e-1까지 현재 택배 박스의 개수를 빼주고 정답에 최대치를 추가
		if (maxWeight >= now.num) {
			for (int j = now.s; j < now.e; j++) {
				remainAmount[j] -= now.num;
			}
			ans += now.num;
		}

		// 못담아 내면 최대치만 담아내기
		else {
			for (int j = now.s; j < now.e; j++) {
				remainAmount[j] -= maxWeight;
			}
			ans += maxWeight;
		}

	}

	cout << ans;

}

int main() {

	func();

	return 0;
}
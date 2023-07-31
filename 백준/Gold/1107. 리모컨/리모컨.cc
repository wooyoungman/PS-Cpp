#include<iostream>
#include<algorithm>
#include<vector>
#include <string>
using namespace std;

int N, M, cnt;
bool check[10];

// 0부터 100만까지 탐색
void find_num() {
	
	for (int i = 0; i <= 1000000; i++) {
		string s = to_string(i);
		bool check1 = false;
		for (int j = 0; j < s.length(); j++) {
			// i의 각 자리 수가 하나라도 고장나있으면 탐색 중지
			if (!check[s[j] - '0']) {
				check1 = true;
				break;
			}
		}
		if (!check1) {
			// ++혹은 --의 개수인 abs(N-i)와 i를 누르는데 필요한 횟수
			int temp = abs(N - i) + s.length();
			cnt = min(cnt, temp);
		}
	}
}


int main() {

	for (int i = 0; i < 10; i++) {
		check[i] = true;
	}
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;
		check[a] = false;
	}
	if (N == 100) {
		cout << 0;
		return 0;
	}
	// 100이하인 경우 그냥 -만 눌러서 갈 때와 비교하기.
	cnt = abs(100 - N);
	find_num();

	cout << cnt;
	
	return 0;
}
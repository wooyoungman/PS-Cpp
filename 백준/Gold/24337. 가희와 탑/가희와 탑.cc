#include<iostream>
#include<algorithm>
#include<deque>

using namespace std;

int n, a, b;

void func() {

	cin >> n >> a >> b;

	// a와 b가 요구하는 높이의 개수를 먼저 넣는다.
	// 1. 1 ~ (a-1) 까지, 
	// 2. a,b 중 큰 값(해당 높이를 1...x까지라 할 때 x를 넣는것)
	// 3. (b-1)부터 1까지
	// 4. 문제의 요구를 만족했으니 앞에서부터 1을 추가해서 사전순으로 만들기
	deque<int>d;
	for (int i = 1; i <= a - 1; i++) {
		d.push_back(i);
	}
	int maxH = max(a, b);
	d.push_back(maxH);
	for (int i = b - 1; i >= 1; i--) {
		d.push_back(i);
	}
	// 문제 요구 사항을 충족하는 최소 개수가 n을 넘으면 불가능
	if (d.size() > n) {
		cout << -1;
		return;
	}

	// 현재 0번 인덱스는 문제 요구 사항을 만족하는 최소 높이임
	// 따라서 남은 건물의 개수는 그 사이를 1로 채워야 사전 순으로 앞에 올 수 있음
	
	int dSize = d.size();
	int minH = d.front();
	d.pop_front();
	for (int i = 0; i < n - dSize; i++) {
		d.push_front(1);
	}
	d.push_front(minH);

	for (int i = 0; i < d.size(); i++) {
		cout << d[i] << " ";
	}

}

int main() {
	func();
	return 0;
}
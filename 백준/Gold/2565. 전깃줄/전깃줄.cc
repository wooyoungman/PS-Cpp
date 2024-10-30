#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 두 선이 꼬이지 않으려면
// (A1,B1)과 (A2,B2)를 잇는 두 선이 있다고 하자.
// A1 < A2 일 때, B1이 B2보다 작아야한다.
// 그렇다면 A를 오름차순 정렬한 후 
// 이에 매칭되는 B의 값들 중 최장 증가 수열을 구하면 된다.

int n;
int dp[101];
void func() {
	cin >> n;
	vector<pair<int, int>>v;
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		v.push_back({ s,e });
	}
	sort(v.begin(), v.end());
	
	for (int i = 0; i < v.size(); i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			// 현재 i번째 인덱스 앞의 최장 증가 수열을 저장
			if (v[i].second > v[j].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	int maxLine = 0;
	for (int i = 0; i < n; i++) {
		maxLine = max(maxLine, dp[i]);
	}
	cout << n - maxLine;
}

int main() {
	func();
	return 0;
}
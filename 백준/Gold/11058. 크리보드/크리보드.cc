#include<iostream>
#include<algorithm>
using namespace std;

int n;

// ca, cc, cv는 하나의 묶음이다.
// dp[i] = i번째 눌렀을 때 화면 출력 최대값이라고 하자.
// dp[6]의 경우의 수를 생각해보자.
// a만 6번 누르는 경우
// a를 3번 누르고 ca,cc,cv를 누르는 경우
// a를 2번 누르고 ca,cc,cv,cv를 누르는 경우
// a를 1번 누르고 ca,cc,cv,cv,cv를 누르는 경우이다.

// 최초로 3개의 버퍼를 설정한 후 곱하기 2
// 4개 버퍼 곱하기 3
// 5개 버퍼 곱하기 4
// 이런식으로 값을 비교하면 된다.

long long dp[101];

int main() {
	cin >> n;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for (int i = 4; i <= 100; i++) {
		// a만 누르는 경우 먼저 저장
		dp[i] = dp[i - 1] + 1;
		// 붙여넣기 비교
		for (int j = 3; j < i; j++) {
			dp[i] = max(dp[i], dp[i - j] * (j - 1));
		}

	}

	cout << dp[n];
	return 0;
}
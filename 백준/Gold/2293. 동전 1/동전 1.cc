//#include <iostream>
//
//using namespace std;
//
//int costs[101];
//// 최대 100개의 동전을 이용하여
//// 최대 10000을 만드는 경우의 수 
//int dp[101][10001];
//int main() {
//	
//	int n, k;
//	cin >> n >> k;
//	for (int i = 1; i <= n; i++) {
//	
//		cin >> costs[i];
//
//	}
//	
//	dp[0][0] = 1;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 0; j <= k; j++) {
//			if (costs[i] > j) {
//				dp[i][j] = dp[i - 1][j];
//			}
//			else {
//				dp[i][j] = dp[i][j - costs[i]] + dp[i - 1][j];
//			}
//		}
//	}
//
//	cout << dp[n][k];
//
//
//	return 0;
//
//}


// 메모리 초과로 인한 코드 수정

#include <iostream>

using namespace std;

// 최대 100개의 동전을 이용하여
int costs[101];
// 최대 10000을 만드는 경우의 수 
int dp[10001];
int main() {

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {

		cin >> costs[i];

	}

	// n번의 반복문안에서
	// 동전을 하나씩 쓰는 경우를 dp 배열에 누적시킨다.
	// 1원 동전만을 이용하여 값을 만드는 경우
	// 이후, 2원 동전을 추가로 이용하여 값을 만드는 경우
	// 이후, 5원 동전을 추가로 이용하여 값을 만드는 경우

	// dp[j] = dp[j] +dp[j-cost[i]] 
	// 즉, 현재 동전을 안쓰고 이전에 만들었던 경우의 수 +
	// 현재 동전을 추가로 사용하여 만들 수 있는 경우의 수

	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = costs[i]; j <= k; j++) {
			dp[j] += dp[j - costs[i]];
		}
	}

	cout << dp[k];

	return 0;

}
#include<iostream>
#include<cstring>
#include<algorithm>
#include<climits>
#define MAX INT_MAX
using namespace std;

// dp[s][e] = min(dp[s][k] + dp[k+1][e] + sum[s][e])
int num[501];
int psum[501];
int dp[501][501];

// Top-Down 방식으로, 이진 트리에서 엣지 노드에 도달할 시 (s==n) 0 반환
int recur_dp(int s, int e) {
	//cout << "시작 : " << s << " " << e << "\n";
	if (s == e)return 0;
	int ret = dp[s][e];
	if (ret != -1)return ret;
	ret = MAX;
	for (int k = s; k < e; k++) {
		//cout << "ret : " << ret << "\n";
		ret = min(ret, recur_dp(s, k) + recur_dp(k + 1, e) + psum[e] - psum[s - 1]);
		//cout << "중간 : " << s << " " << k << " " <<k+1<<" "<< e << " " << ret << "\n";
	}
	dp[s][e] = ret;
	//cout << s << " " << e << " " << ret << "\n";
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> num[j];
			psum[j] = psum[j - 1] + num[j];
		}
		memset(dp, -1, sizeof(dp));
		cout << recur_dp(1, n) << "\n";
	}

	return 0;
}
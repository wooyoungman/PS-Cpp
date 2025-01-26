#include<iostream>
#include<algorithm>
#include<cmath>
#include<climits>
#define MAX INT_MAX
using namespace std;

int n;
char arr[1001];
int dp[1001];


int main() {

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i] = MAX;
	}
	dp[1] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (dp[i] == MAX)continue;
			if ((arr[i] == 'B' && arr[j] == 'O') || (arr[i] == 'O' && arr[j] == 'J')
				|| (arr[i] == 'J' && arr[j] == 'B')){
				dp[j] = min(dp[j], dp[i] + (int)pow(j - i, 2));
}
		}
	}

	cout << (dp[n] == MAX ? -1 : dp[n]);
	return 0;
}
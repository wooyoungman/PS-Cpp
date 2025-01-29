#include<iostream>
#include<cmath>
using namespace std;

int led[10][7] = {
	{1,1,1,0,1,1,1},
	{0,0,1,0,0,1,0},
	{1,0,1,1,1,0,1},
	{1,0,1,1,0,1,1},
	{0,1,1,1,0,1,0},
	{1,1,0,1,0,1,1},
	{1,1,0,1,1,1,1},
	{1,0,1,0,0,1,0},
	{1,1,1,1,1,1,1},
	{1,1,1,1,0,1,1}
};

int n, k, p, x;

// 1. LED 배열로 표현
// 2. 현채 층수 x와 1~N까지 모든 층수 비교
// 3. LED 반전 횟수 계산

// 35가 주어진 수면 3, 5를 따로 빼내기
int getNum(int number, int idx) {
	return (number / (int)(pow(10, k - idx - 1))) % 10;
}

// 두 숫자의 다른 LED 개수 반환
int countDiff(int a, int b) {
	int cnt = 0;
	for (int i = 0; i < 7; i++) {
		if (led[a][i] != led[b][i])cnt++;
	}
	return cnt;
}

int main() {
	cin >> n >> k >> p >> x;
	int ans = 0;
	// 1~N까지 수와 비교
	for (int i = 1; i <= n; i++) {
		if (i == x)continue;

		int sum = 0;
		// 0부터 k-1자리수 까지 숫자 한개씩 비교
		for (int j = 0; j < k; j++) {
			int num_x = getNum(x, j);
			int num_i = getNum(i, j);
			sum += countDiff(num_x, num_i);
		}
		if (sum >= 1 && sum <= p)ans++;
	}
	cout << ans;
	return 0;
}
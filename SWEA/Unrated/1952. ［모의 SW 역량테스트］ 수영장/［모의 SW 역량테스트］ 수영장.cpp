#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <limits.h>
#include <algorithm>
#define MAX INT_MAX
using namespace std;

int t,ans,depth;
// 1일, 1달, 3달, 12달
int prices[4];

// 각 달 이용 계획 수
int plans[12];

void init() {
	ans = MAX;
	depth = 0;
}

void input() {
	for (int i = 0; i < 4; i++) {
		cin >> prices[i];
	}
	for (int i = 0; i < 12; i++) {
		cin >> plans[i];
		if (plans[i] > 0)depth++;
	}
}

void recur(int level, int sum, int cur) {
	if (level == depth) {
		// 현재 모든 월 수에 대해서 선택 완료
		ans = min(ans, sum);
		//cout << ans << "\n";
		return;
	}
	for (int i = cur; i < 12; i++) {
		if (plans[i] > 0) {
			for (int j = 0; j < 4; j++) {
				
				if (j == 0) {
					sum += plans[i] * prices[j];
					recur(level + 1, sum, i + 1);
					sum -= plans[i] * prices[j];
				}
				else if (j == 1) {
					sum += prices[j];
					recur(level + 1, sum, i + 1);
					sum -= prices[j];
				}
				else if (j == 2) {
					int cnt = 0;
					for (int k = i; k < i + 3; k++) {
						if (plans[k] > 0) {
							cnt++;
						}
					}
					sum += prices[j];
					recur(level + cnt, sum, i + 3);
					sum -= prices[j];
				}
				else {
					sum += prices[j];
					recur(depth, sum, cur);
					sum -= prices[j];
				}
			}
		}
	}
}

int main() {

	//freopen("input.txt", "r", stdin);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		init();
		input();
		recur(0, 0, 0);
		cout << "#" << i << " " << ans << "\n";
	}


	return 0;
}
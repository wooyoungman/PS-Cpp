#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, s;
int nums[21];
int save[21];
int ans;
void check(int cnt) {
	int sum = 0;
	for (int i = 0; i < cnt; i++) {
		sum += save[i];
	}
	if (sum == s) {
		ans++;
	}
}

void recur(int depth,int cur,int cnt) {

	if (depth == cnt) {
		check(cnt);
		return;
	}
	
	for (int i = cur; i < n; i++) {
		save[depth] = nums[i];
		recur(depth + 1, i + 1, cnt);
	}

}

int main() {
	
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	for (int i = 1; i <= n; i++) {
		recur(0, 0, i);
		memset(save, 0, sizeof(save));
	}
	cout << ans;
	return 0;
}
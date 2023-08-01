#include<iostream>
using namespace std;

int n, m = 0;
int arr[1001] = { 0, };
int ans[1001] = { 0, };
int r_ans[1001] = { 0, };

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		ans[i] = 1;
		r_ans[i] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (ans[j] >= ans[i]) {
					ans[i] = ans[j] + 1;
				}
			}
		}
	}

	for (int i = n-1; i >= 0; i--) {
		for (int j = n-1; j > i; j--) {
			if (arr[i] > arr[j]) {
				if (r_ans[j] >= r_ans[i]) {
					r_ans[i] = r_ans[j] + 1;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		m = max(m, ans[i] + r_ans[i] - 1);
	}
	cout << m;
	return 0;
}
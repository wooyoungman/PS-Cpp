#include<iostream>
using namespace std;

int n,m=0;
int arr[1001] = { 0, };
int ans[1001] = { 0, };


int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		ans[i] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (ans[j] >= ans[i]) {
					ans[i] = ans[j] + 1;
				}
			}
		}
		m = max(m, ans[i]);
	}
	cout << m;
	return 0;
}
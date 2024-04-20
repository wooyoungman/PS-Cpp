#include<iostream>

using namespace std;

int t, n;
int arr[10001];
// 1 2 3 4 5 7 8 9 10 11 12 14 
void func() {
	for (int i = 0; i <= 10000; i++) {
		arr[i] = 1;
	}
	for (int i = 2; i <= 10000; i++) {
		arr[i] += arr[i - 2];
	}
	for (int i = 3; i <= 10000; i++) {
		arr[i] += arr[i - 3];
	}
}

int main() {
	cin >> t;

	func();
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << arr[n] << "\n";
	}


	return 0;
}
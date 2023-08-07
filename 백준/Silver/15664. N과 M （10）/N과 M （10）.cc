#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int n, m;
int arr[10], ans[10], check[10];


void print_ans() {
	for (auto p : ans) {
		if(p>0)
		cout << p << " ";
	}
	cout << "\n";
}

void recur(int depth,int x) {
	if (depth == m) {
		print_ans();
		return;
	}

	int prev = 0;
	for (int i = x; i < n; i++) {
		if (prev != arr[i]&&!check[i]) {
			prev = arr[i];
			ans[depth] = arr[i];
			check[i] = true;
			recur(depth + 1, i);
			check[i] = false;
		}
	}

}



int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	recur(0, 0);

	return 0;
}
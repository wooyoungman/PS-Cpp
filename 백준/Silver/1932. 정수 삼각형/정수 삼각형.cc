#include <iostream>
#include <vector>

using namespace std;

int n;
int tree[501][501];
int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i+1; j++) {
			cin >> tree[i][j];
		}
	}
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			tree[i - 1][j] += max(tree[i][j], tree[i][j + 1]);
		}
	}
	cout << tree[0][0];
	return 0;
}
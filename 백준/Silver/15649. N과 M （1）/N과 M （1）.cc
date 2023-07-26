#include <iostream>
using namespace std;

int N, M;
int arr[10];
int ans[10];
bool check[10];

// 출력 함수

void print_ans() {
	for (auto i : ans) {
		if (i != 0) {
			cout << i << " ";
		}
	}
	cout << "\n";
}

// 재귀 함수
void recur(int depth) {

	// 종료 조건
	if (depth == M) {
		print_ans();
		return;
	}

	// 수행 부분
	for (int i = 1; i <= N; i++) {
		if (!check[i]) {
			ans[depth] = arr[i];
			check[i] = true;
			recur(depth + 1);
			check[i] = false;
		}

	}

}





int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		arr[i] = i;
	}
	recur(0);
	return 0;
}
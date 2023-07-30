#include<iostream>
#include<algorithm>
using namespace std;

// 백트래킹
// 재귀함수
// 재귀 구간 -> 깊이
// 탈출 구간
int N, M;
int arr[10];
int ans[10];
bool check[10];
void print_ans() {
	for (auto i : ans) {
		if (i != 0){
			cout << i << " ";
		}
	}
	cout << "\n";
}

void recur(int depth) {

	int prev = 0;
	if (depth == M) {
		print_ans();
		return;
	}
	// 이전 마지막 원소 저장
	for (int i = 0; i < N; i++) {

		if (!check[i]&&prev!=arr[i]) {
			prev = arr[i];
			ans[depth] = arr[i];
			check[i] = true;
			recur(depth + 1);
			check[i] = false;
		}
	}
}


int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	recur(0);
	return 0;
}
#include<iostream>
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

void recur(int depth,int s) {

	if (depth == M) {
		print_ans();
		return;
	}

	for (int i = s; i <= N; i++) {

			ans[depth] = arr[i];
			recur(depth+1,s);
			s += 1;
	}
}


int main() {

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		arr[i] = i;
	}
	recur(0,1);
	return 0;
}
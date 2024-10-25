// A-B 선분 연결
// 교차 점은 A1 < A2, B1 > B2에 발생
// 입력을 모두 받은 후 A의 가장 최소 인덱스부터 진행

#include<iostream>
#define MAX 500500
#define TREE_MAX 2002000
#define ll long long

using namespace std;

int arrA[MAX];
int arrB[MAX * 2];
int tree[TREE_MAX];


int n;

void update(int idx, int node, int left, int right) {
	if (idx<left || idx>right)return;
	else if (left == right) {
		tree[node]++;
		return;
	}
	int mid = (left + right) / 2;
	update(idx, node * 2, left, mid);
	update(idx, node * 2 + 1, mid + 1, right);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll querySum(int node, int start, int end, int left, int right) {
	if (end<left || start>right)return 0;
	else if (left <= start && end <= right)return tree[node];
	int mid = (start + end) / 2;
	return querySum(node * 2, start, mid, left, right) + querySum(node * 2 + 1, mid + 1, end, left, right);
}

void func() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arrA[i];
	}
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		arrB[num] = i;
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += querySum(1, 1, n, arrB[arrA[i]] + 1, n);
		update(arrB[arrA[i]], 1, 1, n);
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	func();

	return 0;
}
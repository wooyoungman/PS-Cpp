#include<iostream>
#include<algorithm>
#include<climits>
#define MAX INT_MAX
using namespace std;

int n, m;
int nums[100001];
int minNums[400001];

// 세그먼트 트리 초기화
void init(int node, int start, int end) {
	if (start == end) {
		minNums[node] = nums[start];
		return;
	}
	int mid = (start + end) / 2;
	init(node * 2, start, mid);
	init(node * 2 + 1, mid + 1, end);
	minNums[node] = min(minNums[node * 2], minNums[node * 2 + 1]);
	return;
}
int findMin(int node, int start, int end, int left, int right) {
	if (left > end || start > right)return MAX;
	// 내가 찾고자 하는 범위(a,b)가 현재 노드의 범위를 포함하면 현재 노드에서의 최소를 반환
	else if (left <= start && right >= end) {
		return minNums[node];
	}
	int mid = (start + end) / 2;
	int l = findMin(node * 2, start, mid, left, right);
	int r = findMin(node * 2 + 1, mid + 1, end, left, right);
	return min(l, r);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	init(1, 1, n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		int ans = findMin(1, 1, n, a, b);
		cout << ans << "\n";
	}

	return 0;
}
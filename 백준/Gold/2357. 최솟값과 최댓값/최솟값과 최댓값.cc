#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#define MAX INT_MAX
using namespace std;

vector<int>nums,maxTree,minTree;
int n, m;

void init(int node, int start, int end) {
	if (start == end) {
		maxTree[node] = nums[start];
		minTree[node] = nums[start];
		return;
	}
	int mid = (start + end) / 2;
	init(node * 2, start, mid);
	init(node * 2 + 1, mid + 1, end);
	minTree[node] = min(minTree[node * 2], minTree[node * 2 + 1]);
	maxTree[node] = max(maxTree[node * 2], maxTree[node * 2 + 1]);
	return;
}

pair<int, int> query(int node, int start, int end, int left, int right) {
	if (left > end || start > right) {
		return { MAX,0 };
	}
	else if (left <= start && right >= end) {
		return { minTree[node],maxTree[node] };
	}
	int mid = (start + end) / 2;
	pair<int, int>l = query(node * 2, start, mid, left, right);
	pair<int, int>r = query(node * 2 + 1, mid + 1, end, left, right);
	return { min(l.first,r.first),max(l.second,r.second) };
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	nums.resize(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	maxTree.resize(4 * n);
	minTree.resize(4 * n);
	init(1, 1, n);
	for (int i = 0; i < m; i++) {
		int left, right;
		cin >> left >> right;
		pair<int, int>ans = query(1, 1, n, left, right);
		cout << ans.first << " " << ans.second << "\n";
	}
	return 0;
}
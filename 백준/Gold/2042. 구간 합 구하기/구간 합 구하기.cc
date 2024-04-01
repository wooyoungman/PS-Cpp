#include<iostream>
#include<vector>
using namespace std;

// 업데이트, 구간합, 
int n, m, k;

long long nums[1000001];
vector<long long>sumTree;
void init(int node,int start,int end){
	if (start == end) {
		sumTree[node] = nums[start];
		return;
	}
	int mid = (start + end) / 2;
	init(node * 2, start, mid);
	init(node * 2 + 1, mid + 1, end);
	sumTree[node] = sumTree[node * 2] + sumTree[node * 2 + 1];
}

void update(int node, int start, int end, long long idx, long long value) {
	if (idx<start || idx>end) {
		return;
	}
	if (start == end) {
		sumTree[node] = value;
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, value);
	update(node * 2 + 1, mid + 1, end, idx, value);
	sumTree[node] = sumTree[node * 2] + sumTree[node * 2 + 1];
}

long long querySum(int node, int start, int end, long long left, long long right) {
	if (end < left || right < start) {
		return 0;
	}
	else if (left<=start && right>=end) {
		return sumTree[node];
	}
	int mid = (start + end) / 2;
	long long leftsum = querySum(node * 2, start, mid, left, right);
	long long rightsum = querySum(node * 2+1, mid+1, end, left, right);
	return leftsum + rightsum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;
	sumTree.resize(4 * n);
	for(int i=1;i<=n;i++){
		cin >> nums[i];
	}
	init(1, 1, n);
	for (int i = 0; i < m + k; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, 1, n, b, c);
		}
		else if (a == 2) {
			cout << querySum(1, 1, n, b, c)<<"\n";
		}
	}
	return 0;
}
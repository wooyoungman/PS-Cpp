#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int>v1;
vector<int>v2;

// 참조자로 넣어야만 함수 호출 시 값 복사를 위한 시간이 발생하지 않는다
int bs(vector<int>&v, int left, int right, int num) {
	while (left < right) {
		int mid = (left + right) / 2;
		if (num > v[mid])left = mid + 1;
		else right = mid;
	}
	return right;
}

void func() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v1.push_back(num);
	}
	v2.push_back(v1[0]);
	
	int idx = 0;

	for (int i = 1; i < n; i++) {
		if (v1[i] > v2[idx]) {
			v2.push_back(v1[i]);
			idx = v2.size() - 1;
		}
		else {
			int pos = bs(v2, 0, idx, v1[i]);
			v2[pos] = v1[i];
		}
	}
	cout << v2.size();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	func();
	return 0;
}
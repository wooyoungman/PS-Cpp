#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int n;
vector<int>v1; // 원본 숫자
vector<int>v2; // LIS 배열
vector<int>v3; // 원본 - LIS 인덱스 관계

int bs(int l, int r, int num) {
	while (l < r) {
		int mid = (l + r) / 2;
		if (num > v2[mid])l = mid + 1;
		else r = mid;
	}
	return r;
}

void func() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v1.push_back(num);
	}
	v2.push_back(v1[0]);
	v3.push_back(0);
	int curSize = 0;
	for (int i = 1; i < n; i++) {
		if (v1[i] > v2[curSize]) {
			v2.push_back(v1[i]);
			curSize = v2.size() - 1;
			v3.push_back(curSize);
		}
		else {
			int pos = bs(0, curSize, v1[i]);
			v2[pos] = v1[i];
			v3.push_back(pos);
		}
	}
	
	cout << v2.size() << "\n";

	// 마지막 인덱스는 v2의 크기 - 1과 같다
	int curIdx = curSize;
	stack<int>ans;
	for (int i = n - 1; i >= 0; i--) {
		if (curIdx < 0)break;
		if (v3[i] == curIdx) {
			ans.push(v1[i]);
			curIdx--;
		}
	}
	
	while (!ans.empty()) {
		cout << ans.top() << " ";
		ans.pop();
	}

}

int main() {
	func();
	return 0;
}
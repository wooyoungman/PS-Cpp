#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

vector<int>input;

bool checkNum(int num) {
	int start_idx = 0;
	int end_idx = input.size() - 1;
	while (start_idx <= end_idx) {
		int mid = (start_idx + end_idx) / 2;
		int mid_num = input[mid];

		// 현재 값이 중간값 보다 작은 경우
		if (num < mid_num) {
			end_idx = mid - 1;
		}
		// 현재 값이 중간값 보다 큰 경우
		else if (num > mid_num) {
			start_idx = mid + 1;
		}
		// 같은 경우
		else return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int input_num;
		cin >> input_num;
		input.push_back(input_num);
	}

	sort(input.begin(), input.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		int input2_num;
		cin >> input2_num;
		if (checkNum(input2_num))cout << 1<<" ";
		else cout << 0<<" ";
	}

	return 0;
}
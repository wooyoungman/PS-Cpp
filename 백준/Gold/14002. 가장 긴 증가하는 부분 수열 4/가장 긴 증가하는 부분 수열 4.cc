#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
int arr[1001];
int ans[1001];
int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		ans[i] = 1;
	}

	for (int i = 1; i < n; i++) {
	
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (ans[i] <= ans[j]) {
					ans[i] = ans[j] + 1;
				}
			}
		}

	}
	// 1 2 1 3 2 4
	int ans_max = *max_element(ans, ans + 1001);
	cout << ans_max<<"\n";
	int ans_maxidx = max_element(ans, ans + 1001)-ans;
	
	vector<int>ans_v;
	
	ans_v.push_back(arr[ans_maxidx]);

	int now_max = ans[ans_maxidx];
	for (int i = ans_maxidx - 1; i >= 0; i--) {
		if (ans[i] == now_max - 1) {
			ans_v.push_back(arr[i]);
			now_max--;
		}
	}

	for (int i = ans_v.size() - 1; i >= 0; i--) {
		cout << ans_v[i]<<" ";
	}

	return 0;
}
#include<iostream>
#include<vector>
using namespace std;

int n;

void func() {

	cin >> n;
	vector<pair<int, int>>ansIdx;
	long long ansSum = 0;
	for (int i = 0; i < n; i++) {
		int l;
		cin >> l;
		int nums[1001] = { 0, };
		// 개수, 누적합 
		vector<pair<int, int>>v;
		for (int j = 0; j < l; j++) {
			cin >> nums[j];
			// 맨 첫번째 보석은 그대로 넣기
			if (j == 0)v.push_back({ 1,nums[j] });
			else {
				// 현재 보석으로 누적 합을 이어가는게 더 큰 경우
				if (v[j - 1].second + nums[j] > nums[j]) {
					v.push_back({ v[j - 1].first + 1, v[j - 1].second + nums[j]});
				}
				// 현재 보석으로 누적 합을 새로 시작하는게 더 큰 경우
				else {
					v.push_back({ 1,nums[j] });
				}
			}
		}
		
		// 최대가 되는 위치 구하기
		int idx = 0;
		int cnt = v[idx].first;
		int maxSum = v[idx].second;
		for (int j = 1; j < v.size(); j++) {
			// 최대가 더 큰 경우를 찾았을 때
			if (v[j].second >= maxSum) {
				// 구간의 길이(보석의 개수가 같거나 많으면 진행 x)
				if(v[j].second==maxSum && (v[j].first>=cnt))continue;
				
				// 갱신
				idx = j;
				cnt = v[j].first;
				maxSum = v[j].second;
			}
		}
		ansIdx.push_back({ idx - cnt + 2,idx + 1 });
		ansSum += maxSum;
	}
	cout << ansSum << "\n";
	for (auto p : ansIdx) {
		cout << p.first << " " << p.second << "\n";
	}
}

int main() {
	func();
	return 0;
}
#include<iostream>
#include<queue>
using namespace std;

// 비용이 최소가 되려면 작은 비용의 파일을 가장 먼저 합쳐 임시파일로 생성한다
// -> 2개의 작은 원소부터 합치기 (최소 힙)
// 시간 복잡도 : T log(100만), 답의 최대 범위 : 100만 x 1만 = 100억 -> long long
int t, k;

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> k;
		priority_queue<long long,vector<long long>,greater<>>pq;
		for (int j = 0; j < k; j++) {
			int num;
			cin >> num;
			pq.push(num);
		}
		long long sum = 0;
		while (!pq.empty()) {
			long long num1 = pq.top();
			pq.pop();
			if (pq.empty()) {
				break;
			}
			else {
				long long num2 = pq.top();
				pq.pop();
				sum += (num1 + num2);
				pq.push(num1 + num2);
			}
		}
		cout << sum<<"\n";
	}
	return 0;
}
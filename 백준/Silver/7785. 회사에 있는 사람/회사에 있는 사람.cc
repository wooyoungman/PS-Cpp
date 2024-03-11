#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

int n;

// 상태가 leave면 회사에 없는거

unordered_map<string, string>m;
priority_queue<string>pq;
int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		m[a] = b;
	}
	for (auto p : m) {
		if (p.second == "enter") {
			pq.push(p.first);
		}
	}
	int pq_size = pq.size();
	for (int i = 0; i < pq_size; i++) {
		cout << pq.top() << "\n";
		pq.pop();
	}
	return 0;
}
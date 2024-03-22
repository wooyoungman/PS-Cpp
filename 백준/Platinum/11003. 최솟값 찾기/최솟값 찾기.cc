#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, l;
struct info {
	int num, pos;
};

struct cmp {
	bool operator()(info a, info b) {
		return a.num > b.num;
	}
};

priority_queue<info,vector<info>,cmp>pq;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		pq.push({ num,i });
		int pos = pq.top().pos;
		while (pos < i - l + 1) {
			pq.pop();
			pos = pq.top().pos;
		}
		cout << pq.top().num << " ";
	}
	
	return 0;
}
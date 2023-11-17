#include<iostream>
#include<queue>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10,n,v;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		queue<int>q;
		cin >> n;
		for (int i = 0; i < 8; i++) {
			cin >> v;
			q.push(v);
		}
		int cnt = 1;
		while (1) {
			int cur = q.front() - cnt;
			q.pop();
			if (cur <= 0)break;
			cnt++;
			q.push(cur);
			if (cnt > 5)cnt = 1;
		}
		q.push(0);
		cout << "#" << test_case << " ";
		while (!q.empty()) {
			cout << q.front() << " ";
			q.pop();
		}
		cout << "\n";
	}
	return 0;
}
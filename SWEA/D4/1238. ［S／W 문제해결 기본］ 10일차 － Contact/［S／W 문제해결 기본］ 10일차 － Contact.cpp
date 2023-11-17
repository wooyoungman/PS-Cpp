#include<iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 101
vector<int>arr[MAX];
int depth[MAX];


void bfs(int start_p) {
	queue<int>q;
	q.push(start_p);
	depth[start_p] = 1;
	while (!q.empty()) {
		int cur_from = q.front();
		q.pop();
		for (int i = 0; i < arr[cur_from].size(); i++) {
			int cur_next = arr[cur_from][i];
			if (depth[cur_next] == 0) {
				depth[cur_next] = depth[cur_from] + 1;
				q.push(cur_next);
			}
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T=10;
	
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, start;
		cin >> n >> start;
		for (int i = 1; i < MAX; i++) {
			arr[i].clear();
			depth[i] = 0;
		}

		for (int i = 0; i < n / 2; i++) {
			int from, to;
			cin >> from >> to;
			arr[from].push_back(to);
		}
		bfs(start);
		int answer = start;
		for (int i = 1; i < MAX; i++) {
			if (depth[i] >= depth[answer])answer = i;
		}
		cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;
}
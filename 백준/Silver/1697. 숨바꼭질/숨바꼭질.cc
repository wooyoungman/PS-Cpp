#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>

using namespace std;
int n, k;
bool visitied[100001];
// 처음에 단순 계산으로 풀려고 했지만....
// 결국 검색하고 BFS방법으로 풀기로 하였다.
// 모든 좌표로 이동하는 경우의 수를 탐색하여
// 각 좌표당 이동 시간도 같이 넣어주어 먼저 방문한 경우가 짧은 시간임을 표시한다.

void bfs(int x)
{
	visitied[x] = true;
	queue<pair<int, int>>q;
	q.push(make_pair(x, 0));
	while (!q.empty())
	{
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (cur == k)
		{
			cout << cnt;
			break;
		}
		else
		{
			if ((cur + 1 >= 0) && (cur + 1 <= 100000)&&visitied[cur+1]==false)
			{
				
				visitied[cur + 1] = true;
				q.push(make_pair(cur + 1, cnt + 1));

			}
			if ((cur - 1 >= 0) && (cur - 1 <= 100000)&&visitied[cur - 1] == false)
			{
				visitied[cur - 1] = true;
				q.push(make_pair(cur - 1, cnt + 1));
			}
			if ((2*cur >= 0) && (2*cur <= 100000)&&visitied[2*cur] == false)
			{
				visitied[2*cur] = true;
				q.push(make_pair(2*cur, cnt + 1));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	bfs(n);
	return 0;
}
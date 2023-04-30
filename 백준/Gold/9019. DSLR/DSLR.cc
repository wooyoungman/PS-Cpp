#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>
#include<map>
#include<string>
#include<cstring>
using namespace std;

int a,b;
bool visited[10001];

void bfs()
{
	// 입력된 정수 a와 DSLR 명령어 누적
	queue<pair<int, string>>q;
	q.push(make_pair(a, ""));
	visited[a] = true;

	while (!q.empty())
	{
		int cur_num = q.front().first;
		string cur_s = q.front().second;
		q.pop();

		if (cur_num == b)
		{
			cout << cur_s << "\n";
			return;
		}

		int D, S, L, R;
		D = (cur_num * 2) % 10000;
		if (!visited[D])
		{
			visited[D] = true;
			q.push(make_pair(D, cur_s + "D"));
		}
		// 현재 값이 0이면 9999 아니면 1 빼주기
		S = cur_num == 0 ? 9999 : cur_num - 1;
		if (!visited[S])
		{
			visited[S] = true;
			q.push(make_pair(S, cur_s + "S"));
		}
		L = (cur_num / 1000) + (cur_num % 1000) * 10;
		if (!visited[L])
		{
			visited[L] = true;
			q.push(make_pair(L, cur_s + "L"));
		}
		R = (cur_num / 10) + (cur_num % 10) * 1000;
		if (!visited[R])
		{
			visited[R] = true;
			q.push(make_pair(R, cur_s + "R"));
		}
	}
}




int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> a >> b;
		memset(visited, false, sizeof(visited));
		bfs();
	}
	return 0;
}

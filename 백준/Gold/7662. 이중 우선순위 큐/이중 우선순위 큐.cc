#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>

using namespace std;
bool visited[1111111];
// 우선순위큐는 기본적으로 내림차순
// q1은 내림차순, q2는 오름차순
// 유효하지 않은 숫자들을 모두 pop합니다.(다른 힙에서 pop된 숫자가 현재 힙의 top에 있을 수 있으므로)
// 이러한 허수를 처리하는 부분에 있어서 생각을 못했기 때문에 계속 틀렸었음.. 1번 큐에서 없어진 수는 2번 큐에서도 없어져야함
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t, k, num;
	char c;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> k;
		priority_queue<pair<int,int>>q1;
		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q2;
		int cnt = 0;
		for (int j = 0; j < k; j++)
		{
			cin >> c >> num;;
			if (c == 'I')
			{
				q1.push(make_pair(num,j));
				q2.push(make_pair(num,j));
				visited[j] = true;
			}
			else
			{
				if (num == 1)
				{
					// 허수들 제거하는 부분 
					while (!q1.empty() && !visited[q1.top().second])
					{
						q1.pop();
					}
					if (!q1.empty())
					{
						visited[q1.top().second] = false;
						q1.pop();
					}
				}
				else
				{
					// 허수들 제거하는 부분 
					while (!q2.empty() && !visited[q2.top().second])
					{
						q2.pop();
					}
					if (!q2.empty())
					{
						visited[q2.top().second] = false;
						q2.pop();
					}
				}
			}
		}
		while (!q1.empty() && !visited[q1.top().second])
		{
			q1.pop();
		}

		while (!q2.empty() && !visited[q2.top().second])
		{
			q2.pop();
		}
		if (q1.empty()&&q2.empty())
		{
			cout << "EMPTY" << "\n";
		}
		else
		{
			cout << q1.top().first << ' ' << q2.top().first << "\n";
		}
	}
	return 0;
}

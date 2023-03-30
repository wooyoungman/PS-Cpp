#include <iostream>
#include <queue>

using namespace std;
int n, k;
queue<int>q;
int main()
{
	cin >> n >> k;
	int idx = 0;
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}
	cout << '<';
	for (int i = 0; i < n; i++)
	{
		// k 번째 앞에 존재하는 원소들 뒤로 보내기
		for (int j = 0; j < k-1; j++)
		{
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
		if (i != n - 1)
		{
			cout << ", ";
		}
		q.pop();
	}
	cout << '>';
	return 0;
}
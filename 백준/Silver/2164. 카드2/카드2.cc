#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int a,b,ga,gb;


int main()
{
	int n;
	cin >> n;
	queue<int>q;
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}
	while (1)
	{
		if (q.size() == 1)
		{
			break;
		}
		q.pop();
		q.push(q.front());
		q.pop();
	}
	cout << q.front();
	return 0;
}

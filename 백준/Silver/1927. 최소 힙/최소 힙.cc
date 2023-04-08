#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
int arr[2200][2200];
int cnt[3];
priority_queue<int, vector<int>, greater<>>q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (num != 0)
		{
			q.push(num);
		}
		else
		{
			if (q.empty())
			{
				cout << 0 << "\n";
			}
			else
			{
				cout << q.top() << "\n";
				q.pop();
			}
		}

	}
	return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef struct {
	int height;
	int weight;
}profile;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,cnt=1;
	cin >> n;
	profile* arr = new profile [n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].weight >> arr[i].height;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i].height < arr[j].height && arr[i].weight < arr[j].weight)
			{
				cnt++;
			}
		}
		cout << cnt << ' ';
		cnt = 1;
	}
	return 0;
}
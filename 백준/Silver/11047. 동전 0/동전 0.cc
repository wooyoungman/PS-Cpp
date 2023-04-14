#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>

using namespace std;
int money[11];
int main()
{
	vector<int>ans;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k,num,temp=0,cnt_1=0,cnt_2=0;
	bool check = false;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		money[i] = num;
		if (money[i] >= k)
		{
			check = true;
			temp = i;
		}
	}
	if (check == false)
	{
		temp = n - 1;
	}
	while (k > 0)
	{
		cnt_1 += k / money[temp];
		cnt_2 = k / money[temp];
		k -= money[temp]*cnt_2;
		temp--;
	}
	cout << cnt_1;
	return 0;
}

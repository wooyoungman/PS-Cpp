#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int>v;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	v.push_back(1);
	v.push_back(2);
	for (int i = 2; i < n; i++)
	{
		v.push_back((v[i - 1] + v[i - 2])%10007);
	}
	cout << v[n - 1];
	return 0;
}
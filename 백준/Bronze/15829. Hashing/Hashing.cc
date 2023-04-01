#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int l;
	long long sum = 0,r=1;
	string s;
	cin >> l >> s;
	for (int i = 0; i < l; i++)
	{
		// a의 아스키 값 97 이용

		sum+= ((int(s[i]) - 96) * r)%1234567891;
		r = (r * 31)%1234567891;
	}
	cout << sum;
	return 0;
}

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int l;
	long long sum = 0;
	string s;
	cin >> l >> s;
	for (int i = 0; i < l; i++)
	{
		// a의 아스키 값 97 이용
		long long q = (long long)pow(31, i)%1234567891;
		sum+= (int(s[i]) - 96) * q;
	}
	cout << sum;
	return 0;
}

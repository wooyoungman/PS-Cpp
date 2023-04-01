#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int l;
	unsigned int sum = 0;
	string s;
	cin >> l >> s;
	for (int i = 0; i < l; i++)
	{
		// a의 아스키 값 97 이용
		unsigned int q = (unsigned int)pow(31, i);
		sum+= (int(s[i]) - 96) * q;
		sum %= 1234567891;
	}
	cout << sum;
	return 0;
}

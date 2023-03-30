#include <iostream>

using namespace std;

int a, b, c;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (1)
	{
		cin >> a >> b >> c;
		if (a==b&&b==c&&a==0)
		{
			break;
		}
		if ((((a * a) + (b * b)) == (c * c)) || (((a * a) + (c * c)) == (b * b)) || (((b * b) + (c * c)) == (a * a)))
		{
			cout << "right"<<"\n";
		}
		else
		{
			cout << "wrong"<<"\n";
		}
	}
	return 0;
}
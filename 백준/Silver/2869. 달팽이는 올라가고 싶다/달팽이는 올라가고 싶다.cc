#include <iostream>
using namespace std;
int main()
{
	int a, b, v;
	cin >> a >> b >> v;
	int one_day_up = a - b;
	int final_up_day = (v-a) / one_day_up;
	int final_up_rest = (v - a) % one_day_up;
	if (final_up_rest == 0)
	{
		cout << final_up_day + 1;
	}
	else
	{
		cout << final_up_day + 2;
	}
	return 0;
}
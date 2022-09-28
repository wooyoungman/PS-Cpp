#include <iostream>
#include <vector>
using namespace std;

// self 함수를 만들어 1~10000까지 생성자를 갖고와 그에 해당하는 셀프넘버를 만들고
// bool 배열을 이용해 유무를 참거짓으로 판별 후 0인 자리 인덱스 출력

int func(int a)
{
	int selfnum = a;
	while (a > 0)
	{
		selfnum += a % 10;
		a /= 10;
	}
	return selfnum;
}
int main()
{
	bool a[10001] = { 0 };
	for (int i = 0; i < 10001; i++)
	{
		if (func(i) <= 10000)
		{
			a[func(i)] = 1;
		}
	}
	for (int i = 0; i < 10001; i++)
	{
		if (a[i] != 1)
		{
			cout << i << endl;
		}
	}
	return 0;
}
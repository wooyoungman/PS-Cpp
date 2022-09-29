#include <iostream>
using namespace std;
// 시간초과가 계속해서 발생하여 
// 아이디어를 검색해보았더니 에라토스테네스의 체의 개념을 이용하였다.
// 이는 소수의 개념을 잘 이용한 것인데 소수란 약수가 자기자신과 1밖에 존재하지 않는 수이다.
// 그렇다면 어떤 수의 배수는 소수가 될 수 없다.
// ex) 2의 배수, 3의 배수 .....

int check[1000001]; // 전역 변수로 배열 0초기화 소수가 아니면 1로

void func(int m, int n)
{
	// 0과 1은 소수가 아님
	check[0] = 1;
	check[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		// i가 2이면 2의배수 3이면 3의배수
		// 2와 3은 소수로 처음에 판단하고 첫 배수인 4부터 판단한다
		// q는 i만큼 증가시켜 i*2, i*3 i*4 ... 로 i의 배수가 된다
		for (int q = i * 2; q <= n; q += i)
		{
			check[q] = 1;
		}
	}
	for (int w = m; w <= n; w++)
	{
		if (check[w] == 0)
		{
			cout << w << "\n";
		}
	}
}

int main()
{
	int m, n;
	cin >> m >> n;
	func(m, n);
	return 0;
}
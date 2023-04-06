#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// DP 문제를 푸는 방법은 크게 2가지 이다.
// Top-down과 Bottom-up이다.
// Top-down은 가장 큰 문제를 방문 후 작은 문제를 호출하여 답을 찾는 방식이다.
// Bottom-up은 가장 작은 문제들 부터 답을 구해가며 전체 문제의 답을 찾는 방식이다.
// Top-down은 재귀 호출, Bottom up은 반복문을 이용해 구한다.
// Top-down은 점화식을 이해하기 쉽다는 장점이 있지만, Bottom-up은 메모리 사용량과 시간을 줄이 수 있다는 장점이 있다.
int v[1000002];
int main()
{

	int n;
	cin >> n;
	v[0] = 0;
	v[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		v[i] = v[i - 1] + 1;
		if (i % 3 == 0)
		{
			v[i] = min(v[i], v[i / 3] + 1);
		}
		if (i % 2 == 0)
		{
			v[i] = min(v[i], v[i / 2] + 1);
		}
	}
	cout << v[n];
	return 0;
}

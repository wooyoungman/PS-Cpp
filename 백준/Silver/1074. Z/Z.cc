#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int n, r, c, cnt = 0;


// 대표적인 분할정복 재귀함수 형태이므로 꼭 외우자
void recursion(int x, int y, int length)
{
	if (x == c && y == r)
	{
		cout << cnt;
		return;
	}
	else
	{
		// 해당 범위에 (c,r)이 존재하지 않으면 탐색 x 
		if (!(x <= c && x + length > c && y <= r && y + length > r))
		{
			cnt+=length*length;
			return;
		}
		else
		{
			recursion(x, y, length/2);
			recursion(x+length/2, y, length / 2);
			recursion(x, y+length/2, length / 2);
			recursion(x+length/2, y+length/2, length / 2);
		}
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    // 이 문제는 분할정복을 대표하는 문제로 볼 수 있다.
	// 정사각형 영역을 원하는 좌표가 있을 때 까지
	// 4등분으로 계속 쪼개준다.
	// 모든 영역을 탐색하지 않고, 
	// 해당 영역에서 원하는 좌표가 없다면
	// 그 전체의 수만큼 증가시켜주기만 한다.
	cin >> n >> r >> c;
	recursion(0, 0, 1 << n);
	return 0;
}
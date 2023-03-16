#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

vector <long long>tree_high;

// 꼭 다시 풀어보기 이진 탐색 활용 문제로 아주 좋은거같음!

int main() {
	
	long long n, m, temp, high, max_high;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> high;
		tree_high.push_back(high);
	}
	// 최대 높이를 가진 나무의 중간값으로 시작하여
	// 각 나무들에서 구할 수 있는 나무 자재 높이들의 합을 구하여
	// 범위를 조절해 나가면 된다.
	long long right = *max_element(tree_high.begin(), tree_high.end());
	int left = 0;
	long long mid;
	while (left <= right)
	{
		temp = 0;
		mid = (left + right) / 2;
		for (int i = 0; i < n; i++)
		{
			if (tree_high[i] - mid > 0)
			{
				temp += (tree_high[i] - mid);
			}
		}
		if (temp >= m)
		{
			max_high = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	cout << max_high;
	return 0;
}
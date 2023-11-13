#include<iostream>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int cnt;

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		int answer = 0;
		int arr[100] = { 0, };
		cin >> cnt;
		for (int i = 0; i < 100; i++) {
			cin >> arr[i];
		}
		// 최대, 최소 높이 저장
		int max_high = *max_element(arr, arr + 100);
		int min_high = *min_element(arr, arr + 100);

		// 최대, 최소 높이 인덱스 저장
		int max_high_idx = max_element(arr, arr + 100) - arr;
		int min_high_idx = min_element(arr, arr + 100) - arr;

		// 두 차이가 1또는 0이면 종료
		while (max_high - min_high > 1) {
			arr[max_high_idx] -= 1;
			arr[min_high_idx] += 1;
			max_high = *max_element(arr, arr + 100);
			min_high = *min_element(arr, arr + 100);
			max_high_idx = max_element(arr, arr + 100) - arr;
			min_high_idx = min_element(arr, arr + 100) - arr;
			cnt--;
			if (cnt == 0)break;
		}
		answer = max_high - min_high;
		cout << "#" << test_case << " " << answer<<"\n";
		
	}
	return 0;
}
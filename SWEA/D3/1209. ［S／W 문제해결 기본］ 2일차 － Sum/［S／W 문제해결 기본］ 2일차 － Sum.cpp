#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int n;
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		cin >> n;
		int arr[100][100];
		int sum = 0;
		int answer = 0;
		for (int i = 0; i < 100; i++) {
			sum = 0;
			for (int j = 0; j < 100; j++) {
				cin >> arr[i][j];
				sum += arr[i][j];
			}
			answer = max(sum, answer);
		}
		for (int i = 0; i < 100; i++) {
			sum = 0;
			for (int j = 0; j < 100; j++) {
				sum += arr[j][i];
			}
			answer = max(sum, answer);
		}
		int cross1_sum = 0;
		int cross2_sum = 0;
		for (int i = 0; i < 100; i++) {
			cross1_sum += arr[i][i];
			cross2_sum += arr[i][99 - i];
		}
		answer = max(max(answer, cross1_sum), cross2_sum);
		cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;
}
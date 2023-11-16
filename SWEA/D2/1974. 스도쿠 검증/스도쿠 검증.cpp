#include<iostream>

using namespace std;
int arr[9][9] = { 0, };

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		// 합이 45이면 OK
		int answer = 1;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cin >> arr[i][j];
			}
		}
		
		for (int i = 0; i < 9; i++) {
			int sum_row = 0;
			int sum_col = 0;
			for (int j = 0; j < 9; j++) {
				sum_row += arr[i][j];
				sum_col += arr[j][i];
			}
			if (sum_row != 45 || sum_col != 45) answer = 0;
		}

		for (int i = 0; i < 9; i += 3) {
			for (int j = 0; j < 9; j+=3) {
				int sum_part = 0;
				for (int k = i; k < i + 3; k++) {
					for (int l = j; l < j + 3; l++) {
						sum_part += arr[k][l];
					}
				}
				if (sum_part != 45) answer = 0;
			}
		}
		cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;
}

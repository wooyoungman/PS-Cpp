#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T,n;
	
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;
		int size = n;
		int arr[10][10] = { 0, };
		int low = 0, col = -1, dir = 1, val = 1;
		while (size > 0) {
			// 동 남 서 북으로 진행, (동,남) -> +, (서,북) -> -, 동,서 지나면 사이즈-1
			for (int i = 0; i < size; i++) {
				col += dir;
				arr[low][col] = val++;
			}
			size--;
			for (int i = 0; i < size; i++) {
				low += dir;
				arr[low][col] = val++;
				
			}
			dir *= -1;
		}

		cout << "#" << test_case << "\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j == n - 1) {
					cout << arr[i][j] << "\n";
				}
				else {
					cout << arr[i][j] << " ";
				}
			}
		}
	}
	return 0;
}
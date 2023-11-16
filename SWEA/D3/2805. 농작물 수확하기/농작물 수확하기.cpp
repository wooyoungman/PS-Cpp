#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T,n;
	
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int arr[50][50] = { 0, };
		int answer = 0;
		cin >> n;
		string s;
		for (int i = 0; i < n; i++) {
			cin >> s;
			for (int j = 0; j < n; j++) {
				arr[i][j] = s[j] - '0';
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if ((i < n / 2 && j < n / 2 && (i + j) < n / 2) ||
					(i < n / 2 && j > n / 2 && (j - i) > n / 2) ||
					(i > n / 2 && j < n / 2 && (i - j) > n / 2) ||
					(i > n / 2 && j > n / 2 &&( i+j) >= n + n / 2)) continue;
				answer += arr[i][j];
				}
		}
		cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;
}
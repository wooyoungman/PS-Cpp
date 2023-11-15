#include<iostream>
#include <stdio.h>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T, n, m;

	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n >> m;
		int arr[15][15] = { 0, };
		int answer = 0,sum=0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i <= n - m; i++) {
			for (int j = 0; j <= n - m; j++) {
				sum = 0;
				for (int k = i; k < i + m; k++) {
					for (int l = j; l < j + m; l++) {
						sum += arr[k][l];
					}
				}
				answer = max(sum, answer);
			}
		}
		cout <<"#"<< test_case<<" "<<answer<<"\n";
	}
	return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;
string a, b;
int length[1001][1001];

int main() {

	cin >> a;
	cin >> b;

	int a_length = a.length();
	int b_length = b.length();

	for (int i = 0; i < a_length; i++) {
		for (int j = 0; j < b_length; j++) {
			if (a[i] == b[j]) {
				length[i+1][j+1] = length[i][j] + 1;
			}
			else {
				length[i+1][j+1] = max(length[i+1][j], length[i][j+1]);
			}
		}
	}

	cout << length[a_length][b_length];
	return 0;
}
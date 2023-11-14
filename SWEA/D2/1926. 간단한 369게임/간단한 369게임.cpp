#include<iostream>
#include<string>
// int -> string : to_string
// string -> int : stoi
// char* -> int : atoi 
using namespace std;

int main(int argc, char** argv)
{
	int n;
	cin >> n;
	string arr[1001];
	for (int i = 1; i <= n; i++) {
		arr[i] = to_string(i);
		int cnt = 0;
		for (int j = 0; j < arr[i].size(); j++) {
			if (arr[i][j] == '3' || arr[i][j] == '6' || arr[i][j] == '9') {
				cnt++;
			}
		}
		if (cnt == 0) {
			
			cout << arr[i] << " ";
			
		}
		else {
			for (int k = 0; k < cnt; k++) {
				cout << "-";
			}
			cout << " ";
		}
	}

	return 0;
}
#include<iostream>
#include<algorithm>
#include<climits>
#include<string>
using namespace std;


int main() {

	string n;
	cin >> n;
	sort(n.begin(), n.end(),greater<>());
	int sum = 0;
	for (int i = 0; i < n.length(); i++) {
		sum += (n[i] - '0');
	}
	if (sum % 3 != 0) {
		cout << -1;
		return 0;
	}
	else {
		if (n[n.length()-1] != '0') {
			cout << -1;
			return 0;
		}
		cout << n;
	}
	return 0;
}
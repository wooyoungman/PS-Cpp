#include<iostream>

using namespace std;

int a, b, c;

long long f(long long x) {
	if (x == 0) return 1;
	if (x == 1) return a % c;

	long long k = f(x / 2) % c;
	if (x % 2 == 0) return k * k % c;
	else return k * k % c * a % c;
}

int main() {

	cin >> a >> b >> c;
	cout<< f(b);

	return 0;
}
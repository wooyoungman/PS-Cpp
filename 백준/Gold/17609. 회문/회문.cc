#include<iostream>

using namespace std;

int n;
string sen;
int ans;
void func(int s, int e, int del_c) {
	while (s < e) {
		if (sen[s] == sen[e]) {
			s++;
			e--;
		}
		else {
			// 이미 문자를 제거 한 경우
			if (del_c > 0) {
				if(ans==-1)ans = 2;
				return;
			}
			func(s + 1, e, 1);
			func(s, e - 1, 1);
			return;
		}
	}
	ans = del_c;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> sen;
		ans = -1;
		func(0, sen.length() - 1, 0);
		cout << ans << "\n";
	}
	return 0;
}
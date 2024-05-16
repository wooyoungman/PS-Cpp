// 0번을 누를때 안누를때
// 이후, 1번 부터 자신의 앞 스위치를 눌러야 하는지 말아야 하는지 판단

#include<iostream>
#include<climits>
#define MAX INT_MAX
using namespace std;
int n;
int ans = MAX;
string s1, s2;
void switchOn(bool first_on) {
	string temp = s1;
	int cnt = 0;
	if (first_on)cnt = 1;
	for (int i = 1; i < n; i++) {
		if (temp[i - 1] != s2[i - 1]) {
			temp[i - 1] = s2[i - 1];
			if (temp[i] == '0')temp[i] = '1';
			else temp[i] = '0';
			if (i < n - 1) {
				if (temp[i + 1] == '0')temp[i+1] = '1';
				else temp[i+1] = '0';
			}
			cnt++;
		}
	}
	if (temp == s2)ans = min(ans, cnt);
}

void func() {
	
	cin >> s1 >> s2;
	char first = s1[0];
	char second = s1[1];
	// 0번을 누를 때
	for (int i = 0; i < 2; i++) {
		if (s1[i] == '0')s1[i] = '1';
		else s1[i] = '0';
	}
	switchOn(true);
	// 0번을 안누를 때6
	s1[0] = first;
	s1[1] = second;
	switchOn(false);
	if (ans == MAX)cout << -1;
	else cout << ans;
}
int main() {
	cin >> n;
	func();
	return 0;
}
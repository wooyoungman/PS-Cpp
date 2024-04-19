
// 문자열 S의 뒤에 A를 추가
// 문자열 S의 뒤에 B를 추가 후 뒤집기

#include<iostream>
#include<string>
#include<queue>
using namespace std;

string s, t;
int ans;
// t->s로 구하기
void func() {
	queue<string>q;
	q.push(t);
	while (!q.empty()) {
		string now = q.front();
		q.pop();
		if (now == s) {
			ans = 1;
			return;
		}

		// A를 추가한 경우 -> 끝이 A일 때
		if (now[now.length() - 1] == 'A') {
			string temp = now.substr(0, now.length()-1);
			q.push(temp);
		}
		// B를 추가한 경우 -> 시작이 B일 때 
		if (now[0] == 'B') {
			string temp = "";
			for (int i = now.length() - 1; i > 0; i--) {
				temp += now[i];
			}
			q.push(temp);
		}
	}

}
int main() {
	cin >> s >> t;
	func();
	cout << ans;
	return 0;
}
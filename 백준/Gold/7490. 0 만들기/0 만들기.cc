#include<iostream>
#include<string>
#include<vector>
using namespace std;

int t, n;
char nums[11] = {'0', '1','2','3','4','5','6','7','8','9' };
char oper[3] = { ' ','+','-' };

bool print(string s) {
	vector<int>v;
	int cur = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '+') {
			v.push_back(cur);
			cur = 0;
			v.push_back(-1);
		}
		else if (s[i] == '-') {
			v.push_back(cur);
			cur = 0;
			v.push_back(-2);
		}
		else {
			cur *= 10;
			cur += s[i] - '0';
			if (i == s.length() - 1)v.push_back(cur);
		}
	}

	// 초기 숫자 구하기
	int f_num = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] > 0) {
			f_num *= 10;
			f_num += v[i] - 0;
		}
		else break;
	}

	int ans = f_num;
	for (int i = 1; i < v.size(); i++) {
		if (v[i] == -1) {
			ans +=  v[i + 1];
		}
		else if (v[i] == -2) {
			ans -= v[i + 1];
		}
	}

	if (ans == 0)return true;
	return false;
}

void func(int depth, int cur, string s) {
	if (depth == n-1) {
		if (print(s)) {
			string result = "";
			for (int i = 0; i < s.length(); i++) {
				if (s[i] > '0' && s[i + 1] > '0') {
					result += s[i];
					result += ' ';
				}
				else {
					result += s[i];
				}
			}
			cout << result << "\n";
		}
	}
	for (int i = cur; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			string temp = s;
			if (oper[j] == ' ') {
				temp += nums[i];
			}
			else {
				temp += oper[j];
				temp += nums[i];
			}
			func(depth + 1, i + 1, temp);
		}
	}
}


int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		func(0, 2, "1");
		cout << "\n";
	}
	return 0;
}
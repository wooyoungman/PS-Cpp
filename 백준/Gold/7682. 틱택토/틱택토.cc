#include<iostream>

using namespace std;

bool func(string s) {
	int cnt_x = 0, cnt_o = 0;
	// x,o 개수 카운트
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'X')cnt_x++;
		if (s[i] == 'O')cnt_o++;
	}
	// x가 2개 이상 많거나 o가 더 많은 경우 false
	if (cnt_x - cnt_o > 1)return false;
	if (cnt_o - cnt_x > 0)return false;

	
	int cnt_x_line = 0, cnt_o_line = 0;
	// 가로
	for (int i = 0; i < 7; i += 3) {
		if (s[i] != '.') {
			if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) {
				if (s[i] == 'X')cnt_x_line++;
				else if (s[i] == 'O')cnt_o_line++;
			}
		}
	}
	// 세로
	for (int i = 0; i < 3; i ++) {
		if (s[i] != '.') {
			if (s[i] == s[i + 3] && s[i + 3] == s[i + 6]) {
				if (s[i] == 'X')cnt_x_line++;
				else if (s[i] == 'O')cnt_o_line++;
			}
		}
	}

	int cnt_x_cross = 0, cnt_o_cross = 0;
	// 대각
	// 대각은 2개가 생겨도 가운데 하나 빼면 2개를 상쇄가 가능
	bool check = false;
	if (s[0] != '.') {
		if (s[0] == s[4] && s[4] == s[8]) {
			check = true;
			if (s[0] == 'X')cnt_x_cross++;
			else if (s[0] == 'O')cnt_o_cross++;
		}
	}
	if (s[2] != '.') {
		if (s[2] == s[4] && s[4] == s[6]&& !check) {
			if (s[2] == 'X')cnt_x_cross++;
			else if (s[2] == 'O')cnt_o_cross++;
		}
	}
	int sum_x = cnt_x_cross + cnt_x_line;
	int sum_o = cnt_o_cross + cnt_o_line;
	if (sum_x > 0 && sum_o == 0 && cnt_x - cnt_o == 1) {
		return true;
	}
	if (sum_o > 0 && sum_x == 0 && cnt_x - cnt_o == 0) {
		return true;
	}
	if ((sum_x + sum_o) == 0 && cnt_x == 5 && cnt_o == 4)return true;

	return false;
}

int main() {
	string s;
	while (1) {
		cin >> s;
		if (s == "end")break;
		if (func(s))cout << "valid" << "\n";
		else cout << "invalid" << "\n";
	}
	return 0;
}
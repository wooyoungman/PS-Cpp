#include<iostream>
#include<algorithm>

using namespace std;

int l, c;

// l개를 뽑아서 print() 함수에서
// 모음과 자음 개수를 확인하여 출력
char code[16];
char save[16];

void print() {
	int cnt_1 = 0, cnt_2 = 0;
	for (int i = 0; i < l; i++) {
		if (save[i] == 'a' || save[i] == 'e' || save[i] == 'i' ||
			save[i] == 'o' || save[i] == 'u') {
			cnt_1++;
		}
		else {
			cnt_2++;
		}
	}
	if (cnt_1 >= 1 && cnt_2 >= 2) {
		for (int i = 0; i < l; i++) {
			cout << save[i];
		}
		cout << "\n";
	}
}

void combination(int depth, int cur) {

	if (depth == l) {
		print();
		return;
	}

	for (int i = cur; i < c; i++) {
		if (code[i] >= 'a') {
			save[depth] = code[i];
			combination(depth + 1, i+1);
		}
	}

}

int main() {

	cin >> l >> c;
	
	for (int i = 0; i < c; i++) {
		cin >> code[i];
	}
	sort(code, code + c);
	combination(0, 0);

	return 0;
}

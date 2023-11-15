#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int n;
	string s;
	
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		cin >> n;
		cin >> s;
		int answer = 0;
		int cnt_1 = 0, cnt_2 = 0, cnt_3 = 0, cnt_4 = 0;
		for (int i = 0; i < s.length(); i++) {
			if (cnt_1 < 0 || cnt_2 < 0 || cnt_3 < 0 || cnt_4 < 0) {
				break;
			}
			if (s[i] == '(')cnt_1++;
			else if (s[i] == ')')cnt_1--;
			else if (s[i] == '[')cnt_2++;
			else if (s[i] == ']')cnt_2--;
			else if (s[i] == '{')cnt_3++;
			else if (s[i] == '}')cnt_3--;
			else if (s[i] == '<')cnt_4++;
			else if (s[i] == '>')cnt_4--;
		}
		if (cnt_1 == 0 && cnt_2 == 0 && cnt_3 == 0 && cnt_4 == 0)answer = 1;
		cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;
}
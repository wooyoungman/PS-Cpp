#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int answer = 0;
		string s,cur="";
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			cur += s[i];
			// aa, abab, abcabc 
			if (i > 0) {
				if (cur.substr(0, (i + 1) / 2) == cur.substr((i + 1) / 2, (i + 1) / 2)) {
					answer = cur.substr(0, (i + 1) / 2).length();
					break;
				}
			}
		}
		cout << "#" << test_case << " " << answer << "\n";

	}
	return 0;
}
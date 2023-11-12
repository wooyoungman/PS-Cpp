#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T,num;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> num;
		int cnt[101] = { 0, };
		for (int i = 0; i < 1000; i++) {
			cin >> num;
			cnt[num]++;
		}
		int max_cnt = cnt[0];
		int max_num = 0;
		for (int i = 1; i < 101; i++) {
			if (max_cnt <= cnt[i]) {
				max_cnt = cnt[i];
				max_num = i;
			}
		}
		cout << "#" << test_case << " " << max_num << "\n";
	}
	return 0;
}
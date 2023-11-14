#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int col, row;
	string row_line,arr[50];
	cin >> T;


	// 테스트케이스를 모두 확인해보니 앞에서부터 7자리를 탐색하면 안된다.
	// 0001101, 0011001인경우 무조건 앞에 0이 있으면 0001101로 지정하기 때문에
	// 뒤에서부터 탐색을 해야만 통과한다.
	for (test_case = 1; test_case <= T; ++test_case)
	{
		vector<int>v;
		int answer = 0;
		cin >> col >> row;
		
		for (int i = 0; i < col; i++) {
			cin >> row_line;
			arr[i] = row_line;
			// 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30
			for (int j = row-7; j >=0 ; j--) {
				if (arr[i].substr(j,7) == "0001101") {
					j -= 6;
					v.push_back(0);
				}
				else if (arr[i].substr(j,7) == "0011001") {
					j -= 6;
					v.push_back(1);
				}
				else if (arr[i].substr(j,7) == "0010011") {
					j -= 6;
					v.push_back(2);
				}
				else if (arr[i].substr(j,7) == "0111101") {
					j -= 6;
					v.push_back(3);
				}
				else if (arr[i].substr(j,7) == "0100011") {
					j -= 6;
					v.push_back(4);
				}
				else if (arr[i].substr(j,7) == "0110001") {
					j -= 6;
					v.push_back(5);
				}
				else if (arr[i].substr(j,7) == "0101111") {
					j -= 6;
					v.push_back(6);
				}
				else if (arr[i].substr(j,7) == "0111011") {
					j -= 6;
					v.push_back(7);
				}
				else if (arr[i].substr(j,7) == "0110111") {
					j -= 6;
					v.push_back(8);
				}
				else if (arr[i].substr(j,7) == "0001011") {
					j -= 6;
					v.push_back(9);
				}
				if (v.size() == 8)break;
			}
		}
		int comp=(v[1] + v[3] + v[5] + v[7]) * 3 + v[0] + v[2] + v[4] + v[6];
		if (comp % 10 == 0) {
			for (auto p : v) {
				answer += p;
			}
		}
		cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;
}
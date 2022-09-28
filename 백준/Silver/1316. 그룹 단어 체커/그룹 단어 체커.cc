#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
// unique와 sort 그리고 erase 활용하기
int main()
{	
	int n,idx,cnt=0;
	bool group_flag = true;
	cin >> n;
	string s;
	for (int i = 0; i < n; i++)
	{
		bool alpha[26] = { false };
		cin >> s;
		// unique는 중복값이 시작되는 iterator를 반환함
		s.erase(unique(s.begin(), s.end()),s.end());
		//cout << s << endl;
		for (int q = 0; q < s.length(); q++)
		{
			idx = int(s[q] - 'a');
			if (alpha[idx] == false)
			{
				alpha[idx] = true;
			}
			else
			{
					group_flag = false;
			}
		}
		if (group_flag == false)
		{
			cnt++;
			group_flag = true;
		}
	}
	cout << n-cnt;
	return 0;
}
	
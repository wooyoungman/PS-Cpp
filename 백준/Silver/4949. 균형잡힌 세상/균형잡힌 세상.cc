#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string se;
	while (1)
	{
		// cin은 공백 이전까지만 입력을 받는다
		// 공백도 포함하기 위한 입력 방법
		// 3번째 인자를 생략하면 자동으로 '\n'문자가 저장
		getline(cin,se);
		stack<char>s;
		bool check = false;
		int cnt1 = 0,cnt2=0;
		if (se == ".")
		{
			break;
		}
		else
		{
			for (int i = 0; i < se.length(); i++)
			{
				if (se[i] == '('||se[i]=='[')
				{
					s.push(se[i]);
					cnt1++;
				}
				else if (se[i] == ')')
				{
					if (!s.empty())
					{
						if (s.top() == '(')
						{
							s.pop();
						}
						else
						{
							check = true;
							break;
						}
					}
					cnt2++;
				}
				else if (se[i] == ']')
				{
					if (!s.empty())
					{
						if (s.top() == '[')
						{
							s.pop();
						}
						else
						{
							check = true;
							break;
						}
					}
					cnt2++;
				}
			}
			if (s.empty()&&(cnt1==cnt2))
			{
				cout << "yes" << "\n";
			}
			else if (check == true)
			{
				cout << "no" << "\n";
			}
			else
			{
				cout << "no" << "\n";
			}
		}
	}

	return 0;
}

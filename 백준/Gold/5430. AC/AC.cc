#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>
#include<map>
#include<string>

using namespace std;

int t, n;
string p, nums;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> p >> n >> nums;
		deque<int>q;
		int d_cnt = 0, r_cnt = 0;
		string temp_s = "";
		// 숫자 배열에서 숫자를 뽑아 새로운 배열에 저장
		for (int i = 0; i < nums.length(); i++)
		{
			if (nums[i] >= '0' && nums[i] <= '9')
			{
				temp_s += nums[i];
			}
			else
			{
				if (temp_s != "")
				{
					q.push_back(stoi(temp_s));
					temp_s = "";
				}
			}
		}
		// R 문자의 개수를 카운터하며 홀수이면 리버스로 인덱스 접근하기
		for (int i = 0; i < p.length(); i++)
		{
			if (p[i] == 'R')
			{
				r_cnt++;
			}
			else
			{
				d_cnt++;
				if (!q.empty())
				{
					if (r_cnt % 2 != 0)
					{
						q.pop_back();
					}
					else
					{
						q.pop_front();
					}
				}
			}
		}

		if (n == 0 && d_cnt > 1)
		{
			cout << "error" << "\n";
			continue;
		}
		if (d_cnt > n)
		{
			cout << "error" << "\n";
			continue;
		}
		if (r_cnt % 2 == 0)
		{
			cout << '[';
			for (int i = 0; i < q.size(); i++)
			{
				if (i != q.size() - 1)
				{
					cout << q[i] << ',';
				}
				else
				{
					cout << q[i];
				}
			}
			cout << ']';
			cout << "\n";
		}
		else
		{
			cout << '[';
			for (int i = q.size() - 1; i >= 0; i--)
			{
				if (i != 0)
				{
					cout << q[i] << ',';
				}
				else
				{
					cout << q[i];
				}
			}
			cout << ']';
			cout << "\n";
		}
	}
	return 0;
}
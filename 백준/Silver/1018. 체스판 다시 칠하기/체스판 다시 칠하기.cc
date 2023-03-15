#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int cnt = 0;

string WB[8] = {
"WBWBWBWB",
"BWBWBWBW",
"WBWBWBWB",
"BWBWBWBW",
"WBWBWBWB",
"BWBWBWBW",
"WBWBWBWB",
"BWBWBWBW"
};

string BW[8] = {
"BWBWBWBW",
"WBWBWBWB",
"BWBWBWBW",
"WBWBWBWB",
"BWBWBWBW",
"WBWBWBWB",
"BWBWBWBW",
"WBWBWBWB"
};

string s[50];

int BW_cnt(int a, int b)
{
	cnt = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (s[a + i][b + j] != BW[i][j])
			{
				cnt++;
			}
		}
	}
	return cnt;
}

int WB_cnt(int a, int b)
{
	cnt = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (s[a + i][b + j] != WB[i][j])
			{
				cnt++;
			}
		}
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, temp, min_val=0;
	cin >> n>> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	for (int i = 0; i + 8 <= n; i++)
	{
		for (int j = 0; j + 8 <= m; j++)
		{
			
			temp = min(WB_cnt(i, j), BW_cnt(i, j));
			if ((temp < min_val)||(i==0&&j==0))
			{
				min_val = temp;
			}
		}
	}
	cout << min_val;
	return 0;
}
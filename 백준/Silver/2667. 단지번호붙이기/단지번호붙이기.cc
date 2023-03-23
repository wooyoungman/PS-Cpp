#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

vector<int>cnt2;
int arr[26][26];
bool visited[26][26];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n, m, v, cnt = 0, cnt1 = 0;


void dfs(int x, int y)
{
	if (visited[x][y] == false && arr[x][y] == 1)
	{
		cnt++;
		visited[x][y] = true;
		int temp_x, temp_y;
		for (int i = 0; i < 4; i++)
		{
			temp_x = x + dx[i];
			temp_y = y + dy[i];
			if (visited[temp_x][temp_y] == false && temp_x >= 0 && temp_x < n && temp_y >= 0 && temp_y < n && arr[temp_x][temp_y] == 1)
			{
				dfs(temp_x, temp_y);
			}
		}
	}
	else if (visited[x][y] == false && arr[x][y] == 0)
	{
		visited[x][y] = true;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			if (s[j] == '1')
			{
				arr[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dfs(i, j);
			if (cnt != 0)
			{
				cnt1++;
				cnt2.push_back(cnt);
				cnt = 0;
			}
		}
	}
	cout << cnt1 << "\n";
	sort(cnt2.begin(), cnt2.end());
	for (int i=0;i<cnt2.size();i++)
	{
		cout << cnt2[i]<<"\n";
	}
	return 0;
}
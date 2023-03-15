#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<int> score_list;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, new_score, p,score,cnt=0,rank=1;
	bool check = false;
	cin >> n >> new_score >> p;
	for (int i = 0; i < n; i++)
	{
		cin >> score;
		score_list.push_back(score);
	}
	sort(score_list.begin(), score_list.end(),greater<>());

	for (int i = 0; i < n; i++)
	{
		if (new_score < score_list[i])
		{
			rank++;
			cnt++;
		}
		else if (new_score == score_list[i])
		{
			cnt++;
			continue;
		}
		else
		{
			break;
		}
	}
	if (cnt == p)
	{
		rank = -1;
	}
	if (n == 0)
	{
		rank = 1;
	}
	cout << rank;
	return 0;
}
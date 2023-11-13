#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int arr[16][16];
bool visited[16][16];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int start_x, start_y, end_x, end_y;
int find_check;
void bfs(int _start_x,int _start_y) {
	queue<pair<int, int>>q;
	q.push(make_pair(_start_x, _start_y));
	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		if (cur_x == end_x && cur_y == end_y) { 
			find_check = 1; 
			return;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];
			if (next_x >= 0 && next_y >= 0 && next_x < 16 && next_y < 16
				&& arr[next_x][next_y] == 0 && !visited[next_x][next_y]) {
				q.push(make_pair(next_x, next_y));
				visited[next_x][next_y] = true;
			}
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T,cnt;
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		find_check = 0;
		cin >> T;
		memset(arr, 0, sizeof(arr));
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < 16; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < 16; j++) {
				arr[i][j] = s[j] - '0';
				if (arr[i][j] == 2) {
					start_x = i;
					start_y = j;
					arr[i][j] = 0;
				}
				else if (arr[i][j] == 3) {
					end_x = i;
					end_y = j;
					arr[i][j] = 0;
				}
			}
		}
		bfs(start_x, start_y);
		cout << "#" << T << " " << find_check << "\n";
	}
	return 0;
}
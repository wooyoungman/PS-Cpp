#include<iostream>
#include<cstring>
using namespace std;

int answer = 0;
bool visited[100][2];
int arr1[100];
int arr2[100];
void dfs(int start) {
	if (start == 99) {
		answer = 1;
		return;
	}

	if (arr1[start] != -1 && !visited[start][0]) {
		int cur = arr1[start];
		visited[start][0] = true;
		dfs(cur);
		visited[start][0] = false;
	}
	if (arr2[start] != -1 && !visited[start][1]) {
		int cur = arr2[start];
		visited[start][1] = true;
		dfs(cur);
		visited[start][1] = false;
	}

}

int main(int argc, char** argv)
{
	int test_case;
	int T, n;


	for (test_case = 1; test_case <= 10; ++test_case)
	{
		cin >> T>>n;
		memset(arr1, -1, sizeof(arr1));
		memset(arr2, -1, sizeof(arr2));
		memset(visited, false, sizeof(visited));
		answer = 0;
		for (int i = 0; i < n; i++) {
			int s, e;
			cin >> s >> e;
			if (arr1[s] == -1) {
				arr1[s] = e;
			}
			else if (arr1[s] != -1 && arr2[s] == -1) {
				arr2[s] = e;
			}
		}
		dfs(0);
		cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;
}
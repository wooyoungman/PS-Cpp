#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <limits.h>
#include <algorithm>
#include<vector>
#include<queue>

#define MAX INT_MAX
using namespace std;

int t, n, k,ans;
int map[10][10];
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int highst;
bool visited[10][10];

struct Info {
	int y, x, dist;
};

vector<Info>start;

void init() {
	ans = 0;
	highst = 0;
	start.clear();
	memset(map, 0, sizeof(map));
	memset(visited, false, sizeof(visited));
}

void input() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			highst = max(map[i][j], highst);
		}
	}
}

void findStart() {
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == highst) {
				start.push_back({ i,j,1 });
			}
		}
	}

}

bool isValid(int y, int x) {
	return y >= 0 && x >= 0 && y <= n - 1 && x <= n - 1 && !visited[y][x];
}

void dfs(Info s) {

	// 각 최곳점에 대해 방향배열을 이용한 DFS 진행
	//cout << s.y <<" "<< s.x << " "<<map[s.y][s.x] << "\n";

	int cur_y = s.y;
	int cur_x = s.x;
	int cur_dist = s.dist;

	for (int j = 0; j < 4; j++) {
		int next_y = cur_y + dy[j];
		int next_x = cur_x + dx[j];
		int next_dist = cur_dist + 1;
		Info next = { next_y,next_x,next_dist };
		if (!isValid(next_y, next_x))continue;
		if (map[cur_y][cur_x] > map[next_y][next_x]) {
			visited[next_y][next_x] = true;
			dfs(next);
			visited[next_y][next_x] = false;
		}
		else {
			ans = max(ans, cur_dist);
			continue;
		}
	}
	
}

void func() {
	// nxn 지점 중 하나를 선택하여 0~k만큼 깎고
	// start 지점 중 하나를 선택하여 dfs
	for (int i = 0; i < start.size(); i++) {
		for (int j = 0; j <= k; j++) {
			for (int l = 0; l < n; l++) {
				for (int c = 0; c < n; c++) {
					visited[start[i].y][start[i].x] = true;
					map[l][c] -= j;
					dfs(start[i]);
					map[l][c] += j;
					visited[start[i].y][start[i].x] = false;
				}
			}
		}
	}
}

int main() {

	//freopen("input.txt", "r", stdin);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		init();
		input();
		findStart();
		func();


		cout << "#" << i << " " << ans << "\n";
	}


	return 0;
}
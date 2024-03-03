#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#define CP 150
using namespace std;

int t, n, m, k;
// (K,K)기준 NxM 입력 후 해당 영역에서 최대 150만큼 뻗어나갈 수 있음
int map[350][350];
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
struct Cell {
	// 좌표, 최대 생명, 현재 생명
	int y, x, life_a, life_b;
};
vector<Cell>cells;
void init() {
    memset(map, 0, sizeof(map));
	cells.clear();
}

struct Compare {
	bool operator()(Cell a, Cell b) {
		return a.life_a < b.life_a;
	}
};

void input() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++){
			cin >> map[CP + i][CP + j];
			int v = map[CP + i][CP + j];
			if (v > 0)cells.push_back({CP + i,CP + j,v,v});
		}	
	}
}

int func() {
	int dead_cnt = 0;
	priority_queue<Cell,vector<Cell>,Compare>makeChild;
	while (k>0) {
		k--;
		for (int i = 0; i < cells.size(); i++) {
			cells[i].life_b--;
			// 현재 생명이 0이라면 1초 후에 번식을 완료해야함 -> -1일 때 진행
			if (cells[i].life_b == -1) {
				// 번식을 해야하는 세포 큐에 추가
				// 최대 생명력이 더 높은 녀석 우선 
				makeChild.push(cells[i]);
			}
			// 현재 생명이 원래 생명 * -1 => 사망
			if (cells[i].life_b * -1 == cells[i].life_a) {
				dead_cnt++;
			}
		}
		while (!makeChild.empty()) {
			Cell now = makeChild.top();
			makeChild.pop();
			for (int i = 0; i < 4; i++) {
				int ny = now.y + dy[i];
				int nx = now.x + dx[i];
				if (map[ny][nx] == 0) {
					map[ny][nx] = now.life_a;
					cells.push_back({ ny,nx,now.life_a,now.life_a });
				}
			}
		}
	}
	return cells.size()-dead_cnt;
}

int main() {
	//freopen("input.txt", "r", stdin);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		init();
		input();
		cout << "#" << i << " " << func() << "\n";
	}
	return 0;
}

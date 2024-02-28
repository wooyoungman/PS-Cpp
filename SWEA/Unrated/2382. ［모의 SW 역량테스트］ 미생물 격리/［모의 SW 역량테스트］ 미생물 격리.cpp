#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<cstring>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<set>
using namespace std;

int t, n, m, k, ans;
int y, x, num, dir;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct Bio {
	int y, x, num, dir;
};


bool compare(Bio a, Bio b) {
	return a.num > b.num;
}

vector<Bio>bios;

void init() {
	ans = 0;
	bios.clear();
}

void input() {

	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		cin >> y >> x >> num >> dir;
		bios.push_back({ y,x,num,dir });
	}

}

bool checkRedCell(int y, int x) {
	return y == 0 || x == 0 || y == n - 1 || x == n - 1;
}

void afterMove() {
	sort(bios.begin(), bios.end(),compare);
	unordered_map<int,Bio>um;
	set<int>save_num;
	for (int i = 0; i < bios.size(); i++) {
		if (checkRedCell(bios[i].y, bios[i].x)) {
			bios[i].num /= 2;
			if (bios[i].dir % 2 == 0) {
				bios[i].dir -= 1;
			}
			else {
				bios[i].dir += 1;
			}
		}
		int num = (bios[i].y) * n + bios[i].x;
		save_num.insert(num);
		if (um.count(num) == 0) {
			um[num] = { bios[i].y,bios[i].x,bios[i].num,bios[i].dir };
		}
		else {
			um[num].num += bios[i].num;
		}
	}
	vector<Bio>temp;
	for (auto p : save_num) {
		temp.push_back({ um[p].y,um[p].x,um[p].num,um[p].dir });
	}
	bios.clear();
	bios = temp;
}

void move() {

	for (int i = 0; i < bios.size(); i++) {
		bios[i].y += dy[bios[i].dir - 1];
		bios[i].x += dx[bios[i].dir - 1];
	}
	
	afterMove();
}

int getSum() {
	int sum = 0;
	for (int i = 0; i < bios.size(); i++) {
		sum += bios[i].num;
	}
	return sum;
}

int main() {

	//freopen("input.txt", "r", stdin);
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		init();
		input();
		for (int i = 0; i < m; i++) {
			move();
		}
		cout << "#"<<tc<<" "<<getSum()<<"\n";
	}
	return 0;
}
#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

unordered_map<string, int>um;

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int arr[3][3];
string goal = "123456780";
string start;
bool check;

bool isValid(int y, int x) {
	return y >= 0 && x >= 0 && y < 3 && x < 3;
}

struct Info {
	string nums;
	int y, x, dis;
};

// 문자열로 현재 맵을, 그리고 0의 좌표를 받는다. 
void func(int y, int x) {
	queue<Info>q;
	q.push({ start,y,x,0 });
	um[start] = 0;
	while (!q.empty()) {
		Info now = q.front();
		q.pop();
		//cout << now.y << " " << now.x << "\n";
		//cout << now.nums << "현재 이동 거리 : "<<now.dis << "\n";
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			int nd = now.dis + 1;
			if (!isValid(ny, nx))continue;
			int idx1 = 3 * now.y + now.x;
			int idx2 = 3 * ny + nx;
			string next_nums = now.nums;
			char temp = next_nums[idx1];
			next_nums[idx1] = next_nums[idx2];
			next_nums[idx2] = temp;
			if (um.count(next_nums) != 0)continue;
			um[next_nums] = nd;
			if (next_nums == goal)return;
			q.push({ next_nums,ny,nx,nd });
		}
	}
}

int main() {
	int sy = 0, sx = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) {
				sy = i;
				sx = j;
			}
			start += to_string(arr[i][j]);
		}
	}
	func(sy,sx);
	if (um.count(goal))cout << um[goal];
	else cout << -1;
	return 0;
}
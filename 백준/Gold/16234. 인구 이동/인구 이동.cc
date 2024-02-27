#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
using namespace std;

int n, l, r;
int map[51][51];
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

int parent[2501];
bool visited[51][51];
int save_cnt[2501] = { 0, };
int save_pop[2501] = { 0, };
int save_par;
int ans;
struct Pos {
	int y, x;
};

struct PosSet2 {
	int y, x, num;
};


struct PosSet {
	int y1, x1, y2, x2;
};



bool isValid(int y, int x) {
	return y >= 1 && x >= 1 && y <= n && x <= n;
}

void init() {

	memset(visited, false, sizeof(visited));
	memset(save_cnt, 0, sizeof(save_cnt));
	memset(save_pop, false, sizeof(save_pop));
	save_par = 0;
	

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int num = (i - 1) * n + j;
			parent[num] = num;
		}
	}
}

int find(int tar) {
	if (tar == parent[tar])return tar;
	int ret = find(parent[tar]);
	parent[tar] = ret;
	return ret;
}

void setUnion(int a,int b) {

	int t1 = find(a);
	int t2 = find(b);
	if (t1==t2)return;
	parent[t2] = t1;

}


bool bfs() {


	queue<Pos>q;
	q.push({ 1,1 });

	vector<PosSet>v;

	while (!q.empty()) {
		Pos now = q.front();
		q.pop();
		// 하나의 지역에 대해 국경선 열기 확인
		if (visited[now.y][now.x])continue;
		visited[now.y][now.x] = true;
		for (int i = 0; i < 4; i++) {
			int next_y = now.y + dy[i];
			int next_x = now.x + dx[i];
			if (!isValid(next_y, next_x) || visited[next_y][next_x])continue;
			// L <= 인구 차이 <= R

			q.push({ next_y,next_x });

			int pop_dif = abs(map[now.y][now.x] - map[next_y][next_x]);
			if (l <= pop_dif && pop_dif <= r)
			{
				v.push_back({ now.y,now.x,next_y,next_x });
			}
			
		}
	}

	// 국경선을 열 수 있는 곳이 없으면 false 반환
	if (v.empty())return false;

	// 국경선을 열 수 있는 곳이 있으면 유니온 파인드 진행 
	else {
		init();
		for (int i = 0; i < v.size(); i++) {
			int first_y = v[i].y1;
			int first_x = v[i].x1;
			int second_y = v[i].y2;
			int second_x = v[i].x2;

			// 각 나라의 번호 : (i-1)*n + j를 대입
			int first_num = (first_y - 1) * n + first_x;
			int second_num = (second_y - 1) * n + second_x;
			
			// 부모 통일
			setUnion(first_num, second_num);
		}


		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int num = (i - 1) * n + j;
				find(num);
			}
		}

		// 유니온 마친 후 연합의 인구, 연합의 크기 구하기
		// 연합의 크기는 현재 자신의 부모가 달라진 유니온 개수 + 1
		// 연합의 인구는 현재 자신의 부모가 달라진 유니온의 좌표의 인구 + 다른 부모 값 1회 더하기

		// 대표 부모, 연합 인구, 연합 좌표 저장

		vector<PosSet2>temp;
		set<int>s;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int num = (i - 1) * n + j;
				if (parent[num] != num) {
					//cout << num << " " << parent[num] << "\n";
					save_par = parent[num];
					save_cnt[save_par]++;
					save_pop[save_par] += map[i][j];
					temp.push_back({i,j,save_par});
					s.insert(save_par);
				}
			}
		}


		// 각 나라 별 배치 인구 
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {

				// 현재 번호로 연합이 형성되어있다면
				int num = (i - 1) * n + j;
				if (s.find(num)!=s.end()) {
					// 현재 번호까지 추가하기
					save_cnt[num]++;
					save_pop[num] += map[i][j];
					temp.push_back({ i,j,num });
				}
			}
		}

		for (int i = 0; i < temp.size(); i++) {
			int num = temp[i].num;
			int y = temp[i].y;
			int x = temp[i].x;
			int u_pop = save_pop[num] / save_cnt[num];
			map[y][x] = u_pop;
		}

		// 각 나라 인구 재배치 
		//for (int i = 1; i <= n; i++) {
		//	for (int j = 1; j <= n; j++) {
		//		int num = (i - 1) * n + j;
		//		if (!temp[num].empty()) {

		//			int u_pop = save_pop[num] / save_cnt[num];
		//			//cout << ans<<" "<<num << " " << u_pop << "\n";
		//			for (int k = 0; k < temp[num].size(); k++) {
		//				int y = temp[num][k].y;
		//				int x = temp[num][k].x;
		//				map[y][x] = u_pop;
		//			}

		//		}
		//	}
		//}

		return true;
	}
}

int main() {

	cin >> n >> l >> r;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}


	while (1) {
		if (bfs()) {
			ans++;
			continue;
		}
		break;
	}
	cout << ans;
	return 0;
}
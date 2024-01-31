#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int T;
int N, M, R, C, L;
int pipe[50][50];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int visited[51][51];
// 상 하 좌 우 순서
int pipe_dir[8][4] = {
	{0,0,0,0},{1,1,1,1},
	{1,1,0,0},{0,0,1,1},
	{1,0,0,1},{0,1,0,1},
	{0,1,1,0},{1,0,1,0}
};

struct Pos {
	int y, x;
};

void init() {
	memset(pipe, 0, sizeof(pipe));
	memset(visited, 0, sizeof(visited));
}

void input() {
	cin >> N >> M >> R >> C >> L;
	// 0~7번 종류에 해당하는 파이프 종류 입력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> pipe[i][j];
		}
	}
}

// 연결된 파이프로 탐색 1회당 시간 1초 증가
// L초일 때 현재까지 방문한 파이프의 개수 반환
int bfs(int y, int x) {

	queue<Pos>q;
	q.push({ y,x });

	visited[y][x] = 1;
	int cnt = 0;

	// 현재 파이프가 갈 수 있는 다음 파이프를 찾아야한다.
	// 현재 파이프의 끝나는 방향 = 다음 파이프의 끝나는 방향
	// 즉 현재 우측 방향이 존재한다면 우측 파이프는 좌측으로 연결이 되어있어야함!

	while (!q.empty()) {
		int cur_y = q.front().y;
		int cur_x = q.front().x;
		q.pop();

		// 현재 방문 시간이 L보다 큰 경우 확인 x
		if (visited[cur_y][cur_x] > L)break; 

		// 우선 현재 시작지점을 갈 수 있으므로 ans+1;
		cnt++;

		// 현재 파이프의 다음 지점 확인
		for (int i = 0; i < 4; i++) {
			int next_y = cur_y + dy[i];
			int next_x = cur_x + dx[i];
			if (next_y < 0 || next_x < 0 || next_y >= N || next_x >= M || visited[next_y][next_x]>0 || pipe[next_y][next_x] == 0) {
				continue;
			}
			// 범위를 벗어나거나, 이미 방문했거나, 파이프가 없거나 이외에
			// 갈 수 없는 조건이 더 존재한다.

			// 1. 현재 파이프에서 다음 파이프 방향으로 갈 수 없는 경우

			// i는 현재 i 방향으로 이동한다는 뜻 
			// pipe_dir[pipe[next_y][next_x]] = 다음 파이프에서의 연결 방향
			// pipe_dir[pipe[cur_y][cur_x]] = 현재 파이프에서의 연결 방향 
			// pipe_dir[pipe[cur_y][cur_x]][0] = 현재 파이프가 위로 연결 되어있는가 
			// 그렇다면 현재 i 방향으로 이동한다면 위 식을 일반화 할 수 있지 않을까?
			// int cur_pipe = pipe[cur_y][cur_x];
			// if(pipe_dir[cur_pipe][i] == 0) -> 현재 파이프에서 i 방향으로 못간다!
			
			int cur_pipe = pipe[cur_y][cur_x];
			if (pipe_dir[cur_pipe][i] == 0)continue;


			// 2. 다음 파이프에서 현재 파이프 방향으로 올 수 없는 경우
			// int next_pipe = pipe[next_y][next_x];
			// 상 -> 하, 하 -> 상, 좌 -> 우, 우 -> 좌로 인덱스를 넣어주어야 한다.
			// 상 : 0, 하 : 1, 좌 : 2, 우 : 3
			// 0, 2 일때 +1, 1, 3 일때 -1 이므로
			// 2로 나누어 떨어지면 +1, 안떨어지면 -1
			// int reverse_i;
			// if(i%2==0) : reverse_i = i+1;
			// else : reverse_i = i-1;
			// if (pipe_dir[next_pipe][reverse_i] == 0)->다음 파이프에서 i 역방향으로 못간다!

			int next_pipe = pipe[next_y][next_x];

			int reverse_i;
			if (i % 2 == 0) reverse_i = i + 1;
			else reverse_i = i - 1;

			if (pipe_dir[next_pipe][reverse_i] == 0) continue;

			// 모든 조건을 만족하면 이동
			visited[next_y][next_x] = visited[cur_y][cur_x]+1;
			q.push({ next_y,next_x });

		}

	}
	return cnt;


}

int main() {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		init();
		input();
		int ans = bfs(R, C);
		cout << "#" << i << " " << ans << "\n";
	}

	return 0;
}
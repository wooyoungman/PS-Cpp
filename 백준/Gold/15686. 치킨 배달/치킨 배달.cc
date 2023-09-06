#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;


int N, M;
int MIN = 999999999;
bool selected[13];
vector<pair<int,int>> house_pos;
vector<pair<int,int>> chicken_pos;
vector<pair<int,int>> choosed_pos;
// 조합으로 a개의 치킨 집 중 M개를 모두 고른 후 
// 최소 치킨 거리를 구하자

void find_chicken_dist() {

	// 하나의 집부터 선택한 치킨집에 대해 최소거리 구하고 결과에 저장
	int total_dist = 0;
	for (int i = 0; i < house_pos.size(); i++) {
		int min_dist = 999999999;
		for (int j = 0; j < choosed_pos.size(); j++) {
			min_dist = min(min_dist,
				abs(house_pos[i].first - choosed_pos[j].first) +
				abs(house_pos[i].second - choosed_pos[j].second)
			);
		}
		total_dist += min_dist;
	}
	MIN = min(MIN, total_dist);

}

void find_combination(int x, int m) {
	if (m == M) {
		// M개의 치킨 집 선택 후 치킨거리 구하기
		find_chicken_dist();
	}
	// 치킨 집 M개 고르기
	for (int i = x; i < chicken_pos.size(); i++) {
		if (selected[i])continue; // 이미 고른거면 넘어가기

		// 안골랐으면 배열에 체크 후 넣어주고 다음 순번으로
		selected[i] = true;
		choosed_pos.push_back(make_pair(chicken_pos[i].first, chicken_pos[i].second));
		find_combination(i, m + 1);
		selected[i] = false;
		choosed_pos.pop_back();
	}

}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int v;
			cin >> v;
			if (v == 1) {
				// 그냥 집
				house_pos.push_back(make_pair(i,j));
			}
			else if (v == 2) {
				// 치킨 집
				chicken_pos.push_back(make_pair(i, j));
			}
		} 
	}
	find_combination(0, 0);
	cout << MIN;
	return 0;
}
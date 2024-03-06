#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// n개의 마을과 m개의 간선이 존재
// 이 마을을 2개의 마을로 나누려고 한다.
// 각 마을은 두 집 사이에 경로가 항상 존재해야한다.
// 이 때 경로가 항상 존재하며 최소인 비용은
// 사이클이 없을 때의 구조이므로 MST이다.

int n, m;
//  2<=N<=100000
//  1<=M<=1000000

// 간선의 비용이 양수일 때 -> 크루스칼 
// 크루스칼은 3가지 단계로 구성
// 1. sort (간선의 비용이 낮은 순)
// 2. Union-Find (각 무리 구성)
// 3. for문 (for문을 통해 연결된 비용의 값 저장)

//n개의 집을
//2개의 마을로 분리

//1개의 마을을 만들 수 있는 MST의 간선의 수 = n - 1
//2개의 마을을 만들 수 있는 MST의 간선의 수 = n - 2

//n - 1개의 MST를 구한 후
//그 중 가장 간선의 길이가 긴거 하나를 뺀 값이 정답 ?


struct Info {
	int s, e, w;
};

bool compare(Info a, Info b) {
	return a.w < b.w;
}

vector<Info>houses;


// init, find, setUnion
int parent[100001];
void init() {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
}

int find(int tar) {
	if (parent[tar] == tar)return tar;
	int ret = find(parent[tar]);
	parent[tar] = ret;
	return ret;
}

void setUnion(int a,int b) {
	int t1 = find(a);
	int t2 = find(b);
	if (t1 == t2)return;
	parent[t2] = t1;
}

int main() {

	cin >> n >> m;
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		houses.push_back({ a,b,c });
	}

	


	sort(houses.begin(), houses.end(), compare);

	// 크루스칼 진행하며 등록된 간선의 정보를 저장
	init();
	vector<int>tempWeight;
	int cntLine = 0;
	int target = n - 1;
	for (auto p : houses) {
		int s = p.s;
		int e = p.e;
		int w = p.w;
		// 사이클이 있는가 판단
		if (find(s) == find(e))continue;

		// 없으면 그룹 형성
		setUnion(s, e);

		// 그룹 형성 했으니 현재 간선 정보 저장
		cntLine++;
		tempWeight.push_back(w);

		// 현재 n-1개의 간선이 연결되었으면 종료
		if (cntLine == target)break;

	}

	int ans = 0;
	// 현재 저장된 간선의 정보중 가장 큰 값을 뺀 나머지 합을 출력
	sort(tempWeight.begin(), tempWeight.end());
	for (int i = 0; i < tempWeight.size() - 1; i++) {
		ans += tempWeight[i];
	}
	cout << ans;

	return 0;
}
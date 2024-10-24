#include<iostream>

using namespace std;

// 1부터 1,000,000까지의 정수로 사탕의 맛을 표현 (낮을 수록 가장 맛있다)

// 사탕 상자에 손을 대는 횟수 n은 최대 10만

// 1은 꺼내는 경우 -> A = 1 , B = 3 이면 맛이 3번째로 좋은 사탕을 꺼내는 의미

// 2로 넣는 경우 -> A = 2, B = 4, C = 5 이면 맛이 4인 사탕을 5개 넣는다는 의미

// 2로 빼는 경우 -> A = 3, B = 5, C = -1 이면 맛이 5인 사탕을 1개 꺼내는 의미

// 세그먼트트리 -> 쿼리 실행 수 Q, 노드 개수 n -> O(Qlog(n))
// 쿼리 실행 수 : n(10만)
// 노드 수 최대 : 100만
// 시간복잡도 10만 x log(100만) = 100만 x 6

// 현재 노드의 왼쪽 자식 노드 값(사탕 개수) >= 찾고자 하는 x번째 값 -> 왼쪽 이동

#define MAX 1000100
#define ll long long
ll trees[MAX * 4];
int n;

// idx번째 사탕을 cnt 만큼 더하기 (음수도 포함)
ll update(int idx, int cnt, int node, int left, int right) {
	if (idx<left || idx>right)return trees[node];
	else if (left == right)return trees[node] += cnt;
	ll mid = (left + right) / 2;
	return trees[node] =
		update(idx, cnt, node * 2, left, mid) + update(idx, cnt, node * 2+1, mid + 1, right);
}

// x번째 사탕 찾기 -> 리프 노드 번호가 사탕 맛의 수를 뜻
ll find(int x, int node, int left, int right) {
	if (left == right)return left;
	ll mid = (left + right) / 2;
	// 왼쪽 자식 노드 범위에 해당하는 사탕 개수가 같거나 크면
	if (trees[node * 2] >= x) {
		return find(x, node * 2, left, mid);
	}
	// 왼쪽 자식 노드 범위에 없으면 오른쪽으로 우회
	// (왼쪽 자식 노드 범위의 사탕 개수는 이미 자신 보다 맛있는 사탕이므로 빼서 세주기)
	else {
		return find(x - trees[node * 2], node * 2 + 1, mid + 1, right);
	}
}

void func() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b;
		// 꺼내기
		if (a == 1) {
			// b번째 해당하는 사탕 맛의 번호 구하고 빼주기
			int num = find(b, 1, 1, MAX);
			cout << num << "\n";
			update(num, -1, 1, 1, MAX);
		}
		else {
			cin >> c;
			// b맛의 사탕을 c만큼 넣거나 빼기
			update(b, c, 1, 1, MAX);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	func();
	return 0;
}
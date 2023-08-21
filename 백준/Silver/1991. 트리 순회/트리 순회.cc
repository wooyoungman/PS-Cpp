#include <iostream>

using namespace std;

int n;
int tree [30][2];

// 노드 -> 왼쪽 -> 오른쪽
void preorder(int s) {
	if (s == -1)
	{
		return;
	}
	cout << (char)(s + 'A');
	preorder(tree[s][0]);
	preorder(tree[s][1]);
}

// 왼쪽 -> 노드 -> 오른쪽
void inorder(int s) {
	if (s == -1)
	{
		return;
	}

	inorder(tree[s][0]);
	cout << (char)(s + 'A');
	inorder(tree[s][1]);
}

// 왼쪽 -> 오른쪽 -> 노드
void postorder(int s) {
	if (s == -1)
	{
		return;
	}

	postorder(tree[s][0]);
	postorder(tree[s][1]);
	cout << (char)(s + 'A');
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		a = a - 'A';
		if (b == '.') {
			tree[a][0] = -1;
		}
		else
		{
			tree[a][0] = b - 'A';
		}
		if (c == '.') {
			tree[a][1] = -1;
		}
		else
		{
			tree[a][1] = c - 'A';
		}
	}
	preorder(0);
	cout << "\n";
	inorder(0);
	cout << "\n";
	postorder(0);
	return 0;
}
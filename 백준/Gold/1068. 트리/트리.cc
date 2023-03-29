#include<iostream>
#include<vector>

using namespace std;
vector<int> tree[51];
int del;
int dfs(int _root)
{
	int cnt = 0;
	for (auto p : tree[_root])
	{
		if (p == del)
		{
			// 지울 노드면 그냥 무시하고 다른 노드 탐색
			continue;
		}
		// 리프 노드가 있는 경우 재귀함수로 리턴하여 cnt에 누적시켜 카운팅
		cnt += dfs(p);
	}
	// 마지막 맨 끝의 노드까지 들어가서 역순으로 탐색 
	if (cnt)
	{
		return cnt;
	}
	else
	{
		return 1;
	}
}

int main()
{
	int n, node_par, root;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> node_par;
		if (node_par == -1)
		{
			// i가 노드 번호, node는 입력 받은 노드의 부모 노드 
			root = i;
		}
		else
		{
			tree[node_par].push_back(i);
		}
	}
	cin >> del;
	if (root != del)
	{
		cout << dfs(root);
	}
	else
	{
		cout << 0;
	}
	return 0;
}
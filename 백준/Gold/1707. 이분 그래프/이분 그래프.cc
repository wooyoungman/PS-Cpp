#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int K, V, E;

vector<int>Node[20001];
int check[20001];
void init() {
	for (int i = 1; i <= V; i++) {
		Node[i].clear();
		check[i] = 0;
	}
}

void input() {
	for (int i = 0; i < E; i++) {
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		Node[n1].push_back(n2);
		Node[n2].push_back(n1);
	}
}

void dfs(int start) {
	if (!check[start]) {
		check[start] = 1;
	}
	int s_size = Node[start].size();
	for (int i = 0; i < s_size; i++) {
		int next = Node[start][i];
		if (!check[next]) {
			if (check[start] == 1) {
				check[next] = 2;
			}
			else if(check[start]==2) {
				check[next] = 1;
			}
			dfs(next);
		}
	}
}

bool isBipartite() {
	for (int i = 1; i <= V; i++) {
		int s_size = Node[i].size();
		for (int j = 0; j < s_size; j++) {
			int next = Node[i][j];
			if (check[i] == check[next])return false;
		}
	}
	return true;
}

int main() {

	scanf("%d", &K);
	for (int tc = 1; tc <= K; tc++) {
		scanf("%d %d", &V, &E);
		init();
		input();
		for (int i = 1; i <= V; i++) {
			if (!check[i])dfs(i);
		}
		if (isBipartite())printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}
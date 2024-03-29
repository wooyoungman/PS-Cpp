#include<iostream>
#include<map>

using namespace std;

map<int, int>m;
map<int, int>::iterator upper, lower;

int n;
long long int ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;

	m.insert({ 0,-1 });
	m.insert({ 300001,-1 });
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		upper = m.upper_bound(num);
		lower = upper--;
		int val = max(upper->second, lower->second) + 1;
		
		// 양 옆 노드의 깊이를 확인하여, 더 큰 깊이에 1을 더한 값을 depth로 지정
		m.insert({ num,val });
		ans += val;
		cout << ans << "\n";

	}
	

	return 0;
}
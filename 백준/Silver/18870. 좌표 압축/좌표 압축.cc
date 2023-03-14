#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector <int> s1;
vector <int> s2;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,data,cnt=0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> data;
		s1.push_back(data);
		s2.push_back(data);
	}
	// unique 함수는 정렬된 상태의 원소들의 중복된 원소들을 제거한다.
	// unique 함수는 중복된 원소들 중 첫번째 주소를 리턴한다.
	sort(s2.begin(), s2.end());
	s2.erase(unique(s2.begin(), s2.end()), s2.end());
	for (int i = 0; i < n; i++)
	{
		// lower_bound(first iterator,last iterator, value) 함수는
		// 벡터의 첫번째,마지막 이터레이터에서 value 이상의 값을 갖는 
		// 이터레이터를 반환한다. 인덱스를 반환 받기 위해서는
		// 벡터의 시작 주소를 빼주면 된다.
		cout<<lower_bound(s2.begin(), s2.end(), s1[i])-s2.begin()<<' ';
	}
	return 0;
}
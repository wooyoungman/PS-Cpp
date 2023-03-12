#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef struct {
	int age,idx;
	string name;
}box;
bool cmp(box& b1,box& b2)
{
	if (b1.age == b2.age)
	{
		return b1.idx < b2.idx;
	}
	return b1.age < b2.age;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	box*arr = new box[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].age >> arr[i].name;
		arr[i].idx = i;
	}
	sort(arr, arr + n, cmp);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i].age << ' ' << arr[i].name << "\n";
	}
	return 0;
}
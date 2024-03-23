#include<iostream>
#include<algorithm>
#include<climits>
#define MAX INT_MAX;
using namespace std;

int n,ans1, ans2;
int sum = MAX;
int arr[100001];
void bs() {
	int start = 0, end = n - 1;
	while (start < end) {
		int temp = arr[start] + arr[end];
		if (sum > abs(temp)) {
			sum = abs(temp);
			ans1 = arr[start];
			ans2 = arr[end];
			if (temp == 0)break;
		}
		if (temp < 0)start++;
		else end--;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr,arr+n);
	bs();
	cout << ans1 << " " << ans2;
	return 0;
}
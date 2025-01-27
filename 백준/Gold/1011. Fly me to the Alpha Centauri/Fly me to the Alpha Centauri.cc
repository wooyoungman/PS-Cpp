#include<iostream>
#include<cmath>
using namespace std;

int n;
int x, y;

// 1 
// 2
// 3 3 4 4
// 5 5 5 6 6 6
// 7 7 7 7 8 8 8 8 

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		int diff = y - x;
		if (diff == 1)cout << 1 << "\n";
		else {
			double num = sqrt(diff);
			int main_num = floor(num);
			double sub_num = num - main_num;
			//cout << main_num << " " << sub_num << "\n";
			int ans = main_num + (main_num - 1);
			if (sub_num >= 0.5)ans += 2;
			else if(sub_num>0)ans++;
			cout << ans << "\n";
		}
	}
	return 0;
}
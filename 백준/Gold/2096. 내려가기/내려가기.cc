#include<iostream>
#include<algorithm>


using namespace std;

int n;
int dpMax[3];
int dpMin[3];
int temp[3];
int main() {
	cin >> n;
	for (int i = 0; i < 3; i++) {
		int num;
		cin >> num;
		dpMax[i] = num;
		dpMin[i] = num;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> temp[j];
		}
		int tempMax0 = 0, tempMax1 = 0, tempMax2 = 0, tempMin0 = 0, tempMin1 = 0, tempMin2 = 0;
		for (int j = 0; j < 3; j++) {
			if (j == 0) {
				tempMax0 = max(dpMax[j] + temp[0], dpMax[j+1] + temp[0]);
				tempMin0 = min(dpMin[j] + temp[0], dpMin[j+1] + temp[0]);
			}
			else if (j == 1) {
				tempMax1 = max(dpMax[j-1] + temp[1], max(dpMax[j] + temp[1],dpMax[j+1]+temp[1]));
				tempMin1 = min(dpMin[j-1] + temp[1], min(dpMin[j] + temp[1],dpMin[j+1]+temp[1]));

			}
			else {
				tempMax2 = max(dpMax[j-1] + temp[2], dpMax[j] + temp[2]);
				tempMin2 = min(dpMin[j-1] + temp[2], dpMin[j] + temp[2]);

			}
		}

		dpMax[0] = tempMax0;
		dpMin[0] = tempMin0;
		dpMax[1] = tempMax1;
		dpMin[1] = tempMin1;
		dpMax[2] = tempMax2;
		dpMin[2] = tempMin2;
	}

	cout << *max_element(dpMax, dpMax + 3) << " " << *min_element(dpMin, dpMin + 3);

	return 0;
}
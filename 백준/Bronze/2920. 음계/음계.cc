#include <iostream>
using namespace std;

int main()
{
	int arr[8] = { 0, };
	int ascnt = 0, descnt = 0;

	for (int i = 0; i < 8; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < 7; i++)
	{
		if (arr[i] < arr[i + 1])
			ascnt++;
		else
			descnt++;
	}

	if (ascnt == 7)
		cout << "ascending";
	else if (descnt == 7)
		cout << "descending";
	else
		cout << "mixed";
	
	return 0;	
}
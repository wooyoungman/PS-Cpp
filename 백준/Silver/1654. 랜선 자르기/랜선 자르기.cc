#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#define INF 987654321
using namespace std;

long long line[10000];

long long K, N;
long long  answer;


void func(long long start, long long end)
{
	if (start > end )
	{
		return;
	}

	long long mid = (start + end) / 2;
	if (mid == 0)
	{
		mid=mid + 1;
	}
	//cout << mid << endl;
	long long temp = 0; //선개수
	long long temp2 = 0; //mid+1 선개수
	long long temp3 = 0;
	for (int i = 0; i < K; i++)
	{
		temp=temp+line[i] / mid;
	}

	for (int i = 0; i < K; i++)
	{
		temp2 = temp2 + line[i] / (mid+1);
	}

	/*
	for (int i = 0; i < K; i++)
	{
		temp3 = temp3 + line[i] / (mid -1);
	}*/

	//cout << temp <<" " << temp2 <<" "<<temp3 << endl;

	if (temp >= N && temp2<N)
	{
		answer = mid;
		return;
	}
	else if (temp>=N )
	{
		func(mid + 1, end);
		//cout << endl << "1" << endl;
		
	}
	else 
	{
		
		func(start, mid - 1);
		
	}

}



int main()
{
	cin >> K >> N;
	for (int i = 0; i < K; i++)
	{
		scanf("%d", &line[i]);
	}
	func(0, 21e9);
	cout << answer;
}




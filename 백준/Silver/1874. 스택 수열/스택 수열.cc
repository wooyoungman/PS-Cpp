#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<int> s;
vector<char>output;

int main() {
	
	int n,num,push_num=1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		while (push_num <= num)
		{
			s.push(push_num);
			push_num++;
			output.push_back('+');
		}
		if (s.top() == num)
		{
			s.pop();
			output.push_back('-');
		}
		else
		{
			cout << "NO";
			return 0;
		}
	}
	for (int i = 0; i < output.size(); i++)
	{
		cout << output[i] << "\n";
	}
	return 0;
}
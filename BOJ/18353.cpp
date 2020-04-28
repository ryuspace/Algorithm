//https://www.acmicpc.net/problem/18353
/*풀이 : 전형적인 LIS 문제.*/
#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;

int n;
int arr[2001];
vector<int> v;
int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		auto hi = lower_bound(v.begin(), v.end(), arr[i]);
		if (hi == v.end())
		{
			v.push_back(arr[i]);
		}
		else
		{
			*hi = arr[i];
		}
	}
	cout << n - v.size();
	return 0;
}

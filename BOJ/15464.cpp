//https://www.acmicpc.net/problem/15464
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int arr[101];
string cow[101];
string cow2[101];
string cow3[101];
string cow4[101];
vector < pair<int, string> > v;
int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> cow[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j == arr[i])
			{
				cow2[i] = cow[j - 1];
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j == arr[i])
			{
				cow3[i] = cow2[j - 1];
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j == arr[i])
			{
				cow4[i] = cow3[j - 1];
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << cow4[i] << '\n';
	}


	return 0;
}

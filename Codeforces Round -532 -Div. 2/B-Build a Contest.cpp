//https://codeforces.com/contest/1100/problem/B
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int arr[10001];
bool visit[10001];
int n, m;
bool check()
{
	for (int i = 1; i <= n; i++)
	{
		if (!visit[i])
			return 0;
	}
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i <= m; i++)
	{
		visit[arr[i]] = true;
		if (check())
		{
			cout << "1";
			memset(visit, 0, sizeof(visit));
		}
		else
		{
			cout << "0";
		}
	}

	return 0;
}

//https://www.acmicpc.net/problem/18442
/*
풀이 : 그냥 dfs.............................. 자료형 주의
*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long int v, p;
long long int l;
long long int my_wo[21];
long long int arr[21];
bool visit[21];
long long int wo[21];
long long int minn = 1e18;
long long int calc(long long int a, long long int b)
{
	return min(abs(a - b), l - abs(a - b));
}
void check()
{

	long long int sum = 0;
	for (int i = 0; i < v; i++)
	{
		long long int mini = 1e9;
		for (int j = 0; j < p; j++)
		{
			mini = min(mini, calc(arr[i], wo[j]));
		}
		sum += mini;
	}
	if (minn > sum)
	{
		minn = sum;
		for (int i = 0; i < p; i++)
		{
			my_wo[i] = wo[i];
		}
	}

}
void dfs(int idx,int cnt)
{
	if (cnt == p)
	{
		check();
		return;
	}
	if (idx == v)
	{
		return;
	}
	for (int i = idx; i < v; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			wo[cnt] = arr[i];
			dfs(i+1, cnt + 1);
			visit[i] = false;
		}
	}
}
int main(void)
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> v >> p >> l;
	for (int i = 0; i < v; i++)
	{
		cin >> arr[i];
	}

	dfs(0, 0);
	cout << minn<<'\n';
	for (int i = 0; i < p; i++)
	{
		cout << my_wo[i] << " ";
	}
	return 0;
}

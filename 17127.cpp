//https://www.acmicpc.net/problem/17127
/*풀이 : dfs를 이용해 나무의 갯수를 4개로 나눌 수 있는 모든 경우를 찾는다.*/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int n;
int jemul[5];
int flower[11];
int play()
{
	int jemul2[5];
	for (int i = 0; i < 4; i++)
	{
		jemul2[i] = jemul[i];
	}

	for (int i = 1; i < 4; i++)
	{
		jemul[i] += jemul[i - 1];
	}
	int res1 = 1;
	int res2 = 1;
	int res3 = 1;
	int res4 = 1;
	for (int i = 0; i < jemul[0]; i++)
	{
		res1 *= flower[i];
	}
	for (int i = jemul[0]; i < jemul[1]; i++)
	{
		res2 *= flower[i];
	}
	for (int i = jemul[1]; i < jemul[2]; i++)
	{
		res3 *= flower[i];
	}
	for (int i = jemul[2]; i < jemul[3]; i++)
	{
		res4 *= flower[i];
	}
	for (int i = 0; i < 4; i++)
	{
		jemul[i] = jemul2[i];
	}
	return res1 + res2 + res3 + res4;

}
int maxx = 0;
void dfs(int cnt)
{
	if (cnt==4)
	{
		int sum = 0;
		for (int i = 0; i < 4; i++)
		{
			sum += jemul[i];
		}
		if (sum != n)
			return;
		maxx = max(maxx, play());
		return;
	}
	for (int i = 1; i <= 7 ;i++)
	{
		jemul[cnt] = i;
		dfs(cnt + 1);
		jemul[cnt] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> flower[i];
	}
	dfs(0);
	cout << maxx;
	return 0;
}

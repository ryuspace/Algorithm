//https://www.acmicpc.net/problem/14620
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

bool visit[12][12];
int map[12][12];
int n;
int price = 0;
int Min = 999999;
void dfs(int cnt,int hap)
{
	if (cnt == 3)
	{
		if (hap < Min)
		{
			Min = hap;
		}
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (!visit[i][j] && !visit[i + 1][j] && !visit[i - 1][j] &&
				!visit[i][j + 1] && !visit[i][j - 1])//나, 상하좌우
			{
				visit[i][j] = true;
				visit[i + 1][j] = true;
				visit[i - 1][j] = true;
				visit[i][j + 1] = true;
				visit[i][j - 1] = true;
				price = map[i][j] + map[i + 1][j] + map[i - 1][j] + map[i][j + 1] + map[i][j - 1];
				dfs(cnt + 1,hap+price);
				visit[i][j] = false;
				visit[i + 1][j] = false;
				visit[i - 1][j] = false;
				visit[i][j + 1] = false;
				visit[i][j - 1] = false;

			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	cin >> n;
	for (int i = 0; i <= n+1; i++)
	{
		for (int j = 0; j <= n+1; j++)
		{
			visit[i][j] = true;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
			visit[i][j] = false;
		}
	}
	dfs(0,0);
	cout << Min;
	return 0;
}

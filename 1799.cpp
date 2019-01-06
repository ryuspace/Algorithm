//https://www.acmicpc.net/problem/1799
#include<iostream>
#include<algorithm>

/* 풀이 : 1이면 비숍을 놓을 수 있다. 0이면 비숍은 놓을 수는 없지만 비숍이 지나갈 수 있다.
visit이 true면 이미 비숍이 존재하는 것.  맵을 대각선으로 탐색한다. 대각선으로 탐색하다가
비숍을 놓을 자리가 있으면 다음 열로 건너뛴다. 대각선 하나에는 최대 하나의 비숍만 있을 수 
있다.*/

using namespace std;
int map[12][12];
bool visit[12][12];
int n;
int Max;
bool flag = false;
bool check(int i, int j)
{
	//왼쪽 위 대각선
	while (i >= 1 && j >= 1)
	{
		if (visit[i][j])
			return 0;
		i = i - 1;
		j = j - 1;
	}
	return 1;
}

void dfs(int m, int cnt)
{
	if (m == 2 * n)
	{
		if (cnt > Max)
		{
			Max = cnt;
		}
		return;
	}
	bool flag = false;
	int i;
	int j;
	if (cnt > Max)
	{
		Max = cnt;
	}
	if (m <= n)
	{
		i = 1;
		j = m;
	}
	else
	{
		i = m - n + 1;
		j = n;
	}
	while (j >= 1 && i <= n )
	{
		if (visit[i][j] == false && map[i][j] == 1)
		{
			if (check(i, j))
			{
				visit[i][j] = true;
				dfs(m + 1, cnt + 1);
				visit[i][j] = false;
				flag=true;
			}
		}
		i = i + 1;
		j = j - 1;
	}
	if (!flag)
	{
		dfs(m + 1, cnt);
	}

}
int main()
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
		}
	}
	dfs(1, 0);
	cout << Max;

	return 0;
}

//https://www.acmicpc.net/problem/1799
#include<iostream>
#include<algorithm>

//1이면 비숍을 놓을 수 있다. 0이면 비숍은 놓을 수는 없지만 비숍이 지나갈 수 있다.
//visit이 true면 이미 비숍이 존재하는 것. 
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

void dfs(int m,int cnt)
{
	if (m == 2 * n)
	{
		if (cnt > Max)
		{
			Max = cnt;
		}
		return;
	}
	int check_cnt = 0;
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
	else//m이 n을 넘으면 탐색 인덱스를 바꿔야한다.
	{
		i = m - n + 1;
		j = n;
	}
	while (i >= 1 && j >= 1 && i <= n && j <= n)
	{
		if (visit[i][j] == false && map[i][j] == 1)
		{
			if (check(i, j))
			{
				visit[i][j] = true;
				dfs(m + 1, cnt + 1);
				visit[i][j] = false;
				check_cnt++;
			}
		}
		i = i + 1;
		j = j - 1;
	}
	if (check_cnt == 0)
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
	dfs(1,0);
	cout << Max;

	return 0;
}

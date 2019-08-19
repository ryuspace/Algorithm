//https://www.acmicpc.net/problem/16926
/*풀이 : 
남동북서 방향으로 (n,n)을 시작으로 dfs를 돌린다.
예외처리.. 2X2돌릴때 북에서 서로 갔는데 시작점이다.
시간이 너무 많이 걸리므로 다른 시리즈에는 좀 더 개선해보자.
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int value;
int n, m, r;
int tmp[301][301];
int arr[301][301];
bool visit[301][301];
//남동북서
bool check(int x, int y)
{
	if (x >= 0 && x < n && y >= 0 && y < m)
		return true;
	else
		return false;
}
void mov(int x, int y, int dir)
{
	visit[x][y] = true;
	if (dir == 0)
	{
		if (!visit[x + 1][y] && check(x + 1, y))
		{
			arr[x + 1][y] = tmp[x][y];
			mov(x + 1, y, 0);
		}
		else if (!visit[x][y + 1] && check(x, y + 1))
		{
			arr[x][y + 1] = tmp[x][y];
			mov(x, y + 1, 1);
		}
		return;
	}
	else if (dir == 1)
	{
		if (!visit[x][y + 1] && check(x, y + 1))
		{
			arr[x][y + 1] = tmp[x][y];
			mov(x, y + 1, 1);
		}
		else if (!visit[x - 1][y] && check(x - 1, y))
		{
			arr[x - 1][y] = tmp[x][y];
			mov(x - 1, y, 2);
		}
		return;
	}
	else if (dir == 2)
	{
		if (!visit[x - 1][y] && check(x - 1, y))
		{
			arr[x - 1][y] = tmp[x][y];
			mov(x - 1, y, 2);
		}
		else if (!visit[x][y - 1] && check(x, y - 1))
		{
			arr[x][y - 1] = tmp[x][y];
			mov(x, y - 1, 3);
		}
		else if (visit[x][y - 1] && check(x, y - 1))
		{
			arr[x][y - 1] = tmp[x][y];
			return;
		}

	}
	else if (dir == 3)
	{
		if (!visit[x][y - 1] && check(x, y - 1))
		{
			arr[x][y - 1] = tmp[x][y];
			mov(x, y - 1, 3);
		}
		else if (visit[x][y - 1] && check(x, y - 1))
		{
			arr[x][y - 1] = tmp[x][y];
			return;
		}
	}
}
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> r;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			tmp[i][j] = arr[i][j];
		}
	}
	while (r--)
	{
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < min(n,m); i++)
		{
			if (!visit[i][i])
				mov(i, i, 0);
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				tmp[i][j] = arr[i][j];
			}
		}

	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}

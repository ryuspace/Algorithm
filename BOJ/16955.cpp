//https://www.acmicpc.net/problem/16955
/*풀이 : 완탐..  가능한 모든 .인 위치에 돌을 둬보고
오목판의 처음부터 끝까지 탐색해서 이길 수 있는지 없는지 찾는다.
시간복잡도 : 10^4*8*5 */
#include <iostream>
#include <algorithm>

using namespace std;

char arr[10][10];

bool dfs(int r,int c,int dir,int cnt)
{
	if (r < 0 || r >= 10 || c < 0 || c >= 10 ||arr[r][c]!='X')
	{
		return false;
	}
	if (cnt == 4)
	{
		return true;
	}
	if (dir == 0)
	{
		dfs(r - 1, c, dir, cnt + 1);
	}
	else if (dir == 1)
	{
		dfs(r - 1, c+1, dir, cnt + 1);
	}
	else if (dir == 2)
	{
		dfs(r, c+1, dir, cnt + 1);
	}
	else if (dir == 3)
	{
		dfs(r + 1, c+1, dir, cnt + 1);
	}
	else if (dir == 4)
	{
		dfs(r +1, c, dir, cnt + 1);
	}
	else if (dir == 5)
	{
		dfs(r +1, c-1, dir, cnt + 1);
	}
	else if (dir == 6)
	{
		dfs(r, c-1, dir, cnt + 1);
	}
	else if (dir == 7)
	{
		dfs(r - 1, c-1, dir, cnt + 1);
	}
}
int main()
{
	//freopen("t.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (arr[i][j] == '.')
			{
				arr[i][j] = 'X';
				for (int k = 0; k < 10; k++)
				{
					for (int t = 0; t < 10; t++)
					{
						for (int r = 0; r < 8; r++)
						{
							if (dfs(k, t, r, 0))
							{
								cout << 1;
								exit(0);
							}
						}
					}
				}
				arr[i][j] = '.';
			}
		}
	}
	cout << 0;
	return 0;
}

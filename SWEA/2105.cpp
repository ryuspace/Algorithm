/*2105번 디저트 카페
풀이 : 어떤 좌표에서 밑으로 사각형을 그리는데
가능한 모든 사각형을 그려본다.
*/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int arr[21][21];
int t;
int maxi;

int dx[4] = { 1,1,-1,-1 };
int dy[4] = { 1,-1,-1,1 };
bool visit[101];

void dfs(int start_x, int start_y, int x, int y, int dir,int cnt)
{
	if (x < 0 || x >= n || y < 0 || y >= n)
		return;
	if (start_x == x && start_y == y && dir==3)
	{
		maxi = max(maxi, cnt);
		return;
	}
	if (!visit[arr[x][y]])
	{
		visit[arr[x][y]] = true;
		if (dir == 0)
		{
			dfs(start_x, start_y, x + dx[0], y + dy[0], 0, cnt + 1);
			dfs(start_x, start_y, x + dx[1], y + dy[1], 1, cnt + 1);
		}
		else if (dir == 1)
		{
			dfs(start_x, start_y, x + dx[1], y + dy[1], 1, cnt + 1);
			dfs(start_x, start_y, x + dx[2], y + dy[2], 2, cnt + 1);
		}
		else if (dir == 2)
		{
			dfs(start_x, start_y, x + dx[2], y + dy[2], 2, cnt + 1);
			dfs(start_x, start_y, x + dx[3], y + dy[3], 3, cnt + 1);
		}
		else if (dir == 3)
		{
			dfs(start_x, start_y, x + dx[3], y + dy[3], 3, cnt + 1);
		}
		visit[arr[x][y]] = false;
	}
}
int main()
{
	//freopen("Test.txt", "r", stdin);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);

	cin >> t;
	for (int q = 1;q <= t;q++)
	{
		maxi = 0;
		cin >> n;
		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < n;j++)
			{
				cin >> arr[i][j];
			}
		}
		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < n;j++)
			{
				dfs(i, j, i, j, 0, 0);
			}
		}
		if (maxi == 0)
		{
			cout << "#" << q << " " << -1 << '\n';
		}
		else
		{
			cout << "#" << q << " " << maxi << '\n';
		}

	}

	return 0;
}

//https://www.acmicpc.net/problem/17406
/*풀이 : dfs를 이용하여 연산 위치의 순서를 선택해주고 시뮬레이션 해준다.
배열돌리기 1을 풀더니 수월하게 해결하였다.
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

struct point {
	int a, b, siz;
};

int sunsu[7];
int n, m,k;
int arr[51][51];
int tmp[51][51];
int si[51][51];
bool visit[51][51];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
vector<point> v;

bool check(int x, int y,int siz)
{
	if (x >= 0 && x < 2 * siz + 1 && y >= 0 && y < 2 * siz + 1)
	{
		return true;
	}
	return false;
}
void dfs(int x, int y, int dir,int siz)
{
	visit[x][y] = true;
	if (dir == 0)
	{
		if (check(x, y + 1, siz) && !visit[x][y + 1])
		{
			si[x][y + 1] = tmp[x][y];
			dfs(x, y + 1, 0, siz);
		}
		else if (check(x + 1, y, siz) && !visit[x + 1][y])
		{
			si[x + 1][y] = tmp[x][y];
			dfs(x + 1, y, 1, siz);
		}
	}
	else if (dir == 1)
	{
		if (check(x + 1, y, siz) && !visit[x + 1][y])
		{
			si[x + 1][y] = tmp[x][y];
			dfs(x + 1, y, 1, siz);
		}
		else if (check(x, y - 1, siz) && !visit[x][y - 1])
		{
			si[x][y - 1] = tmp[x][y];
			dfs(x, y - 1, 2, siz);
		}
	}
	else if (dir == 2)
	{
		if (check(x, y - 1, siz) && !visit[x][y - 1])
		{
			si[x][y - 1] = tmp[x][y];
			dfs(x, y - 1, 2, siz);
		}
		else if (check(x - 1, y, siz) && visit[x - 1][y])
		{
			si[x-1][y] = tmp[x][y];
		}
		else if (check(x - 1, y, siz) && !visit[x - 1][y])
		{
			si[x-1][y] = tmp[x][y];
			dfs(x - 1, y, 3, siz);
		}
	}
	else if (dir == 3)
	{
		if (check(x - 1, y, siz) && !visit[x - 1][y])
		{
			si[x - 1][y] = tmp[x][y];
			dfs(x - 1, y, 3, siz);
		}
		else if (check(x - 1, y, siz )&& visit[x - 1][y])
		{
			si[x - 1][y] = tmp[x][y];
		}
	}
}
void magic(int r, int c,int siz)
{
	memset(visit, 0, sizeof(visit));
	int min_x = r - siz;
	int max_x = r + siz;
	int min_y = c - siz;
	int max_y = c + siz;
	tmp[51][51] = { 0, };
	for (int i = min_x; i <= max_x; i++)
	{
		for (int j = min_y; j <= max_y; j++)
		{
			si[i-min_x][j-min_y]=tmp[i - min_x][j - min_y] = arr[i][j];
		}
	}
	for (int i = 0; i < 2 * siz + 1; i++)
	{
		if(!visit[i][i])
			dfs(i, i, 0,siz);
	}
	for (int i = min_x; i <= max_x; i++)
	{
		for (int j = min_y; j <= max_y; j++)
		{
			arr[i][j] = si[i - min_x][j - min_y];
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int copy[51][51];
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			copy[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i < k; i++)
	{
		sunsu[i] = i;
		int a, b, siz;
		cin >> a >> b >> siz;
		v.push_back({ a,b,siz });
	}

	int minn = 1e9;
	do
	{
		for (int t = 0; t < v.size(); t++)
		{
			magic(v[sunsu[t]].a-1, v[sunsu[t]].b-1, v[sunsu[t]].siz);
		}

		for (int i = 0; i < n; i++)
		{
			int sum = 0;
			for (int j = 0; j < m; j++)
			{
				sum += arr[i][j];
			}
			minn = min(minn, sum);
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				arr[i][j] = copy[i][j];
			}
		}
	} while (next_permutation(sunsu, sunsu+k));

	
	cout << minn;
	return 0;
}

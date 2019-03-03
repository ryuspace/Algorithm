//https://www.acmicpc.net/problem/15683
/*카메라가 감시할 수 있는 모든 방향을 dfs를 이용해 체크해본다. 이전 상태 map을 유지하는것 중요*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef pair<int, int> pii;
int arr[9][9];
vector <pii> v;
int n, m;


void up(int x, int y)
{
	x--;
	while (x >= 0)
	{
		if (arr[x][y] == 6)
			break;
		else if (arr[x][y] == 0 || arr[x][y]==7)
		{
			arr[x][y] = 7;
		}
		x--;
	}
}
void down(int x, int y)
{
	x++;
	while (x < n)
	{
		if (arr[x][y] == 6)
			break;
		else if (arr[x][y] == 0 || arr[x][y] == 7)
		{
			arr[x][y] = 7;
		}
		x++;
	}

}
void left(int x, int y)
{
	y--;
	while (y>=0)
	{
		if (arr[x][y] == 6)
			break;
		else if (arr[x][y] == 0 || arr[x][y] == 7)
		{
			arr[x][y] = 7;
		}
		y--;
	}
}
void right(int x, int y) 
{
	y++;
	while (y < m)
	{
		if (arr[x][y] == 6)
			break;
		else if (arr[x][y] == 0 || arr[x][y] == 7)
		{
			arr[x][y] = 7;
		}
		y++;
	}
}
void fun(int x,int y,int num,int dir)
{
	if (num == 1)
	{
		if (dir == 0)
		{
			up(x, y);
		}
		else if (dir == 1)
		{
			down(x, y);
		}
		else if (dir == 2)
		{
			left(x, y);
		}
		else
		{
			right(x, y);
		}
	}
	else if (num == 2)
	{
		if (dir == 0)
		{
			up(x, y);
			down(x, y);
		}
		else if (dir == 1)
		{
			left(x, y);
			right(x, y);
		}
	}
	else if (num == 4)
	{
		if (dir == 0)
		{
			up(x, y);
			left(x, y);
			right(x, y);
		}
		else if (dir == 1)
		{
			up(x, y);
			left(x, y);
			down(x, y);
		}
		else if (dir == 2)
		{
			up(x, y);
			down(x, y);
			right(x, y);
		}
		else
		{
			down(x, y);
			left(x, y);
			right(x, y);
		}
	}
	else if (num == 3)
	{
		if (dir == 0)
		{
			up(x, y);
			right(x, y);
		}
		else if (dir == 1)
		{
			down(x, y);
			right(x, y);
		}
		else if (dir == 2)
		{
			left(x, y);
			down(x, y);
		}
		else
		{
			up(x, y);
			left(x, y);
		}
	}
	else
	{
		if (dir == 0)
		{
			up(x, y);
			down(x, y);
			left(x, y);
			right(x, y);
		}
	}
}


int minn = 1e9;

void ans(int num)
{
	int tmp[9][9];
	int cntt = 0;
	if (num == v.size())
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == 0)
				{
					cntt++;
				}
			}
		}
		minn = min(minn, cntt);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			tmp[i][j] = arr[i][j];
		}
	}
	if (arr[v[num].first][v[num].second] == 1 ||
		arr[v[num].first][v[num].second] == 3 ||
		arr[v[num].first][v[num].second] == 4 )
	{
		for (int j = 0; j < 4; j++)
		{
			fun(v[num].first,v[num].second,arr[v[num].first][v[num].second], j);
			ans(num + 1);
			for (int k = 0; k < n; k++)
			{
				for (int r = 0; r < m; r++)
				{
					arr[k][r] = tmp[k][r];
				}
			}

		}
	}
	else if (arr[v[num].first][v[num].second] == 2)
	{
		for (int j = 0; j < 2; j++)
		{
			fun(v[num].first, v[num].second, arr[v[num].first][v[num].second], j);
			ans(num + 1);
			for (int k = 0; k < n; k++)
			{
				for (int r = 0; r < m; r++)
				{
					arr[k][r] = tmp[k][r];
				}
			}
		}
	}
	else
	{
		fun(v[num].first, v[num].second, arr[v[num].first][v[num].second], 0);
		ans(num + 1);
		for (int k = 0; k < n; k++)
		{
			for (int r = 0; r < m; r++)
			{
				arr[k][r] = tmp[k][r];
			}
		}
	}
}
int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] >= 1 && arr[i][j] <= 5)
			{
				v.push_back({ i,j });
			}
		}
	}
	ans(0);
	cout << minn;
}

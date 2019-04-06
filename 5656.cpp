/* 5656번 벽돌깨기
풀이 : dfs를 이용해 구슬을 떨어뜨릴 수 있는 가능한 모든 위치를 구하고
bfs를 이용해 벽돌을 폭파시킨다. 
가능한 모든 위치를 선정한 후 벽돌을 폭파시키면 시간이 많이 걸리므로..
위치를 하나 선정할 때 마다 벽돌을 폭파시킨다.*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int t, n, w, h;
int arr[16][13];
bool visit[13];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
struct point
{
	int x, y, num;
};

void mov()
{
	for (int i = 0; i < w; i++)
	{
		vector<int> v;
		for (int j = h - 1; j >= 0; j--)
		{
			if (arr[j][i] != 0)
			{
				v.push_back(arr[j][i]);
				arr[j][i] = 0;
			}
		}
		for (int j = 0; j < v.size(); j++)
		{
			arr[h - 1 - j][i] = v[j];
		}
	}
}

int where(int num)
{
	for (int i = 0; i < h; i++)
	{
		if (arr[i][num] != 0)
			return i;
	}
	return -1;
}

int cntt()
{
	int cnt = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (arr[i][j] != 0)
				cnt++;
		}
	}
	return cnt;
}
int minn = 1e9;
void dfs(int cnt)
{
	int won[16][13];
	for (int m = 0; m < h; m++)
	{
		for (int j = 0; j < w; j++)
		{
			won[m][j] = arr[m][j];
		}
	}
	if (cnt == n)
	{
		minn = min(minn, cntt());
		return;
	}
	for (int i = 0; i < w; i++)
	{
		queue<point> q;
		int num = where(i);
		if (num != -1)
		{
			q.push({ num,i,arr[num][i] });
			while (!q.empty())
			{
				point front = q.front();
				q.pop();
				arr[front.x][front.y] = 0;
				int rept = front.num;
				for (int j = 0; j < 4; j++)
				{
					int nx = front.x;
					int ny = front.y;
					for (int r = 0; r < rept - 1; r++)
					{
						nx += dx[j];
						ny += dy[j];
						if (nx >= 0 && nx < h &&ny >= 0 && ny < w &&arr[nx][ny] != 0)
						{
							if (arr[nx][ny] > 1)
							{
								q.push({ nx,ny,arr[nx][ny] });
							}
							arr[nx][ny] = 0;
						}
					}

				}
			}
		}
		mov();
		dfs(cnt + 1);
		for (int m = 0; m < h; m++)
		{
			for (int j = 0; j < w; j++)
			{
				arr[m][j] = won[m][j];
			}
		}

	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> t;
	for (int r = 1; r <= t; r++)
	{
		memset(visit, sizeof(visit), 0);
		minn = 1e9;
		cin >> n >> w >> h;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> arr[i][j];
			}
		}
		dfs(0);
		cout << "#" << r << " " << minn << '\n';

	}
	return 0;
}

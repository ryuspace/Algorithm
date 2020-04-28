//https://www.acmicpc.net/problem/1012
/*풀이 : 전형적인 bfs 문제 . 가로와 세로 좌표 주의*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

bool visit[51][51];
int arr[51][51];
int m, n, k;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
typedef pair<int, int> pii;
void bfs(int x,int y)
{
	visit[x][y] = true;
	queue <pii> q;
	q.push({ x,y });
	while (!q.empty())
	{
		pii front = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + front.first;
			int ny = dy[i] + front.second;
			if (nx >= 0 && nx < n && ny >= 0 && ny < m &&!visit[nx][ny] &&arr[nx][ny]==1)
			{
				q.push({ nx,ny });
				visit[nx][ny] = true;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int r = 0; r < t; r++)
	{
		int cnt = 0;
		memset(arr, 0, sizeof(arr));
		memset(visit, false, sizeof(visit));
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++)
		{
			int x, y;
			cin >> x >> y;
			arr[y][x] = 1;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == 1 && !visit[i][j])
				{
					bfs(i,j);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}

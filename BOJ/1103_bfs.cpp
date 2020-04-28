//https://www.acmicpc.net/problem/1103
/*풀이 : bfs로 조건에 맞으면 이동시켜준다. n*m번 이동했는데도 bfs가 돌아간다면 무한번
돈다고 간주할 수 있다. */
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
struct point
{
	int x, y;
};
int n, m;
char arr[51][51];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int bfs(int x, int y)
{
	int cnt = 0;
	queue <point> q;
	int visit[51][51] = { 0, };
	q.push({ x,y });
	visit[x][y] = true;
	visit[x][y] = true;
	visit[x][y] = true;
	visit[x][y] = true;
	while (!q.empty())
	{
		int sizz = q.size();
		while (sizz--)
		{
			point front = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = dx[i]*(arr[front.x][front.y]-'0') + front.x;
				int ny = dy[i] * (arr[front.x][front.y]-'0') + front.y;

				if (nx >= 0 && nx < n && ny >= 0 && ny < m &&visit[nx][ny]<cnt+1&&arr[nx][ny]!='H')
				{
					q.push({ nx,ny });
					visit[nx][ny] = cnt+1;
				}
			}
		}
		cnt++;
		if (cnt > n * m)
			return -1;
	}
	return cnt;
}
int main()
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = tmp[j];
		}
	}
	cout<<bfs(0, 0);
	return 0;
}


//https://www.acmicpc.net/problem/17144
/*
풀이 : bfs + 구현 
공기청소기가 돌면서 얻는 먼지를 큐에 넣고 그 경로를 다시 넣어 큐에 있는 값을 한 칸씩 밀리게 배열에 넣는다.
*/
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
pii le = { -1,-1 }, ri = { -1,-1 };
int r, c, t;
int arr[51][51];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };//동북서남

struct point
{
	int x, y, value;
};
void bfs(queue<point> q)
{
	while (!q.empty())
	{
		point front = q.front();
		q.pop();
		int cnt = 0;
		int value = front.value;
		for (int i = 0; i < 4; i++)
		{
			int nx = front.x + dx[i];
			int ny = front.y + dy[i];
			if (nx >= 0 && nx < r && ny >= 0 && ny < c && arr[nx][ny] != -1)
			{
				arr[nx][ny] += value / 5;
				cnt++;
			}
		}
		arr[front.x][front.y] += value - (value / 5) * cnt;
	}
}
void wash()
{
	int R = r;
	int C = c;
	queue<int> qq;
	int x = le.first;
	int y = le.second;
	int dir = 0;
	while (!(x == le.first - 2 && y == le.second))
	{

		x += dx[dir];
		y += dy[dir];
		if (x < 0 || x >= R || y < 0 || y >= C)
		{
			x -= dx[dir];
			y -= dy[dir];
			dir = (dir + 1) % 4;
			x += dx[dir];
			y += dy[dir];
		}
		qq.push(arr[x][y]);
	}

	arr[le.first][le.second + 1] = 0;
	x = le.first;
	y = le.second+1;
	dir = 0;
	while (!(x == le.first-1 && y == le.second))
	{

		x += dx[dir];
		y += dy[dir];
		if (x < 0 || x >= R || y < 0 || y >= C)
		{
			x -= dx[dir];
			y -= dy[dir];
			dir = (dir + 1) % 4;
			x += dx[dir];
			y += dy[dir];

		}
		arr[x][y] = qq.front();
		qq.pop();	
	}
	x = ri.first;
	y = ri.second;
	dir = 0;
	while (!(x == ri.first +2 && y == ri.second))
	{
		
		x += dx[dir];
		y += dy[dir];
		if (x < 0 || x >= R || y < 0 || y >= C)
		{
			x -= dx[dir];
			y -= dy[dir];
			dir = (dir + 3) % 4;
			x += dx[dir];
			y += dy[dir];
		}
		qq.push(arr[x][y]);
	}
	arr[ri.first][ri.second + 1] = 0;
	x = ri.first;
	y = ri.second + 1;
	dir = 0;

	while (!(x == ri.first +1 && y == ri.second))
	{
		x += dx[dir];
		y += dy[dir];
		if (x < 0 || x >= R || y < 0 || y >= C)
		{
			x -= dx[dir];
			y -= dy[dir];
			dir = (dir + 3) % 4;
			x += dx[dir];
			y += dy[dir];

		}
		arr[x][y] = qq.front();
		qq.pop();
	}
	//arr[le.first][le.second] = -1;
	//arr[ri.first][ri.second] = -1;
}
int main()
{
	//freopen("Text.txt", "r", stdin);
	scanf("%d %d %d", &r, &c, &t);
	int R = r;
	int C = c;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == -1 && le.first == -1 && le.second==-1)
			{
				le = { i,j };
			}
			else if (arr[i][j] == -1 && !(le.first == -1 && le.second == -1))
			{
				ri = { i,j };
			}
		}
	}
	for (int y = 1; y<= t;y++)//t초 동안 확산 시키고 공기청정기 작동시킨다.
	{
		queue <point> q;
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (arr[i][j] != 0 && arr[i][j] != -1)
				{
					q.push({ i,j,arr[i][j] });
					arr[i][j] = 0;
				}
			}
		}
		bfs(q);
		wash();
	}
	int sum = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (arr[i][j] != -1)
				sum += arr[i][j];
		}
	}
	printf("%d", sum);
	return 0;
}

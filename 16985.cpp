//https://www.acmicpc.net/problem/16985
/*풀이 : dfs를 이용해서 큐브가 쌓일 수 있는 모든 경우를 탐색 하고, 그 탐색 중에 큐브를
돌릴 수 있는 모든 가능한 경우도 탐색한다.*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
typedef struct{
	int x, y, z;
}point;
int arr[5][5][5];
int maze[5][5][5];
int visit[5];
bool mapp[5][5][5];
int maxx = 1e9;

int dx[6] = { 0,0,0,0,-1,1 };
int dy[6] = { -1,1,0,0,0,0 };
int dz[6] = { 0,0,1,-1,0,0 };
int bfs()
{
	int cnt = 0;
	queue <point> q;
	q.push({ 0,0,0 });
	memset(mapp, false, sizeof(mapp));
	while (!q.empty())
	{
		int sizz = q.size();
		while (sizz--)
		{
			point front = q.front();
			mapp[front.x][front.y][front.z] = true;
			q.pop();
			for (int i = 0; i < 6; i++)
			{
				int nx = front.x + dx[i];
				int ny = front.y + dy[i];
				int nz = front.z + dz[i];
				if (nx == 4 && ny == 4 && nz == 4)
				{
					return cnt+1;
				}
				if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5
					&& nz >= 0 && nz < 5 && maze[nx][ny][nz]==1 && mapp[nx][ny][nz]==false)
				{
					q.push({ nx,ny,nz });
					mapp[nx][ny][nz] = true;
				}
			}
		}
		cnt++;
	}
	return 1e9;
}
void rotate(int num,int cntt)
{
	int tmp[5][5][5];
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			tmp[num][i][j] = arr[num][4 - j][i];
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arr[num][i][j] = tmp[num][i][j];//돌린거 다시 복사
			maze[cntt][i][j] = arr[num][i][j];
		}
	}

}
void dfs(int cnt)
{
	if (cnt == 5)
	{
		if (maze[0][0][0] == 1 && maze[4][4][4] == 1)
		{
			maxx = min(bfs(), maxx);
		}
		return;
	}
	for (int i = 0; i < 5; i++)//i번째 큐브부터 차곡 차곡 쌓을 거다.
	{
		if (visit[i] == false)
		{
			visit[i] = true;
			for (int j = 0; j < 4; j++)//4방향으로 돌리자.
			{
				rotate(i,cnt);
				dfs(cnt + 1);
			}
			visit[i] = false;
		}
		
	}
}
int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int r = 0; r < 5; r++)
			{
				cin >> arr[i][j][r];
			}
		}
	}
	dfs(0);
	if (maxx == 1e9)
		cout << -1;
	else
		cout << maxx;

	return 0;
}

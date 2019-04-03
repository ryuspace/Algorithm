//https://www.acmicpc.net/problem/3055
/*풀이 : 물에 대한 bfs를 먼저 돌려서 몇 분에 물이 이 위치에 오는지 시간을 표시해준다.
그리고 고슴도치에 대한 bfs를 돌려서 물이 오기전에 고슴도치가 갈 수 있는지 시간을 체크해준다.*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;
char arr[51][51];
int mov[51][51];
bool visit[51][51];
queue<pii> water;
queue<pii> ani;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int r, c;
void bfs_w()
{
	int cnt = 0;
	while (!water.empty())
	{
		int sizz = water.size();
		while (sizz--)
		{
			pii front = water.front();
			visit[front.first][front.second] = true;
			if (mov[front.first][front.second] == 1e9)
			{
				mov[front.first][front.second] = 0;
			}
			water.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = front.first + dx[i];
				int ny = front.second + dy[i];
	
				if (nx >= 0 && nx < r && ny >= 0 && ny < c &&
					!visit[nx][ny] && arr[nx][ny]=='.')
				{
					water.push({ nx,ny });
					visit[nx][ny] = true;
					mov[nx][ny] = cnt + 1;
				}
			}
		}
		cnt++;
	}
}
void bfs_a()
{
	memset(visit, 0, sizeof(visit));
	int cnt = 0;
	while (!ani.empty())
	{
		int sizz = ani.size();
		while (sizz--)
		{
			pii front = ani.front();
			ani.pop();
			if (arr[front.first][front.second] == 'D')
			{
				cout << cnt;
				exit(0);
			}
			visit[front.first][front.second] = true;
			for (int i = 0; i < 4; i++)
			{
				int nx = front.first + dx[i];
				int ny = front.second + dy[i];
				if (nx >= 0 && nx < r && ny >= 0 && ny < c &&
					arr[nx][ny]!='X'&&
					!visit[nx][ny] && cnt+1 < mov[nx][ny])
				{
					ani.push({ nx,ny });
					visit[nx][ny] = true;
				}
			}
		}
		cnt++;
	}
	cout << "KAKTUS";
}
int main()
{
	ios_base::sync_with_stdio(0);

	
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			mov[i][j] = 1e9;
		}
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == '*')
				water.push({ i,j });
			if (arr[i][j] == 'S')
			{
				ani.push({ i,j });
				arr[i][j] = '.';
			}
		}
	}
	bfs_w();
	bfs_a();
}

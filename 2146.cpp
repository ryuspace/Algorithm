//https://www.acmicpc.net/problem/2146
/*풀이 : 우선 섬들을 구분할 수 있게 bfs를 돌려 섬마다 다른 숫자로 덮는다. 그리고 나서
각 섬에 대하여 또 bfs를 돌리는데 다른 섬에 닿았을 때 level-1의 최소를 구한다.*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int arr[101][101];
bool visit[101][101];
int n;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
void bfs1(int x, int y,int cnt)
{
	queue <pair<int,int> > q;
	visit[x][y] = true;
	q.push({ x, y });
	while (!q.empty())
	{
		pair<int, int> front = q.front();
		arr[front.first][front.second] = cnt;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = front.first + dx[i];
			int ny = front.second + dy[i];
			while (nx >= 0 && nx < n &&ny >= 0 && ny < n &&
				visit[nx][ny] == 0 && arr[nx][ny]!=0)
			{
				visit[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}

int bfs2(int x, int y)
{
	queue<pair<int, int> > q;
	int numm = arr[x][y];
	visit[x][y] = true;
	q.push({ x,y });
	int level = 0;
	while (!q.empty())
	{

		int sizz = q.size();
		while (sizz--)
		{
			pair<int, int> front = q.front();
			q.pop();
			if (arr[front.first][front.second]!=0 &&
				arr[front.first][front.second] != numm)
			{
				return level;
			}
			for (int i = 0; i < 4; i++)
			{
				int nx = front.first + dx[i];
				int ny = front.second + dy[i];
				if (visit[nx][ny] == 0&& 
					nx >= 0 && nx < n &&ny >= 0 && ny < n)
				{
					q.push({ nx,ny });
					visit[nx][ny] = true;
				}
			}
		}
		level++;
	}
}
int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	int cnt = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 1 && visit[i][j]==false)
			{
				bfs1(i, j,cnt);
				cnt++;
			}
		}
	}
	int minn = 1e9;
	memset(visit, false, sizeof(visit));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] != 0 && visit[i][j] == 0)
			{
				minn= min(bfs2(i, j),minn);
				memset(visit, false, sizeof(visit));
			}
		}
	}
	cout << minn-1;
}

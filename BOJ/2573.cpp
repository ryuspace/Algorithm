//https://www.acmicpc.net/problem/2573
/*풀이 :
큐에다가 빙산의 위치를 담고 주변의 바다의 갯수를 담는 배열을 선언해준다.
모든 빙산 탐색이 끝나면 원래 배열에 바다 갯수를 담은 배열의 값만큼 빼준다.
그리고 dfs를 이용해 빙산 덩어리가 몇갠지 체크를 한다.
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int n, m;
int arr[301][301];
int around[301][301];
bool visit[301][301];
queue <pii> bing;

void dfs(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny] && arr[nx][ny] > 0)
		{
			visit[nx][ny] = true;
			dfs(nx, ny);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] > 0)
				bing.push({ i,j });
		}
	}

	int time = 0;
	int sizz = bing.size();
	while (sizz != 0)
	{
		memset(visit, 0, sizeof(visit));
		memset(around, 0, sizeof(around));
		while (sizz--)
		{
			pii front = bing.front();
			bing.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = dx[i] + front.first;
				int ny = dy[i] + front.second;
				if (nx >= 0 && nx < n && ny >= 0 && ny < m)
				{
					if (arr[nx][ny] == 0)
						around[front.first][front.second]++;
				}
			}
			if (arr[front.first][front.second] - around[front.first][front.second] > 0)
			{
				bing.push({ front.first,front.second });
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] - around[i][j] > 0)
				{
					arr[i][j] -= around[i][j];
				}
				else
					arr[i][j] = 0;
			}
		}
		sizz = bing.size();
		time++;
		int dung = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] > 0 && !visit[i][j])
				{
					visit[i][j] = true;
					dfs(i, j);
					dung++;
				}
			}
		}
		if (dung >= 2)
		{
			cout << time;
			exit(0);
		}

	}
	cout << 0;
	return 0;
}

//https://www.acmicpc.net/problem/16933
/*풀이 : bfs + 다익스트라.. 현재 온 위치가 가장 짧은 경로로 온 거라면
큐에 넣어준다. 짧은 경로는 같은 개수의 벽을 부수고 왔는데 그것이
최단 경로이다.*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int, int> pii;

int n, m, k;
int arr[1001][1001];
int visit[1001][1001][11];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

struct info
{
	int x, y, z,d;//z는 부순적이 있는지 체크 d는 낮,밤
};
int bfs()
{
	for (int i = 0; i <= 1000; i++)
	{
		for (int j = 0; j <= 1000; j++)
		{
			for (int r = 0; r <= 10; r++)
			{
				visit[i][j][r] = 1e9;
			}
		}
	}
	int cnt = 1;
	queue <info> q;
	q.push({ 0,0,0,0 });
	while (!q.empty())
	{
		info front = q.front();
		q.pop();
		if (front.x == n - 1 && front.y == m - 1)
			return front.d+1;
		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + front.x;
			int ny = dy[i] + front.y;
			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (arr[nx][ny] == 0)
				{
					if (1 + front.d < visit[nx][ny][front.z])
					{
						visit[nx][ny][front.z] = front.d + 1;
						q.push({ nx,ny,front.z,front.d + 1 });
					}

				}
				if (arr[nx][ny] == 1 && front.z<k)
				{
					if (1 + front.d < visit[nx][ny][front.z + 1])
					{
						if (front.d % 2 == 1)
						{
							q.push({ front.x,front.y,front.z,front.d+1 });
						}
						else
						{
							q.push({ nx,ny,front.z + 1,front.d + 1 });
							visit[nx][ny][front.z + 1] = front.d+1;
						}
					}

				}
			}
		}
	}
	return -1;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < tmp.length(); j++)
		{
			arr[i][j] = tmp[j] - '0';
		}
	}
	cout << bfs();
	return 0;

}


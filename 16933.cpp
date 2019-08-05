//https://www.acmicpc.net/problem/16933
/*풀이 : 벽을 n개 만큼 깨고 온 적이 없으면 큐에 추가해주는게 포인트.*/
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
bool visit[1001][1001][11];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

struct info
{
	int x, y, z;
};
int bfs()
{
	int cnt = 0;//낮인지 밤인지 나타낼 수 있고 며칠이 지났는지..
	queue <info> q;
	q.push({ 0,0,0 });
	while (!q.empty())
	{
		int sizz = q.size();
		while (sizz--)
		{
			info front = q.front();
			q.pop();
			if (front.x == n - 1 && front.y == m - 1)
				return cnt + 1;
			for (int i = 0; i < 4; i++)
			{
				int nx = dx[i] + front.x;
				int ny = dy[i] + front.y;
				if (nx >= 0 && nx < n && ny >= 0 && ny < m)
				{
					if (arr[nx][ny] == 0)
					{
						if (!visit[nx][ny][front.z])
						{
							visit[nx][ny][front.z] = true;
							q.push({ nx,ny,front.z });
						}

					}
					if (arr[nx][ny] == 1 && front.z < k)
					{
						if (!visit[nx][ny][front.z + 1])//벽을 깰 예정 front.z+1개를 깨고 온 적이 없다면 큐에 추가해주자.
						{
							if (cnt % 2 == 1)
							{
								q.push({ front.x,front.y,front.z });
							}
							else
							{
								q.push({ nx,ny,front.z + 1 });
								visit[nx][ny][front.z + 1] = true;
							}
						}

					}
				}
			}
		}
		cnt++;
		
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


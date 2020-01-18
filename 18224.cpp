//https://www.acmicpc.net/problem/18224
/*풀이 : visit 처리를 현재 count에 밤 또는 낮에 방문했는지 체크한다.
그렇지 않으면 메모리 초과가 난다. 밤에 벽을 뛰어넘을 수 있기 때문에
낮 또는 밤에 방문했을지라도 몇 번째 (몇 일 아님) 낮 밤인지에 따라 또 결과가 달라진다.
*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int arr[501][501];
bool visit[11][2][501][501]; //몇번째 낮.. 몇번째 밤..
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
struct point
{
	int x, y, day, cnt;
};
void bfs()
{
	//낮은 0 밤은 1
	queue<point> q;
	q.push({ 0,0,0,0 });//x,y,day,cnt
	visit[0][0][0][0] = true;
	while (!q.empty())
	{
		point front = q.front();
		q.pop();
		if (front.x == n - 1 && front.y == n - 1)
		{
			cout << front.cnt/(2*m) + 1 << " ";
			if (front.day == 0)
				cout << "sun" << " ";
			else
				cout << "moon";
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + front.x;
			int ny = dy[i] + front.y;
			if (nx >= 0 && nx < n && ny >= 0 && ny < n)
			{
				if (arr[nx][ny] == 0)
				{
					if ((front.cnt + 1) % m == 0)
					{
						if (!visit[0][1 - front.day][nx][ny])
						{
							visit[0][1 - front.day][nx][ny] = true;
							q.push({ nx,ny,1 - front.day,front.cnt+1});
						}

					}
					else
					{
						if (!visit[(front.cnt + 1)%m][front.day][nx][ny])
						{
							visit[(front.cnt + 1) % m][front.day][nx][ny] = true;
							q.push({ nx,ny,front.day,front.cnt + 1 });
						}
						
					}
				}
				else
				{
					if (front.day == 1)
					{
						int nnx = nx;
						int nny = ny;
						while (nnx >= 0 && nnx < n && nny >= 0 && nny < n && arr[nnx][nny] == 1)
						{
							nnx += dx[i];
							nny += dy[i];
						}
						if (nnx >= 0 && nnx < n && nny >= 0 && nny < n && arr[nnx][nny] == 0)
						{
							if ((front.cnt + 1) % m == 0)
							{
								if (!visit[0][1 - front.day][nnx][nny])
								{
									visit[0][1 - front.day][nnx][nny] = true;
									q.push({ nnx,nny,1 - front.day,front.cnt + 1 });
								}

							}
							else
							{
								if (!visit[(front.cnt + 1) % m][front.day][nnx][nny])
								{
									visit[(front.cnt + 1) % m][front.day][nnx][nny] = true;
									q.push({ nnx,nny,front.day,front.cnt + 1 });
								}
								
							}
						}

					}

				}
			}
		}
	}
	cout << -1;
}
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	bfs();
	return 0;
}

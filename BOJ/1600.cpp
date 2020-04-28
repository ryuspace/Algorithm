//https://www.acmicpc.net/problem/1600
/*풀이 : bfs를 이용하여 최단 시간을 구한다.
현재 위치에서 몇 번 말의 이동방식을 사용했는지를 표시하는 visit 배열에다가 방문여부를
표시한다. 만약 현재 위치에서 k번의 이동이 이미 있었으면 큐에 넣지 않는다.*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int k, h, w;
int arr[201][201];
bool visit[201][201][31];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
struct point
{
	int x, y;
	int flag = 0;
};
void bfs()
{
	int cnt = 0;
	queue<point> q;
	point start = { 0,0,0 };
	q.push(start);
	visit[start.x][start.y][start.flag] = true;
	while (!q.empty())
	{
		int sizz = q.size();
		while (sizz--)
		{
			point front = q.front();
			q.pop();
			if (front.x == h - 1 && front.y == w - 1)
			{
				cout << cnt;
				exit(0);
			}
			for (int i = 0; i < 4; i++)
			{
				int nx = front.x + dx[i];
				int ny = front.y + dy[i];
				int nf = front.flag;
				if (nx >= 0 && nx < h && ny >= 0 && ny < w &&
					!visit[nx][ny][nf] && arr[nx][ny] == 0)
				{
					q.push({ nx,ny,nf });
					visit[nx][ny][nf] = true;
				}
			}
			int nx = front.x - 2;
			int ny = front.y - 1;
			int nf = front.flag;
			if (nx >= 0 && ny >= 0 && nf + 1 <= k && arr[nx][ny] == 0 && !visit[nx][ny][nf + 1])
			{
				q.push({ nx,ny,nf + 1 });
				visit[nx][ny][nf + 1] = true;
			}

			nx = front.x - 1;
			ny = front.y - 2;
			nf = front.flag;
			if (nx >= 0 && ny >= 0 && nf + 1 <= k && arr[nx][ny] == 0 && !visit[nx][ny][nf + 1])
			{
				q.push({ nx,ny,nf + 1 });
				visit[nx][ny][nf + 1] = true;
			}

			nx = front.x - 2;
			ny = front.y + 1;
			nf = front.flag;
			if (nx >= 0 && ny <w && nf + 1 <= k && arr[nx][ny] == 0 && !visit[nx][ny][nf + 1])
			{
				q.push({ nx,ny,nf + 1 });
				visit[nx][ny][nf + 1] = true;
			}

			nx = front.x - 1;
			ny = front.y + 2;
			nf = front.flag;
			if (nx >= 0 && ny <w && nf + 1 <= k && arr[nx][ny] == 0 && !visit[nx][ny][nf + 1])
			{
				q.push({ nx,ny,nf + 1 });
				visit[nx][ny][nf + 1] = true;
			}

			nx = front.x + 1;
			ny = front.y - 2;
			nf = front.flag;
			if (nx <h && ny >= 0 && nf + 1 <= k && arr[nx][ny] == 0 && !visit[nx][ny][nf + 1])
			{
				q.push({ nx,ny,nf + 1 });
				visit[nx][ny][nf + 1] = true;
			}

			nx = front.x + 2;
			ny = front.y - 1;
			nf = front.flag;
			if (nx <h && ny >= 0 && nf + 1 <= k && arr[nx][ny] == 0 && !visit[nx][ny][nf + 1])
			{
				q.push({ nx,ny,nf + 1 });
				visit[nx][ny][nf + 1] = true;
			}

			nx = front.x + 2;
			ny = front.y + 1;
			nf = front.flag;
			if (nx <h && ny <w && nf + 1 <= k && arr[nx][ny] == 0 && !visit[nx][ny][nf + 1])
			{
				q.push({ nx,ny,nf + 1 });
				visit[nx][ny][nf + 1] = true;
			}

			nx = front.x + 1;
			ny = front.y + 2;
			nf = front.flag;
			if (nx <h && ny <w && nf + 1 <= k && arr[nx][ny] == 0 && !visit[nx][ny][nf + 1])
			{
				q.push({ nx,ny,nf + 1 });
				visit[nx][ny][nf + 1] = true;
			}
		}
		cnt++;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> k >> w >> h;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> arr[i][j];
		}
	}
	bfs();
	cout << -1;
	return 0;
}

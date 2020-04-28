//https://www.acmicpc.net/problem/1726
/*풀이 : bfs로 모든 경로를 탐색해본다.
한 큐에 담을 수 있는 경우 :
1. 한 칸을 간다. 2.두 칸을 간다. 3.세 칸을 간다 4.왼쪽으로 돈다. 5.오른쪽으로 돈다.
만약 n칸을 갔는데 막혔으면 n+1칸은 갈 수 없음을 주의하자.
*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct point
{
	int x, y, dir;
};

point des;
int m, n;
int arr[101][101];
bool visit[4][101][101];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };

int bfs(int x,int y,int dir)
{
	int cnt = 0;
	queue<point> q;
	q.push({ x,y,dir });
	visit[dir][x][y] = true;
	while (!q.empty())
	{
		int sizz = q.size();
		while (sizz--)
		{
			point front = q.front();
			q.pop();
			if (front.x == des.x && front.y == des.y &&
				front.dir == des.dir)
			{
				return cnt;
			}
			for (int j = 1; j <= 3; j++)
			{
				int nx = front.x + (dx[front.dir] * j);
				int ny = front.y + (dy[front.dir] * j);
				
				if (nx >= 0 && nx < m && ny >= 0 && ny < n && arr[nx][ny] == 1)
				{
					break;
				}
				else if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visit[front.dir][nx][ny] && arr[nx][ny] == 0)
				{
					visit[front.dir][nx][ny] = true;
					q.push({ nx,ny,front.dir });
				}

			}
			if (!visit[(front.dir + 1) % 4][front.x][front.y])
			{
				visit[(front.dir +1)%4][front.x][front.y] = true;
				q.push({ front.x,front.y,(front.dir + 1) % 4 });
			}
			if (!visit[(front.dir + 3) % 4][front.x][front.y])
			{
				visit[(front.dir + 3) % 4][front.x][front.y] = true;
				q.push({ front.x,front.y,(front.dir + 3) % 4 });
			}
		}
		cnt++;
		
	}
}
int main()
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	point start;
	cin >> start.x >> start.y >> start.dir;
	start.x -= 1;
	start.y -= 1;
	if (start.dir == 1)
		start.dir = 0;
	else if (start.dir == 4)
		start.dir = 1;

	cin >> des.x >> des.y >> des.dir;
	des.x -= 1;
	des.y -= 1;
	if (des.dir == 1)
		des.dir = 0;
	else if (des.dir == 4)
		des.dir = 1;

	cout<<bfs(start.x, start.y, start.dir);
	
	return 0;
}

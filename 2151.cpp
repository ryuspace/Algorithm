//https://www.acmicpc.net/problem/2151
/*풀이 : 처음에 dfs로 접근했다가 n의 사이즈 때문에 tle가 떴었다.
우선 거울을 놓을 수 있는 위치는 자신이 온 역방향 이외의 모든 방향을 갈 수 있다.
정방향으로 갈 때는 카운트를 유지하고 역방향 이외의 방향을 갈 때는 거울을 설치해야 하니까 카운트를 하나 올려준다.
방문 처리는 이 지점에 왔을 때 이 방향으로 더 적은 카운트로 온 적이 없으면 방문할 수 있게 한다.
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
struct point
{
	int x, y, dir,cnt;
};
typedef pair<int, int> pii;
int n;
char arr[51][51];
int visit[4][51][51];
vector <pii> v;
pii moon;
int res = 1e9;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,-0,1 };
void simul()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				visit[i][j][k] = 1e9;
			}
		}
	}
	queue<point> q;
	for (int i = 0; i < 4; i++)
	{
		q.push({ moon.first,moon.second,i ,0});
		visit[i][moon.first][moon.second] = 0;
	}
	while (!q.empty())
	{
		point front = q.front();
		q.pop();
		int x = front.x;
		int y = front.y;
		if (arr[x][y] == '#' && !(moon.first==x && moon.second==y))
		{
			res = min(res, front.cnt);
		}
		int cnt = front.cnt;
		int dir = front.dir;
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n )
		{
			if (arr[nx][ny]=='.' || arr[nx][ny]=='#' && visit[dir][nx][ny] > cnt)
			{
				visit[dir][nx][ny] = cnt;
				q.push({ nx,ny,dir, cnt});
			}
			if (arr[nx][ny] == '!')
			{
				for (int i = 0; i < 4; i++)
				{
					if (i != (dir + 2) % 4 && visit[i][nx][ny] > cnt+1)
					{
						q.push({ nx,ny,i,cnt+1 });
						visit[i][nx][ny] = cnt+1;
					}
					if (i == dir && visit[i][nx][ny] > cnt)
					{
						q.push({ nx,ny,i,cnt });
						visit[i][nx][ny] = cnt;
					}
				}
			}
		}
	}
}
int main()
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == '#')
				moon = { i,j };
		}
	}
	simul();
	cout << res;
	return 0;
}

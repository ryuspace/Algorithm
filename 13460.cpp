//https://www.acmicpc.net/problem/13460
/*풀이 : 현재 위치에서 상하좌우 4방향으로 구슬을 굴린다.
bfs를 이용하고 파란 구슬이 구멍에 떨어지는 경우에는 
큐에 push 해주지 않는다.*/
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
using namespace std;
typedef pair<int, int> pii;
int n, m;
char arr[11][11];
pii red;
pii blue;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool visit[11][11][11][11];

struct point {
	int rx, ry, bx, by;
};
void bfs()
{
	int cnt = 0;
	queue<point> q;
	visit[red.first][red.second][blue.first][blue.second] = true;
	q.push({ red.first,red.second,blue.first,blue.second });
	while (!q.empty())
	{
		int sizz = q.size();
		while (sizz--)
		{
			point front = q.front();
			q.pop();
			if (arr[front.rx][front.ry] == 'O')
			{
				if (cnt <= 10)
					cout << cnt;
				else
					cout << -1;
				exit(0);
			}
	
			for (int i = 0; i < 4; i++)
			{
				int rxx = front.rx;
				int ryy = front.ry;
				int bxx = front.bx;
				int byy = front.by;
				while (arr[rxx][ryy] == '.')
				{
					rxx += dx[i];
					ryy += dy[i];
				}
				if (arr[rxx][ryy] == '#')
				{
					rxx -= dx[i];
					ryy -= dy[i];
				}
				while (arr[bxx][byy] == '.')
				{
					bxx += dx[i];
					byy += dy[i];
				}
				if (arr[bxx][byy] == '#')
				{
					bxx -= dx[i];
					byy -= dy[i];
				}				
				//큐에 다시 넣어야하는 조건 1. 둘 다 .인경우 2. 빨강만 O에 들어간 경우
				if (rxx == bxx && ryy == byy && arr[rxx][ryy] != 'O')
				{
					if (abs(rxx - front.rx) + abs(ryy - front.ry) > abs(bxx - front.bx) +
						abs(byy - front.by))
					{
						rxx -= dx[i];
						ryy -= dy[i];
					}
					else
					{
						bxx -= dx[i];
						byy -= dy[i];
					}
					if (visit[rxx][ryy][bxx][byy])
						continue;
					visit[rxx][ryy][bxx][byy] = true;
					q.push({ rxx,ryy,bxx,byy });
				}
				else if (arr[rxx][ryy] == 'O' && arr[bxx][byy] != 'O')
				{
					if (visit[rxx][ryy][bxx][byy])
						continue;
					visit[rxx][ryy][bxx][byy] = true;
					q.push({ rxx,ryy,bxx,byy });
				}
				else if(arr[rxx][ryy]=='.' && arr[bxx][byy]=='.')
				{
					if (visit[rxx][ryy][bxx][byy])
						continue;
					visit[rxx][ryy][bxx][byy] = true;
					q.push({ rxx,ryy,bxx,byy });
				}
			}
		}
		cnt++;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = tmp[j];
			if (arr[i][j] == 'B')
			{
				blue = { i,j };
				arr[i][j] = '.';
			}
			else if (arr[i][j] == 'R')
			{
				red = { i,j };
				arr[i][j] = '.';
			}
		}
	}

	bfs();
	cout << -1;
	return 0;
}
}


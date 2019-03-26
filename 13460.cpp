//https://www.acmicpc.net/problem/13460
/*풀이 : 현재 위치에서 상하좌우 4방향으로 구슬을 굴린다.
bfs를 이용하고 파란 구슬이 구멍에 떨어지는 경우에는 
큐에 push 해주지 않는다.*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

typedef pair<int, int> pii;
typedef pair <pii, pii> pp;
int n, m;
char arr[11][11];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool visit[11][11][11][11];//빨간 공의 위치와 파란 공의 위치를 담는 배열
vector<pii> red;
vector<pii> blue;
int bfs()
{
	int cntt = 0;
	queue< pp> q;
	q.push({ { red[0].first,red[0].second },{ blue[0].first,blue[0].second } });
	visit[red[0].first][red[0].second][blue[0].first][blue[0].second] = true;
	while (!q.empty())
	{
		int sizz = q.size();
		while (sizz--)
		{
			pp front = q.front();
			q.pop();
			int rx = front.first.first;
			int ry = front.first.second;
			int bx = front.second.first;
			int by = front.second.second;
			if (cntt > 10)
				return -1;
			if (arr[rx][ry] == 'O')
				return cntt;

			for (int i = 0; i < 4; i++)
			{
				int rxx = rx + dx[i];
				int ryy = ry + dy[i];
				int bxx = bx + dx[i];
				int byy = by + dy[i];
				while (arr[rxx][ryy] != '#' &&arr[rxx][ryy] != 'O')
				{
					rxx += dx[i];
					ryy += dy[i];
				}
				if (arr[rxx][ryy] == '#')
				{
					rxx -= dx[i];
					ryy -= dy[i];
				}
				while (arr[bxx][byy] != '#' &&arr[bxx][byy] != 'O')
				{
					bxx += dx[i];
					byy += dy[i];
				}
				if (arr[bxx][byy] == '#')
				{
					bxx -= dx[i];
					byy -= dy[i];
				}

				if (arr[bxx][byy] == 'O')
					continue;
				if (rxx == bxx && ryy == byy)
				{
					if (arr[rxx][ryy] != 'O')
					{
						int red_dist = abs(rx - rxx) + abs(ry - ryy);
						int blue_dist = abs(bx - bxx) + abs(by - byy);
						if (red_dist < blue_dist)
						{
							bxx -= dx[i];
							byy -= dy[i];
						}
						else
						{
							rxx -= dx[i];
							ryy -= dy[i];
						}
					}
				}
				if (visit[rxx][ryy][bxx][byy] == 0)//이 위치에 이미 왔었으면 횟수 낭비
				{
					visit[rxx][ryy][bxx][byy] = 1;
					q.push({ { rxx,ryy },{ bxx,byy } });
				}
			}
		}
		cntt++;
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'R')
				red.push_back({ i,j });
			if (arr[i][j] == 'B')
				blue.push_back({ i,j });
		}
	cout << bfs();
	return 0;
}


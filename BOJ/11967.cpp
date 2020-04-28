//https://www.acmicpc.net/problem/11967
/*풀이 : bfs는 최대 10000번까지 돌 수 있다. 연결된 곳의 불을 전부 켜본 후 최대치까지 bfs를 돌려본다.*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;
vector<pii> v[101][101];
int n, m;
bool visit[101][101];
int light[101][101];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
queue <pii> q;

int cnt = 0;
void bfs(pii start)
{
	visit[start.first][start.second] = 1;
	for (int i = 0; i < v[start.first][start.second].size(); i++)
	{
		light[v[start.first][start.second][i].first][v[start.first][start.second][i].second] = 1;
	}
	for (int i = 0; i < 4; i++)
	{
		int nx = start.first + dx[i];
		int ny = start.second + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n&&
			visit[nx][ny] == false && light[nx][ny] == 1)
		{
			bfs({ nx,ny });
		}
	}
}
int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		v[a - 1][b - 1].push_back({ c - 1,d - 1 });
	}
	visit[0][0] = true;
	light[0][0] = 1;

	for (int i = 0; i < n*n; i++)
	{
		memset(visit, 0, sizeof(visit));
		bfs({ 0,0 });
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (light[i][j] == 1)
				cnt++;
		}
	}
	cout << cnt;

	return 0;
}

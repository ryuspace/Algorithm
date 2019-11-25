//https://www.acmicpc.net/problem/11967
/*풀이 : 문제를 정의 하는 것이 중요하다.
만약 어느 방에 방문해서 다른 곳에 불을 켰으면 이 상황은 (1,1)방에서 다시 출발할 필요가 있다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;
int n, m;
int x, y, a, b;
vector <pii> v[102][102];
bool visit[102][102];
bool light[102][102];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int cnt = 0;
bool bfs(pii start)
{
	bool flag = false;
	visit[start.first][start.second] = true;
	for (int i = 0; i < v[start.first][start.second].size(); i++)
	{
		if (!light[v[start.first][start.second][i].first][v[start.first][start.second][i].second])
		{
			light[v[start.first][start.second][i].first][v[start.first][start.second][i].second] = true;
			cnt++;
			flag = true;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		int nx = dx[i] + start.first;
		int ny = dy[i] + start.second;
		if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && light[nx][ny] && !visit[nx][ny])
		{
			visit[nx][ny] = true;
			bool flag2 = bfs(make_pair(nx, ny));//상하좌우 방을 돌다가 또 어느 방에 불을 켰으면 이것 또한 (1,1) 방에서 다시 탐색할 필요가 있다.
			flag |= flag2;//가능한 모든 방을 돌면서 불을 킨 적이 있냐 없냐 check..
		}
	}
	return flag;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> a >> b;
		v[x][y].push_back(make_pair(a, b));
	}
	light[1][1] = true;
	while (true)
	{
		memset(visit, 0, sizeof(visit));
		if (!bfs(make_pair(1, 1)))
			break;
	}
	cout << cnt+1;
	return 0;
}

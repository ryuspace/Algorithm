/*5644번 무선 충전
풀이 : 맵을 벡터로 받아 그 맵에 있는 bc의 인덱스를 push 해준다.
그리고 사용자를 움직이면서 현재 위치에 있는 bc들의 조합 중에서
최대치를 찾는다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
int t;
int walk[2][101];
vector<int> arr[11][11];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int wx[5] = { 0,-1,0,1,0 };
int wy[5] = { 0,0,1,0,-1 };
int bc[9];
void bfs(int x, int y,int idx,int c)
{
	int cnt = 0;
	bool visit[11][11] = {};
	queue<pii> q;
	q.push(make_pair(x, y));
	visit[x][y] = true;
	arr[x][y].push_back(idx);
	while (!q.empty())
	{
		int sizz = q.size();
		while (sizz--)
		{
			pii front = q.front();
			q.pop();
			if (cnt == c)
				return;
			for (int i = 0; i < 4; i++)
			{
				int nx = dx[i] + front.first;
				int ny = dy[i] + front.second;
				if (nx >= 0 && nx < 10 && ny >= 0 && ny < 10 && !visit[nx][ny])
				{
					arr[nx][ny].push_back(idx);
					visit[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
		cnt++;
	}

}

int summ(pii p1, pii p2)
{

	int maxx = 0;
	for (int i = 0; i < arr[p1.first][p1.second].size(); i++)
	{
		for (int j = 0; j < arr[p2.first][p2.second].size(); j++)
		{
			if (arr[p1.first][p1.second][i] == arr[p2.first][p2.second][j])
			{
				maxx = max(maxx, bc[arr[p1.first][p1.second][i]]);
			}
			else
			{
				maxx = max(maxx, bc[arr[p1.first][p1.second][i]]+bc[arr[p2.first][p2.second][j]]
				);
			}
		}
	}
	return maxx;
}
int main()
{
	freopen("t.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin >> t;
	for (int y = 1; y <= t; y++)
	{
		for (int i = 0; i <= 10; i++)
		{
			for (int j = 0; j <= 10; j++)
			{
				arr[i][j].clear();
			}
		}
		pii p1 = make_pair(0, 0);
		pii p2 = make_pair(9, 9);
		int m, a;
		cin >> m >> a;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> walk[i][j];
			}
		}
		for (int i = 1; i <= a; i++)
		{
			int x, y, c, p;
			cin >> x >> y >> c >> p;
			bc[i] = p;
			bfs(y-1, x-1, i,c);//x랑 y 위치 바뀜 주의
		}

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (arr[i][j].size() == 0)
				{
					arr[i][j].push_back(0);
				}
			}
		}
	
		int res = 0;
		res+=summ(p1, p2);
		for (int i = 0; i < m; i++)
		{
			p1.first += wx[walk[0][i]];
			p1.second += wy[walk[0][i]];
			p2.first += wx[walk[1][i]];
			p2.second += wy[walk[1][i]];
			res += summ(p1, p2);

		}
		cout << "#" << y << " " << res << '\n';
	}
	return 0;
}

//https://www.acmicpc.net/problem/9376
/*풀이 : deque를 이용해서 문이 있는 곳이면 뒤에다가 푸쉬해주고 문이 없는 곳이면 앞에다가 푸쉬해줘서
최대한 문을 통과하지 않는 방법으로 bfs를 돌려서 시간을 절약한다 !!
*/
#include <iostream>
#include <algorithm>
#include <deque>
#include <cstring>
using namespace std;

typedef pair<int, int> pii;
int t,h,w;
char arr[103][103];
int dist[3][103][103];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void bfs(pii start, int num)
{
	bool visit[103][103] = { 0, };
	deque<pii> q;
	q.push_front(start);
	visit[start.first][start.second] = true;
	dist[num][start.first][start.second] = 0;
	while (!q.empty())
	{
		pii front = q.front();
		q.pop_front();
		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + front.first;
			int ny = dy[i] + front.second;
			if (nx >= 0 && nx <= h+1 && ny >= 0 && ny <= w+1 && !visit[nx][ny] && arr[nx][ny] != '*')
			{
				if (arr[nx][ny] == '.')
				{
					dist[num][nx][ny] = dist[num][front.first][front.second];
					visit[nx][ny] = true;
					q.push_front({ nx,ny });
				}
				else if (arr[nx][ny] == '#')
				{
					dist[num][nx][ny] = dist[num][front.first][front.second] + 1;
					visit[nx][ny] = true;
					q.push_back({ nx,ny });
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

	cin >> t;
	while (t--)
	{
		int cnt = 0;
		cin >> h >> w;
		memset(arr, 0, sizeof(arr));
		fill(&dist[0][0][0], &dist[2][h][w], 99999);
		pii pri[2];
		for (int i = 0; i <= h + 1; i++)
		{
			for (int j = 0; j <= w + 1; j++)
			{
				if (i == 0 || j == 0 || i == h + 1 || j == w + 1)
					arr[i][j] = '.';
				else
				{
					cin >> arr[i][j];
					if (arr[i][j] == '$')
					{
						pri[cnt] = { i,j };
						cnt++;
						arr[i][j] = '.';
					}
				}

			}
		}
		bfs({ 0,0 }, 0);bfs(pri[0], 1);bfs(pri[1], 2);
		int minn = 1e9;
		pii mini;
		int tmp[103][103] = { 0, };
		for (int i = 0; i <= h + 1; i++)
		{
			for (int j = 0; j <= w + 1; j++)
			{
				tmp[i][j] = dist[0][i][j] + dist[1][i][j] + dist[2][i][j];
				if (arr[i][j] == '#')
				{
					if (minn > tmp[i][j] - 2)
					{
						minn = tmp[i][j] - 2;
						mini = { i,j };
					}
				}
				else
				{
					if (minn > tmp[i][j])
					{
						minn = tmp[i][j];
						mini = { i,j };
					}
				}
			}
		}
		cout << minn << '\n';
	}
	return 0;
}


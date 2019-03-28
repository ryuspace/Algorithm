//https://www.acmicpc.net/problem/17025
/*풀이 : 범위 밖으로 나가는 경우와
.으로 가는 경우의 갯수를 count 해주면 그것이 둘레가 된다.*/
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

vector <pii> v;
char arr[1001][1001];
bool visit[1001][1001];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int n;

int bfs1(pii start)
{
	int cntt = 1;
	queue<pii> q;
	visit[start.first][start.second] = true;
	q.push({ start });
	while (!q.empty())
	{
		pii front = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + front.first;
			int ny = dy[i] + front.second;
			if (!visit[nx][ny] && arr[nx][ny] == '#'&& nx >= 0 && nx < n && ny >= 0 && ny < n)
			{
				q.push({ nx,ny });
				visit[nx][ny] = true;
				cntt++;
			}
		}
	}
	return cntt;
}

int bfs2(pii start)
{
	int cntt = 0;
	queue<pii> q;
	visit[start.first][start.second] = true;
	q.push({ start });
	while (!q.empty())
	{
		pii front = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + front.first;
			int ny = dy[i] + front.second;
			if (!visit[nx][ny] && arr[nx][ny] == '.' || nx < 0 || nx >= n || ny < 0 || ny >= n)
			{
				cntt++;
				continue;
			}
			else if (!visit[nx][ny] && arr[nx][ny] == '#'&& nx >= 0 && nx < n && ny >= 0 && ny < n)
			{
				q.push({ nx,ny });
				visit[nx][ny] = true;
			}

		}
	}
	return cntt;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	int maxx = 0;
	pii max_idx = { -1,-1 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == '#' && !visit[i][j])
			{
				int num = bfs1({ i,j });
				if (maxx < num)
				{
					maxx = num;
					max_idx = { i,j };
				}
			}
		}
	}
	memset(visit, false, sizeof(visit));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == '#' && !visit[i][j])
			{
				int num = bfs1({ i,j });
				if (maxx == num)
				{
					v.push_back({ i,j });
				}
			}
		}
	}



	memset(visit, false, sizeof(visit));
	if (max_idx.first == -1 && max_idx.second == -1)
	{
		cout << 0 << " " << 0 << '\n';
	}
	else
	{
		int minn = 1e9;
		for (int i = 0; i < v.size(); i++)
		{
			minn = min(bfs2({ v[i].first,v[i].second }), minn);
		}
		cout << maxx << " " << minn << '\n';
	}

}

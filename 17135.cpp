//https://www.acmicpc.net/problem/17135
/*풀이 : dfs를 이용해 궁수 위치 선택. bfs를 이용해 모든 궁수가 잡을 수 있는 적을 찾는다.*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
int n, m, d;
int arr[17][17];
int dx[3] = { 0,-1,0 };
int dy[3] = { -1,0,1 };
bool vis[17];
bool target[17][17];//죽은 적을 표시하자.
vector <pii> acher;

bool cmp(pii& a, pii& b)
{
	if (a.second < b.second)
		return 1;
	else
		return 0;
}

void bfs(pii start)
{
	int cnt = 0;
	bool visit[17][17] = { 0, };
	queue<pii> q;
	q.push(start);
	visit[start.first][start.second] = true;
	while (!q.empty())
	{
		int sizz = q.size();
		while (sizz--)
		{
			pii front =q.front();
			q.pop();

			for (int i = 0; i < 3; i++)
			{
				int nx = dx[i] + front.first;
				int ny = dy[i] + front.second;
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny] &&cnt+1<=d)
				{
					if (arr[nx][ny] == 0)
					{
						q.push({ nx,ny });
						visit[nx][ny] = true;
					}
					else
					{
						target[nx][ny] = true;
						return;
					}
				}
			}
		}

		cnt++;
	}

}
bool check()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 1)
				return true;
		}
	}
	return false;
}
int maxx = 0;
void movv()
{
	int cop[17][17];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cop[i][j] = arr[i][j];
		}
	}
	
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = cop[i - 1][j];
		}
	}
	for (int j = 0; j < m; j++)
		arr[0][j] = 0;
}
void play()
{
	int cnt = 0;
	while (check())
	{
		for (int i = 0; i < acher.size(); i++)
		{
			bfs({ acher[i].first,acher[i].second });
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (target[i][j])
				{
					cnt++;
					target[i][j] = false;
					arr[i][j] = 0;
				}
			}
		}
		movv();
	}
	maxx = max(maxx, cnt);
	
}
void dfs(int cnt,int idx)
{
	if (cnt == 3)
	{
		int cop[17][17];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cop[i][j] = arr[i][j];
			}
		}
		play();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				arr[i][j] = cop[i][j];
			}
		}
		return;
	}
	if (idx >= m)
		return;
	
	for (int i = idx; i < m; i++)
	{
		if (!vis[i])
		{
			vis[i] = true;
			acher.push_back({ n,i });
			dfs(cnt + 1,i+1);
			acher.pop_back();
			vis[i] = false;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	dfs(0,0);
	cout << maxx;
	return 0;
}


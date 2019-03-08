//https://www.acmicpc.net/problem/14502
/*풀이 : dfs를 이용하여 맵에 빈 공간에 벽을 세울 수 있는 모든 경우를 탐색해보고 벽을 3개 세웠으면 bfs를 이용해 안전영역을 찾는다.*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;
int n, m;
int arr[9][9];
bool visit[9][9];
bool visit2[9][9];
vector <pii> virus;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void bfs(pii start)
{
	queue <pii> q;
	q.push({ start.first,start.second });
	visit2[start.first][start.second] = true;
	while (!q.empty())
	{
		pii front = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = front.first + dx[i];
			int ny = front.second + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m
				&&arr[nx][ny]==0 && visit2[nx][ny]==false)
			{
				visit2[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}
int minn = 0;
void dfs(int cnt)
{
	int res = 0;
	if (cnt == 3)
	{
		for (int i = 0; i < virus.size(); i++)
		{
			bfs({ virus[i].first,virus[i].second });
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == 0  && visit2[i][j] == false)
				{
					res++;
				}
			}
		}
		minn = max(res, minn);
		memset(visit2, 0, sizeof(visit2));
		return;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visit[i][j] == false &&arr[i][j]==0)
			{
				visit[i][j] = true;
				arr[i][j] = 1;
				dfs(cnt + 1);
				visit[i][j] = false;
				arr[i][j] = 0;
			}
		}
	}
}
int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 2)
			{
				virus.push_back({ i,j });
			}
		}
	}
	dfs(0);
	cout << minn;
	return 0;
}

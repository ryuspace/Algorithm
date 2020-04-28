//https://www.acmicpc.net/problem/14502
/*풀이 : dfs를 이용하여 놓을 수 있는 위치에 벽을 다 놓아본다.
벽을 놓으면 행을 역주행해서 다시 벽을 놓을 순 없으므로 dfs를 또 실행시킬땐
원래 행부터 시작한다.(처음부터 탐색, 정해진 행부터 탐색 이 두가지의 시간
차이는 어마어마하다.) 벽을 세웠으면 bfs를 실행시켜 안전영역을 찾는다.*/
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
				&&arr[nx][ny] == 0 && visit2[nx][ny] == false)
			{
				visit2[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}
int minn = 0;
void dfs(int x,int cnt)
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
				if (arr[i][j] == 0 && visit2[i][j] == false)
				{
					res++;
				}
			}
		}
		minn = max(res, minn);
		memset(visit2, 0, sizeof(visit2));
		return;
	}
	for (int i = x; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visit[i][j] == false && arr[i][j] == 0)
			{
				visit[i][j] = true;
				arr[i][j] = 1;
				dfs(i,cnt + 1);
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
	dfs(0,0);
	cout << minn;
	return 0;
}

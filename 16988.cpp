//https://www.acmicpc.net/problem/16988
/*풀이 :0인 칸 2개를 선택할 수 있는 가능한 모든 경우를 찾고
각각의 경우에 bfs를 돌려서 잡을 수 있는 
상대방의 돌의 개수의 최대값을 찾는다.*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
int n, m;
int arr[21][21];
bool use[21][21];
bool visit[21][21];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int maxx = 0;


void init()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			visit[i][j] = false;
		}
	}
}
int bfs(pii start)
{
	bool flag = false;
	int cnt = 1;
	vector<pii> bye;
	queue<pii> q;
	q.push(start);
	bye.push_back(start);
	visit[start.first][start.second] = true;
	while (!q.empty())
	{
		pii front = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + front.first;
			int ny = dy[i] + front.second;
			if (nx >= 0 && nx < n && ny >= 0 && ny < m )
			{
				if (!visit[nx][ny]&&arr[nx][ny] == 2)
				{
					bye.push_back({ nx,ny });
					visit[nx][ny] = true;
					q.push({ nx,ny });
					cnt++;
				}
				else if (arr[nx][ny] == 0)
				{
					flag = true;
				}
			}
		}
	}
	if (flag)
	{
		return 0;
	}
	else
		return cnt;
}

void dfs(int idx,int cnt)
{
	if (cnt == 2)
	{
		int cntt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (!visit[i][j] && arr[i][j] == 2)
				{
					int num = bfs({ i,j });
					cntt+= num;
				}
			}
		}
		init();
		maxx = max(cntt, maxx);
		return;
	}
	for (int i = idx; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 0 && !use[i][j])
			{
				use[i][j] = true;
				arr[i][j] = 1;
				dfs(i, cnt + 1);
				use[i][j] = false;
				arr[i][j] = 0;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
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

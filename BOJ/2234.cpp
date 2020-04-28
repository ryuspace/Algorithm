//https://www.acmicpc.net/problem/2234
/*풀이 : 우선 같은 방끼리 고유의 인덱스를 부여한다. 벽을 제거하는 것을 처리하는 방법은
두 방의 인덱스가 다르면 어떤 벽이 두 방을 갈랐단 뜻이다.
그 두 방의 넓이를 합치면 벽을 제거한 것과 같다.*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;
//서북동남
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };

vector<pii> info;
int room[51][51];
int wall[51][51][4];//행,열,방향에 따른 벽의 존재여부
bool visit[51][51];
int n, m;
int idx = 0;
int bfs(pii start)//방의 넓이를 리턴
{
	int res = 1;
	queue<pii> q;
	vector<pii> v;
	v.push_back(start);
	q.push(start);
	visit[start.first][start.second] = true;
	while (!q.empty())
	{
		pii front = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = front.first + dx[i];
			int ny = front.second + dy[i];
			if (nx >= 0 && nx < m&& ny >= 0 && ny < n && !visit[nx][ny] &&
				wall[nx][ny][i] == 0)
			{
				res++;
				q.push({ nx,ny });
				v.push_back({ nx,ny });
				visit[nx][ny] = true;
			}
		}
	}
	for (int i = 0; i < v.size(); i++)
	{
		room[v[i].first][v[i].second] = idx;
	}
	info.push_back({ idx,res });
	idx++;
	return res;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int a;
			cin >> a;
			for (int r = 0; r < 4; r++)
			{
				if (a & (1 << r))
				{
					int nx = dx[r] + i;
					int ny = dy[r] + j;
					if (nx >= 0 && nx<m && ny >= 0 && ny<n)
						wall[nx][ny][r] = 1;
				}
			}
		}
	}
	int cnt1 = 0;
	int cnt2 = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visit[i][j])
			{
				cnt2 = max(cnt2, bfs({ i,j }));
				cnt1++;
			}
		}
	}
	sort(info.begin(), info.end());

	int cnt3 = 0;
	for (int r = 0; r < 4; r++)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (dx[r] + i >= 0 && dx[r] + i <m &&
					dy[r] + j >= 0 && dy[r] + j<n)
				{
					//최소 두개의 방이 있다! 방을 둘로 나누는 경우가 반드시 있다.
					if (room[i][j] != room[dx[r] + i][dy[r] + j])//방의 인덱스가 다르단 것은 벽이 둘을 나눈 것이다. 이 둘을 나눈 벽을 치워보자.
					{
						cnt3 = max(cnt3, info[room[i][j]].second + info[room[dx[r] + i][dy[r] + j]].second);//벽을 치웠으니 두 공간 합체
					}
				}
			}
		}
	}
	cout << cnt1 << '\n' << cnt2 << '\n' << cnt3 << '\n';
	return 0;
}

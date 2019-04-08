//https://www.acmicpc.net/problem/17135
/*풀이 : dfs를 이용해 궁수 위치 선택. bfs를 이용해 모든 궁수가 잡을 수 있는 적을 찾는다.*/
#include<iostream>
#include<algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;
int n, m, d;
int arr[16][16];
int tmp[16][16];
bool visit[16][16];
int dx[3] = { 0,-1,0 };
int dy[3] = { -1,0,1 };
vector<int> v;

void movv()
{
	for (int i = n-2; i >=0; i--)
	{
		for (int j = 0; j < m; j++)
		{
			arr[i + 1][j] = arr[i][j];
			arr[i][j] = 0;
		}
	}
}
vector<pii> vv;
void bfs(pii start)
{
	vector<pii> amy;
	int cnt = 0;
	bool use[16][16];
	memset(use, 0, sizeof(use));
	queue<pii> q;
	q.push(start);
	while (!q.empty())
	{
		int sizz = q.size();
		while (sizz--)
		{
			pii front = q.front();
			q.pop();

			for (int i = 0; i < 3; i++)
			{
				int nx = dx[i] + front.first;
				int ny = dy[i] + front.second;
				if (nx >= 0 && nx < n&&ny >= 0 && ny < m && !use[nx][ny])
				{
					if (arr[nx][ny] == 0)
					{
						use[nx][ny] = true;
						q.push({ nx,ny });
					}
					else
					{
						vv.push_back({ nx,ny });
						return;
					}
				}
			}
		}
		cnt++;
		if (cnt == d)
			return;
	}
}
int find()
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 1)
				cnt++;
		}
	}
	return cnt;
}
int play()
{
	bool visit3[16][16];
	int cntt = 0;
	while(find()!=0)
	{
		for (int i = 0; i < v.size(); i++)
		{
			bfs({ n,v[i]});
		}
		for (int i = 0; i < vv.size(); i++)
		{
			if (arr[vv[i].first][vv[i].second] == 1)
			{
				arr[vv[i].first][vv[i].second] = 0;
				cntt++;
			}
		}
		movv();
		vv.clear();
	}
	return cntt;
}
int maxx = 0;
void init()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = tmp[i][j];
		}
	}
}
void dfs(int idx, int cnt)
{
	if (cnt == 3)
	{
		maxx = max(maxx, play());
		init();
		return;
	}
	if (idx >= m || cnt>3)
		return;
	dfs(idx + 1, cnt);
	v.push_back(idx);
	dfs(idx + 1, cnt + 1);
	v.pop_back();
}
int main() {
	ios_base::sync_with_stdio(0);
	//freopen("t.txt", "r", stdin);
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			tmp[i][j] = arr[i][j];
		}
	}
	dfs(0,0);
	cout << maxx;
	return 0;
}

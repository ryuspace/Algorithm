//https://www.acmicpc.net/problem/17472
/*풀이
1.섬들을 라벨링 하자
2.라벨링한 섬들의 좌표를 하나로 묶자
3.라벨링한 섬을 한개로 보고 다른 섬이 나올 때 까지 dfs를 돌려 가능한 최소거리의 다리를 만들자
4.다른 dfs를 돌려 다리를 선택한 후 모든 섬이 연결되어있는지 체크한다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
typedef pair<int, int> pii;
int n, m;
int arr[101][101];
bool bfs_visit[101][101];
int dist[7][7];//섬에서 섬으로 가는 다리의 길이의 최소
bool dfs_visit[7];
vector<pii> v[7];//같은 섬 별로 좌표를 담은 벡터
int bfs_idx = 1;
bool play_visit[7];
bool selected[7][7];
struct point
{
	int start, end, value;
};
vector <point> vv;//섬이 연결되어있는 거와 최소 거리를 담은 벡터
void bfs(pii start, int idx)
{

	bfs_visit[start.first][start.second] = true;
	queue<pii> q;
	q.push(start);;
	v[idx].push_back(start);
	arr[start.first][start.second] = idx;
	while (!q.empty())
	{
		pii front = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + front.first;
			int ny = dy[i] + front.second;
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !bfs_visit[nx][ny] && arr[nx][ny] == 1)
			{
				bfs_visit[nx][ny] = true;
				v[idx].push_back({ nx,ny });
				arr[nx][ny] = idx;
				q.push({ nx,ny });
			}
		}
	}
}
void go(int num, pii start, int len, int dir)
{
	int nx = start.first + dx[dir];
	int ny = start.second + dy[dir];
	if (nx < 0 || nx >= n || ny < 0 || ny >= m)
		return;
	if (arr[nx][ny] == 0)
	{
		go(num, { nx,ny }, len + 1, dir);
	}
	else if (arr[nx][ny] == num)
	{
		return;
	}
	else
	{
		if (len >= 2)
			dist[num][arr[nx][ny]] = min(dist[num][arr[nx][ny]], len);
		return;
	}
}
int minn = 1e9;
bool play()
{
	int cnt = 1;
	memset(play_visit, 0, sizeof(play_visit));
	queue<int> q;
	q.push(1);
	play_visit[1] = true;
	while (!q.empty())
	{
		int front = q.front();
		q.pop();
		for (int i = 1; i <= bfs_idx; i++)
		{
			if (selected[front][i] == true && !play_visit[i])
			{
				q.push(i);
				play_visit[i] = true;
				cnt++;
			}
		}
	}
	if (cnt == bfs_idx)
		return true;
	else
		return false;

}
void dfs(int idx, int cnt, int sum)
{

	if (cnt >= 1)
	{
		if (play())
		{

			minn = min(minn, sum);
		}
	}
	if (cnt >= vv.size() || idx >= vv.size())
	{
		return;
	}
	for (int i = idx; i < vv.size(); i++)
	{
		if (!dfs_visit[i])
		{
			dfs_visit[i] = true;
			selected[vv[i].start][vv[i].end] = true;
			selected[vv[i].end][vv[i].start] = true;

			dfs(i + 1, cnt + 1, sum + vv[i].value);

			dfs_visit[i] = false;
			selected[vv[i].start][vv[i].end] = false;
			selected[vv[i].end][vv[i].start] = false;

			dfs(i + 1, cnt, sum);
		}
	}

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i =1; i <= 6; i++)
	{
		for (int j = 1; j <= 6; j++)
		{
			dist[i][j] = 1e9;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 1 && !bfs_visit[i][j])
			{
				bfs(make_pair(i, j), bfs_idx);
				bfs_idx++;
			}

		}
	}
	bfs_idx--;
	//라벨링 ok


	for (int i = 1; i <= bfs_idx; i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			for (int r = 0; r < 4; r++)
			{
				go(i, { v[i][j].first,v[i][j].second }, 0, r);
			}

		}
	}
	//dist ok

	bool visit[7][7] = { 0, };
	for (int i = 1; i <= bfs_idx; i++)
	{
		for (int j = 1; j <= bfs_idx; j++)
		{
			if (dist[i][j] != 1e9 && !visit[i][j])
			{

				visit[i][j] = true;
				visit[j][i] = true;
				vv.push_back({ i,j,dist[i][j] });
			}
		}
	}

	dfs(0, 0, 0);
	if (minn == 1e9)
		cout << -1;
	else
		cout << minn;
	return 0;
}

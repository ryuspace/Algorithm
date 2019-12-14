//https://www.acmicpc.net/problem/17472
/*풀이
1.섬들을 라벨링 하자
2.라벨링한 섬들의 좌표를 하나로 묶자
3.라벨링한 섬을 한개로 보고 다른 섬이 나올 때 까지 가능한 최소거리의 다리를 만들자
4. MST를 이용하여 최단경로를 구한다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
typedef pair<int, int> pii;
struct point
{
	int x, y, z;
};
int n, m;
int arr[11][11];
vector<pii> v[11];
bool visit[11][11];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int idx = 1;
int con[11][11];
bool con2[11][11];
int parent[11];
vector<point> ans;


void sel(pii start, int dir)
{
	int num = arr[start.first][start.second];
	int nx = start.first + dx[dir];
	int ny = start.second + dy[dir];
	while (true)
	{
		int len = (abs(start.first - nx) + abs(start.second - ny)) - 1;
		if (!(nx >= 0 && nx < n && ny >= 0 && ny < m))
		{
			break;
		}
		if (arr[nx][ny] == num)
			break;
		if (arr[nx][ny] != num && arr[nx][ny] != 0)
		{
			if (len >= 2 && con[num][arr[nx][ny]] > len)
			{
				con[num][arr[nx][ny]] = len;
				con[arr[nx][ny]][num] = len;
			}
			break;
		}

		nx += dx[dir];
		ny += dy[dir];
	}
}
void go(int idx)
{

	for (int i = 0; i < v[idx].size(); i++)
	{
		for (int j = 0; j < 4; j++)
		{
			sel(v[idx][i], j);
		}
	}

}
void bfs(pii start, int idx)
{
	queue<pii> q;
	q.push(start);
	visit[start.first][start.second] = true;
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
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny] && arr[nx][ny] == 1)
			{
				q.push({ nx,ny });
				visit[nx][ny] = true;
				v[idx].push_back({ nx,ny });
				arr[nx][ny] = idx;
			}
		}
	}

}

int find(int a)
{
	if (a == parent[a])
	{
		return a;
	}
	else
	{
		return parent[a] = find(parent[a]);
	}
}
bool cmp(const point& a, const point& b)
{
	if (a.z < b.z)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Union(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a < b)
	{
		parent[b] = a;
	}
	else
		parent[a] = b;
}
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			con[i][j] = 1e9;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!visit[i][j] && arr[i][j] == 1)
			{
				bfs({ i,j }, idx);
				idx++;
			}
		}
	}
	idx--;

	for (int i = 1; i <=idx; i++)
	{
		for (int j = 1; j <=idx; j++)
		{
			con[i][j] = 1e9;
		}
	}
	for (int i = 1; i <= idx; i++)
	{
		go(i);
	}
	for (int i = 1; i <= idx; i++)
	{
		for (int j = 1; j <= idx; j++)
		{
			if (!con2[i][j] && con[i][j] != 1e9 && con[i][j] >= 2)
			{
				ans.push_back({ i, j, con[i][j] });
				ans.push_back({ j, i, con[i][j] });
				con2[i][j] = true;
				con2[j][i] = true;
			}
		}
	}
	int sum = 0;
	sort(ans.begin(), ans.end(), cmp);
	for (int i = 1; i <= idx; i++)
	{
		parent[i] = i;
	}
	for (int i = 0; i < ans.size(); i++)
	{
		int a = find(ans[i].x);
		int b = find(ans[i].y);
		if (parent[a] != parent[b])
		{
			Union(a, b);
			sum += ans[i].z;
		}
	}
	int numm = find(1);
	for (int i = 2; i <= idx; i++)
	{
		find(i);
		if (parent[i] != numm)
		{
			cout << -1;
			exit(0);
		}
	}
	cout << sum;
	return 0;
}


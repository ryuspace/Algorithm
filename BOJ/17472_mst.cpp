//https://www.acmicpc.net/problem/17472
/*풀이
1.섬들을 라벨링 하자
2.라벨링한 섬들의 좌표를 하나로 묶자
3.라벨링한 섬을 한개로 보고 다른 섬이 나올 때 까지 가능한 다리를 만들자
4. MST를 이용하여 최단경로를 구한다.
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

int n, m;
int arr[11][11];
bool visit[11][11];
queue<pii> q;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int color = 1;
int label[11][11];
int parent[7];

struct point
{
	int x, y, gap;
};


bool cmp(point& a, point& b)
{
	return a.gap < b.gap;
}

vector<point> v;
void go(pii start, int dir,int color)
{
	int cnt = 0;
	int nx = start.first + dx[dir];
	int ny = start.second + dy[dir];
	while (nx >= 0 && nx < n && ny >= 0 && ny < m)
	{
		cnt++;
		if (label[nx][ny] == color)
			break;
		if (label[nx][ny] != 0 && label[nx][ny] != color)
		{
			cnt--;
			break;
		}
		nx += dx[dir];
		ny += dy[dir];
	}

	if (nx >= 0 && nx < n && ny >= 0 && ny < m && label[nx][ny] != 0 && label[nx][ny] != color && cnt>=2)
	{
		v.push_back({ color,label[nx][ny],cnt });
	}
}
void bfs(pii start, int num)
{
	visit[start.first][start.second] = true;
	q.push(start);
	label[start.first][start.second] = color;

	while (!q.empty())
	{
		pii front = q.front();
		q.pop();
		for (int i = 0;i < 4;i++)
		{
			int nx = dx[i] + front.first;
			int ny = dy[i] + front.second;
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny] && arr[nx][ny] == 1)
			{
				q.push({ nx,ny });
				visit[nx][ny] = true;
				label[nx][ny] = color;
			}
		}
	}
}

int findd(int a)
{
	if (a == parent[a])
		return a;
	return parent[a] = findd(parent[a]);
}

void uni(int a, int b)
{
	if (a < b)
	{
		parent[a] = b;
	}
	else
	{
		parent[b] = a;
	}
}
int main()
{
	//freopen("Test.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			if (arr[i][j] == 1 && !visit[i][j])
			{
				bfs({ i,j },color);
				color++;
			}
		}
	}
	//라벨링 완료

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			for (int r = 0;r < 4;r++)
			{
				if(label[i][j]!=0)
					go({ i,j }, r,label[i][j]);
			}
		}
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 1;i < color;i++)
	{
		parent[i] = i;
	}
	int sum = 0;
	for (int i = 0;i < v.size();i++)
	{
		if (findd(parent[v[i].x]) != findd(parent[v[i].y]))
		{
			uni(findd(parent[v[i].x]), findd(parent[v[i].y]));
			sum += v[i].gap;
		}
	}

	int start = findd(parent[1]);
	for (int i = 2;i < color;i++)
	{
		if (start != findd(parent[i]))
		{
			cout << -1;
			exit(0);
		}
	}
	cout << sum;
	return 0;
}

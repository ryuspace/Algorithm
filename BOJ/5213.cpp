//https://www.acmicpc.net/problem/5213
/*풀이 : 웬만한 큰 변수들은 전역변수로 선언해주자.
1.타일을 왼쪽 끝으로 몬다.
2.왼쪽 끝으로 몰았을 때 현재 타일 기준으로 홀/짝을 나눠 방문할 수 있는 곳을 체크하자.
3.그 방문할 수 있는 곳을 bfs를 돌려 마지막 행,마지막 열(타일 번호가 가장 큼) 까지 가게 한다.
ㄴ> 우선 bfs를 돌려서 가장 큰 타일 번호가 몇인지 체크한다.(목적지에 도착 못해도 가장 큰 타일번호로 가야한다.)
어떤 타일로 갈 때 이전 타일 번호를 저장하는 배열을 만들어서. bfs가 끝났을 때 가장 큰 타일번호를 기점으로 역추적을 한다.
*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct p1
{
	int l, r, num;
	p1()
	{
		l = -1;
		r = -1;
		num = -1;
	}
};

struct p2
{
	int x, y, idx;
};

int dx[8] = { -1,-1,-1,0,0 ,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };
p1 arr[501][501];
bool adj[9][501][501];
int parent[250100];
bool visit[501][501] = { 0, };
int main()
{
	//freopen("Text.txt","r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	int idx = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - (i % 2); j++)
		{
			cin >> arr[i][j].l >> arr[i][j].r;
			arr[i][j].num = idx++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - (i % 2); j++)
		{
			for (int r = 0; r < 8; r++)
			{
				if (arr[i][j].l == -1)
					continue;
				int nx = i + dx[r];
				int ny = j + dy[r];
				if (r == 0 && i % 2 == 0)
				{
					if (arr[i][j].l == arr[nx][ny].r)
					{
						adj[r][nx][ny] = 1;
					}
				}
				if (r == 1)
				{
					if (i % 2 == 0)
					{
						if (arr[i][j].r == arr[nx][ny].l)
							adj[r][nx][ny] = 1;
					}
					else
					{
						if (arr[i][j].l == arr[nx][ny].r)
							adj[r][nx][ny] = 1;
					}
				}
				if (r == 2 && i % 2 == 1)
				{
					if (arr[i][j].r == arr[nx][ny].l)
						adj[r][nx][ny] = 1;
				}
				if (r == 3)
				{
					if (arr[i][j].l == arr[nx][ny].r)
						adj[r][nx][ny] = 1;
				}
				if (r == 4)
				{
					if (arr[i][j].r == arr[nx][ny].l)
						adj[r][nx][ny] = 1;
				}
				if (r == 5 && i % 2 == 0)
				{
					if (arr[i][j].l == arr[nx][ny].r)
						adj[r][nx][ny] = 1;
				}
				if (r == 6)
				{
					if (i % 2 == 0)
					{
						if (arr[i][j].r == arr[nx][ny].l)
							adj[r][nx][ny] = 1;
					}
					else
					{
						if (arr[i][j].l == arr[nx][ny].r)
							adj[r][nx][ny] = 1;
					}
				}
				if (r == 7 && i % 2 == 1)
				{
					if (arr[i][j].r == arr[nx][ny].l)
						adj[r][nx][ny] = 1;
				}
			}
		}
	}

	int maxx = 0;
	queue <p2> q;
	q.push({ 0,0,1 });
	visit[0][0] = true;
	while (!q.empty())
	{
		p2 front = q.front();
		maxx = max(maxx, front.idx);
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int nx = front.x + dx[i];
			int ny = front.y + dy[i];
			int idx = front.idx;
			if (!visit[nx][ny] && adj[i][nx][ny])
			{
				visit[nx][ny] = true;
				q.push({ nx,ny,arr[nx][ny].num });
				parent[arr[nx][ny].num] = idx;
			}
		}
	}
	vector<int> v;
	while (true)
	{
		v.push_back(maxx);
		if (maxx == 1)
			break;
		maxx = parent[maxx];
	}
	cout << v.size() << '\n';
	for (int i = v.size() - 1; i >= 0; i--)
	{
		cout << v[i] << " ";
	}
	return 0;
}


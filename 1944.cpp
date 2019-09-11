//https://www.acmicpc.net/problem/1944
/*풀이 : 
1.S와 Key 위치를 큐에 푸쉬한다.
2.bfs를 돌려 S가 모든 key에 도달하는지 체크하고, key 위치들이 S 또는 다른 Key로 가는 최소 거리를 체크한다.
3.만약 S가 모든 key에 도달하지 못 하면 모든 열쇠를 찾지 못 하는 것이다.
4.S또는 Key에서 S또는 key로 가는 모든 최소 거리를 체크했으니 크루스칼 알고리즘을 이용해 움직인 횟수의 최소 합을 구할 수 있다.
*/
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
struct point
{
	int idx,cnt, x,y;
};
struct gap
{
	int idx1, idx2, val;
};
vector <gap> v;
char arr[51][51];
bool visit[252][51][51];
int key[51][51];
int n, m;
queue <point> q;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int s_idx;
int s_cnt = 1;
int cnt = 1;
int parent[252];

int find(int a)
{
	if (parent[a] == a)
		return a;
	return parent[a] = find(parent[a]);
}
void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a < b)
		parent[a] = b;
	else
		parent[b] = a;
}
bool cmp(const gap& a, const gap& b)
{
	if (a.val < b.val)
		return true;
	else
		return false;
}
void bfs()
{
	while (!q.empty())
	{
		int sizz = q.size();
		while (sizz--)
		{
			point front = q.front();
			q.pop();
			visit[front.idx][front.x][front.y] = true;
			for (int i = 0; i < 4; i++)
			{
				int nx = dx[i] + front.x;
				int ny = dy[i] + front.y;
				int cnt = front.cnt;
				int idx = front.idx;
				if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visit[idx][nx][ny]&&arr[nx][ny]!='1')
				{
					visit[idx][nx][ny] = true;
					if (key[nx][ny]!=0 && key[nx][ny] != idx)
					{
						v.push_back({ idx,key[nx][ny],cnt+1 });
						if (s_idx ==idx)
						{
							s_cnt++;
						}
					}

					q.push({ idx,cnt + 1,nx,ny });
				}
			}
		}
	}
	if (s_cnt != cnt)
	{
		cout << -1;
		exit(0);
	}
}
int main()
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for(int j=0;j<n;j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'S' ||arr[i][j]=='K')
			{
				if (arr[i][j] == 'S')
					s_idx = cnt;
				q.push({ cnt,0,i,j});
				key[i][j] = cnt;
				cnt++;
			}
		}
	}
	cnt -= 1;

	bfs();
	sort(v.begin(), v.end(), cmp);

	for (int i = 1; i <= cnt; i++)
	{
		parent[i] = i;
	}
	int sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		int a = find(v[i].idx1);
		int b = find(v[i].idx2);
		if (a != b)
		{
			sum += v[i].val;
			merge(v[i].idx1, v[i].idx2);
		}
	}
	cout << sum;
	return 0;
}


//https://www.acmicpc.net/problem/16137
/*풀이 : 오작교를 건널 수 있는 경우 : 위 아래가 절벽 하나 이상, 왼쪽 오른쪽이 절벽 하나 이상이 아닌 경우. 
오작교를 건넌 경우면
hi 값을 true로 하고 또 오작교가 나오면 큐에다가 push 해주지 않는다.*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
int n, m, o;
int arr[11][11];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<pii> v;
int minn = 1e9;
struct point
{
	int x, y;
	bool hi;//오작교 건너고 온건지 아닌지 체크
};
void bfs()
{
	int cnt = 0;
	bool visit[11][11] = { 0, };
	queue<point> q;
	q.push({ 0,0,0 });
	visit[0][0] = true;
	while (!q.empty())
	{
		int sizz = q.size();
		while (sizz--)
		{
			point front = q.front();
			q.pop();
			if (front.x == n - 1 && front.y == n - 1)
			{
				minn = min(minn, cnt);
				return;
			}
			for (int i = 0; i < 4; i++)
			{
				int nx = dx[i] + front.x;
				int ny = dy[i] + front.y;
				bool hi = front.hi;
				if (nx >= 0 && nx < n && ny >= 0 && ny < n && arr[nx][ny] >= 1 && !visit[nx][ny])
				{
					if (arr[nx][ny] == 1)
					{
						q.push({ nx,ny,0 });
						visit[nx][ny] = true;
					}
					else if (arr[nx][ny] >= 2)
					{
						if (((cnt + 1) % arr[nx][ny] == 0) && (hi == false))
						{
							q.push({ nx,ny,1 });
							visit[nx][ny] = true;
						}
						else if ((cnt + 1) % arr[nx][ny] != 0 && (hi == false))
						{
							q.push({ front.x,front.y,hi });
						}
					}
				}
			}
		}
		cnt++;
	}

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];

		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 0)
			{
				int cnt1 = 0;
				int cnt2 = 0;
				for (int r = 0; r < 2; r++)
				{
					int nx = dx[r] + i;
					int ny = dy[r] + j;
					if (nx >= 0 && nx < n && ny >= 0 && ny < n && arr[nx][ny] == 0)
						cnt1++;
				}
				for (int r = 2; r < 4; r++)
				{
					int nx = dx[r] + i;
					int ny = dy[r] + j;
					if (nx >= 0 && nx < n && ny >= 0 && ny < n && arr[nx][ny] == 0)
						cnt2++;
				}
				if (!(cnt1 >= 1 && cnt2 >= 1))
				{
					v.push_back({ i,j });//오작교 위치 후보
				}
			}
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		arr[v[i].first][v[i].second] = m;
		bfs();
		arr[v[i].first][v[i].second] = 0;
	}
	cout << minn;
	return 0;
}


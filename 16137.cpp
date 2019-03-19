//https://www.acmicpc.net/problem/16137
/*풀이 : 오작교를 건널 수 있는 경우 : 위 아래가 땅 또는 왼쪽 오른쪽이 땅
경계넘어서는 땅이라고 생각한다. 오작교를 건넌 경우면
flag 값을 true로 하고 또 오작교가 나오면 큐에다가 push 해주지 않는다.
만약 (0,0)이 오작교면 그 오작교는 건넌거라고 생각하지 않는다.(상하좌우가 오작교여도 갈 수 있음)*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;


int arr[11][11];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool visit[11][11];
int n, m;
vector <pii> v;
bool hi;

int bfs()
{
	memset(visit, 0, sizeof(visit));
	int time = 0;
	queue<pii> q;
	q.push({ 0,0 });
	visit[0][0] = true;

	if (arr[0][0] >= 2)
	{
		time = arr[0][0];
	}
	while (!q.empty())
	{
		int sizz = q.size();
		while (sizz--)
		{
			pii front = q.front();
			//cout << front.first << " " << front.second << '\n';
			q.pop();
			if (front.first == n - 1 && front.second == n - 1)
			{
				return time;
			}
			hi = false;
			if (arr[front.first][front.second] >= 2
				&& !(front.first == 0 && front.second == 0))
			{
				if (time%arr[front.first][front.second] != 0)
				{
					q.push({ front.first,front.second });
					continue;
				}
				else
					hi = true;
			}

			for (int i = 0; i < 4; i++)
			{
				int nx = front.first + dx[i];
				int ny = front.second + dy[i];
				if (nx >= 0 && nx < n && ny >= 0 && ny < n && visit[nx][ny] == false
					&& arr[nx][ny] >= 1)
				{
					if (hi == true && arr[nx][ny] != 1)
						continue;
					q.push({ nx,ny });
					visit[nx][ny] = true;
				}
			}
		}
		time++;
	}
	return 1e9;
}


int main()
{
	ios_base::sync_with_stdio(0);

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
			//가능한 좌표를 넣는다. 위 아래가 전부 땅이거나 왼쪽 오른쪽이 전부 땅이면 가능한 좌표
			if (arr[i][j] == 0)
			{
				int cnt = 0;
				for (int k = 0; k < 2; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (!(nx >= 0 && nx < n&&ny >= 0 && ny < n))
					{
						cnt++;
						continue;
					}
					else if (arr[nx][ny] == 1)
					{
						cnt++;
					}
				}
				if (cnt == 2)
				{
					v.push_back({ i,j });
					continue;
				}
				cnt = 0;
				for (int k = 2; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (!(nx >= 0 && nx < n&&ny >= 0 && ny < n))
					{
						cnt++;
						continue;
					}
					else if (arr[nx][ny] == 1)
					{
						cnt++;
					}
				}
				if (cnt == 2)
				{
					v.push_back({ i,j });
				}
			}
		}
	}
	int minn = 1e9;
	for (int i = 0; i < v.size(); i++)
	{
		pii front = v[i];
		arr[front.first][front.second] = m;
		int num = bfs();
		minn = min(minn, num);
		arr[front.first][front.second] = 0;
	}
	cout << minn;

	return 0;
}

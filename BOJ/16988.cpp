//https://www.acmicpc.net/problem/16988
/*풀이 :0인 칸 2개를 선택할 수 있는 가능한 모든 경우를 찾고
각각의 경우에 bfs를 돌려서 잡을 수 있는
상대방의 돌의 개수의 최대값을 찾는다.
시간 복잡도 : 돌을 2개를 놓는 경우 : (N^2*M^2)
bfs 돌리는 경우 N*M
총 N^3*M^3

큐를 전역 변수에 선언하니깐 시간이 4배 가까이가 줄었다.
bfs가 잦게 실행되는데 큐를 지역변수로 선언하면 생각보다 오버헤드가 큰가보다.

*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
int n, m;
int arr[21][21];
vector<pii> v;
bool visit[410];
bool black[21][21];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int maxi;

queue<pii> q;
int bfs(pii start)
{
	bool flag = false;
	black[start.first][start.second] = true;
	q.push(start);
	int cnt = 1;
	while (!q.empty())
	{
		pii front = q.front();
		q.pop();
		for (int i = 0;i < 4;i++)
		{
			int nx = dx[i] + front.first;
			int ny = dy[i] + front.second;
			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (arr[nx][ny] == 2 && !black[nx][ny])
				{
					q.push({ nx,ny });
					black[nx][ny] = true;
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
		return 0;
	return cnt;
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
			if (arr[i][j] == 0)
				v.push_back({ i,j });
		}
	}

	for (int i = 0;i < v.size() - 1;i++)
	{
		arr[v[i].first][v[i].second] = 1;
		for (int j = i + 1;j < v.size();j++)
		{
			arr[v[j].first][v[j].second] = 1;
			int sum = 0;
			memset(black, 0, sizeof(black));
			for (int r = 0;r < n;r++)
			{
				for (int k = 0;k < m;k++)
				{
					if (!black[r][k] && arr[r][k] == 2)
					{
						sum += bfs({ r,k });
					}
				}
			}
			maxi = max(maxi, sum);
			arr[v[j].first][v[j].second] = 0;

		}
		arr[v[i].first][v[i].second] = 0;
	}
	cout << maxi;

	return 0;
}

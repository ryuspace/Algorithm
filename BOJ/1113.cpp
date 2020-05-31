//https://www.acmicpc.net/problem/1113
/*풀이 :
아이디어가 필요했던 문제다.
1~직육면체 최대 높이까지 밖에서 물이 들어온다고 생각하자.
밖에서 bfs를 돌리고 직육면체를 쭉 탐색하는데 현재 들어온 물의 높이 보다 낮은 높이의 직육면체가 있다면 그 직육면체는 물이 찰 것이다.
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int, int> pii;
int n, m;
int arr[53][53];
int maxi;
bool visit[53][53];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int ans;

void bfs(int num)
{
	memset(visit, 0, sizeof(visit));
	queue<pii> q;
	q.push({ 0,0 });
	visit[0][0] = true;
	arr[0][0] = num;
	while (!q.empty())
	{
		pii front = q.front();
		q.pop();
		for (int i = 0;i < 4;i++)
		{
			int nx = dx[i] + front.first;
			int ny = dy[i] + front.second;
			if (nx >= 0 && nx <= n + 1 && ny >= 0 && ny <= m + 1 && !visit[nx][ny] && arr[nx][ny] < arr[front.first][front.second])
			{
				arr[nx][ny] = arr[front.first][front.second];
				visit[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= m;j++)
		{
			char a;
			cin >> a;
			arr[i][j] = a - '0';
			maxi = max(maxi, arr[i][j]);
		}
	}
	
	for (int i = 1;i <= maxi;i++)
	{
		bfs(i);
		for (int j = 1;j <= n;j++)
		{
			for (int r = 1;r <= m;r++)
			{	
				if (arr[j][r] < i)
				{
					ans++;
					arr[j][r]++;
				}
			}
		}
	}
	cout << ans;

	return 0;
}

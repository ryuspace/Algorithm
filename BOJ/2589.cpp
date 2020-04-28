//https://www.acmicpc.net/problem/2589
/*풀이 : 전형적인 bfs지만 어떤 육지 기준으로 좌 우 또는 상 하에 육지가 붙어있으면 그 육지는
절대 보물이 묻혀있을 후보가 될 수 없으므로 이를 제외하고 bfs를 돌리면 시간을 훨씬 단축할 수 있다.
*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
int l, w;
char arr[51][51];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int maxx = 0;

void bfs(int x, int y)
{
	bool visit[51][51] = { 0, };
	int cnt = 0;
	queue<pii> q;
	q.push({ x,y });
	visit[x][y] = true;
	while (!q.empty())
	{
		int sizz = q.size();
		while (sizz--)
		{
			pii front = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = dx[i] + front.first;
				int ny = dy[i] + front.second;
				if (nx >= 0 && nx < l && ny >= 0 && ny < w && !visit[nx][ny] && arr[nx][ny] == 'L')
				{
					q.push({ nx,ny });
					visit[nx][ny] = true;
				}
			}
		}
		cnt++;
	}
	maxx = max(maxx, cnt - 1);
}
int main()
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> l >> w;
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (arr[i][j] == 'L')
			{
				if (i - 1 >= 0 && i + 1 < l && arr[i - 1][j] == 'L' && arr[i + 1][j] == 'L')
					continue;
				if (j - 1 >= 0 && j + 1 < w && arr[i][j - 1] == 'L' && arr[i][j + 1] == 'L')
					continue;
				bfs(i, j);
			}
		}
	}
	cout << maxx;
	return 0;
}

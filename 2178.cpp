//https://www.acmicpc.net/problem/2178
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int n, m;
int arr[101][101];
bool visit[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
void bfs()
{
	int cnt = 1;
	queue<pii> q;
	visit[0][0] = true;
	q.push({ 0,0 });

	while (!q.empty())
	{
		int sizz = q.size();
		while (sizz--)
		{
			pii front = q.front();
			q.pop();
			if (front.first == n - 1 && front.second == m - 1)
			{
				cout << cnt;
				exit(0);
			}
			for (int i = 0; i < 4; i++)
			{
				int nx = dx[i] + front.first;
				int ny = dy[i] + front.second;
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny]&&arr[nx][ny]==1)
				{
					q.push({ nx,ny });
					visit[nx][ny] = true;
				}
			}
		}
		cnt++;
	}


}
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < tmp.length(); j++)
		{
			arr[i][j] = tmp[j] - '0';
		}
	}
	bfs();
	return 0;
}

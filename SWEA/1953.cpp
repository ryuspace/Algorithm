/*1953번 탈주범 검거
풀이 : 터널 모양에 따른 뚫린 위치의 배열을 미리 선언해 놓고
현재 터널이 모양에 이어질 수 있는 터널이 다음 위치에 있을 때만 큐에 넣어준다.
*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int arr[51][51];
int n, m, r, c, l;
//상좌하우
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int pyo[8][4] = {
	{1,1,1,1},{1,0,1,0},{0,1,0,1},{1,0,0,1},
{0,0,1,1},{0,1,1,0},{1,1,0,0}
};//터널 모양에 따른 뚫린 위치
int bfs(pii start)
{
	int cntt = 1;
	bool visit[51][51] = {};
	queue<pii> q;
	q.push(make_pair(start.first, start.second));
	visit[start.first][start.second] = 1;
	int cnt = 1;
	while (!q.empty())
	{
		int sizz = q.size();
		if (cntt == l)
			return cnt;
		while (sizz--)
		{
			pii front = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = front.first + dx[i];
				int ny = front.second + dy[i];
				if (nx >= 0 && nx < n&&ny >= 0 && ny < m && !visit[nx][ny] && arr[nx][ny] != 0)
				{
					if (pyo[arr[nx][ny]-1][(i + 2) % 4] == 1 &&
						pyo[arr[front.first][front.second]-1][i] == 1)
					{
					
						q.push(make_pair(nx, ny));
						visit[nx][ny] = true;
						cnt++;
					}
				}
			}
		}
		cntt++;
	}
	return cnt;
}
int main()
{
	ios_base::sync_with_stdio(0);
	freopen("t.txt", "r", stdin);
	int t;
	cin >> t;
	for (int q = 1; q <= t; q++)
	{
		cin >> n >> m >> r >> c >> l;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> arr[i][j];
			}
		}
		cout<<"#"<<q<<" "<<bfs(make_pair(r, c))<<'\n';

	}
	return 0;
}

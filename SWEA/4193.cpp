/*4193번 수영대회 결승전
풀이 : 기본적으로 bfs를 이용해 최단경로를 찾는다. 
(현재시간+1)%3==0이면 소용돌이를 건널 수 있다. 못 건너면 원래 좌표를 다시 큐에다가 넣어준다.
*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int t, n;
int arr[16][16];
pii start, des;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int bfs()
{
	bool visit[16][16] = { 0, };
	int time = 0;
	queue <pii> q;
	q.push(start);
	visit[start.first][start.second] = true;
	while (!q.empty())
	{
		int sizz = q.size();
		while (sizz--)
		{
			pii front = q.front();
			q.pop();
			if (front.first == des.first && front.second == des.second)
			{
				return time;
			}
			for (int i = 0; i < 4; i++)
			{
				int nx = dx[i] + front.first;
				int ny = dy[i] + front.second;
				if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visit[nx][ny] && arr[nx][ny] != 1)
				{
					if (arr[nx][ny] == 0)
					{
						q.push({ nx,ny });
						visit[nx][ny] = true;
					}
					else if (arr[nx][ny] == 2 && (time + 1) % 3 == 0)
					{
						q.push({ nx,ny });
						visit[nx][ny] = true;
					}
					else if(arr[nx][ny]==2 && (time+1)%3!=0)
					{
						q.push({ front.first,front.second });
					}
				}
			}
		}
		time++;
	}
	return -1;
}
int main()
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	for (int r = 1; r <= t; r++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
			}
		}
		cin >> start.first >> start.second;
		cin >> des.first >> des.second;
		cout << "#" << r << " " << bfs() << '\n';
	}
	return 0;
}

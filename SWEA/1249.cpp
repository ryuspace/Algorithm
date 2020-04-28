/*1249번 보급로
풀이 : bfs를 돌리는데 현재 온 위치가 이전에 왔던 기록보다 적은 수로 오면 큐에 추가한다.
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

struct point
{
	int x, y, value;
};
int t,n;
int arr[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int minn = 1e9;
void bfs()
{
	int visit[101][101];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			visit[i][j] = 1e9;
		}
	}
	queue<point> q;
	q.push({ 0,0,0 });
	while (!q.empty())
	{
		point front = q.front();
		q.pop();
		if (front.x == n - 1 && front.y == n - 1)
		{
			minn = min(minn, front.value);
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + front.x;
			int ny = dy[i] + front.y;
			int value = front.value;
			if (nx >= 0 && nx < n && ny >= 0 && ny<n && visit[nx][ny]>value + arr[nx][ny])
			{
				visit[nx][ny] = value + arr[nx][ny];
				q.push({ nx,ny,value + arr[nx][ny] });
			}
		}
	}
}
int main()
{
	freopen("Text.txt","r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	for (int r = 1; r <= t; r++)
	{
		minn = 1e9;
		cin >> n;
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
		cout << "#" << r << " " << minn << '\n';
	}
	return 0;
}


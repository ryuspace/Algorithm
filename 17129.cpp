//https://www.acmicpc.net/problem/17129
/*풀이 : 단순 bfs 문제*/
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
int n, m;
int arr[3001][3001];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool visit[3001][3001];
queue <pii> q;

int bfs()
{
	int time = 0;
	while (!q.empty())
	{
		int sizz = q.size();
		while (sizz--)
		{
			pii front = q.front();
			q.pop();
			if (arr[front.first][front.second] >= 3 &&
				arr[front.first][front.second] <= 5)
				return time;
			for (int i = 0; i < 4; i++)
			{
				int nx = dx[i] + front.first;
				int ny = dy[i] + front.second;
				if (nx < 0 || nx >= n || ny < 0 || ny >= m)
					continue;
				if (!visit[nx][ny] && arr[nx][ny] != 1)
				{
					visit[nx][ny] = true;
					q.push({ nx,ny });
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
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = tmp[j] - '0';
			if (arr[i][j] == 2)
			{
				q.push(make_pair(i, j));
			}	
		}
	}
	int hi = bfs();
	if (hi== 1e9)
		cout << "NIE";
	else
	{
		cout << "TAK" << '\n' << hi ;
	}
	return 0;
}

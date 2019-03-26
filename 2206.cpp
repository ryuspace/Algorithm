//https://www.acmicpc.net/problem/2206
/*풀이 : 기본적인 bfs에서 벽을 부순적이 있는지 체크하는 배열을 하나 더 만든다.
방문한 적이 있는지 체크할 때도 벽을 부순적이 있는지 여부로 판단해야 한다.*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int, int> pii;

int n, m;
int arr[1001][1001];
bool visit[1001][1001][2];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

struct info
{
	int x, y, z;//z는 부순적이 있는지 체크
};
int bfs()
{
	int cnt = 1;
	queue <info> q;
	q.push({ 0,0,0 });
	while (!q.empty())
	{
		int sizz = q.size();
		while (sizz--)
		{
			info front = q.front();
			q.pop();
			if (front.x == n - 1 && front.y == m - 1)
				return cnt;
			for (int i = 0; i < 4; i++)
			{
				int nx = dx[i] + front.x;
				int ny = dy[i] + front.y;
	

				if (!visit[nx][ny][front.z]&&nx >= 0 && nx < n && ny >= 0 && ny < m)
				{
					if (arr[nx][ny] == 0)
					{
						q.push({ nx,ny,front.z });
						visit[nx][ny][front.z] = true;
					}
					if (arr[nx][ny] == 1 && front.z==0)
					{
						q.push({ nx,ny,1 });
						visit[nx][ny][1] = true;
					}
				}
			}
		}
		cnt++;
	}
	return -1;
}
int main()
{
	int minn = 1e9;
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
	cout << bfs();
	return 0;

}


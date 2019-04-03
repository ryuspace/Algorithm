//https://www.acmicpc.net/problem/3197
/*풀이 : 모든 경우 bfs를 돌리면 1500^4이므로 시간초과가 난다.
물의 위치를 전부 큐에 넣고 물에 인접한 빙산을 녹인 시간을
맵에다 체크한다. 그리고 한 백조의 위치에서 다른 백조를 만나게 하는
bfs를 돌리는데. 이는 이분탐색으로 찾는다. 
n시간에 녹은 상태에서 백조가 만날 수 있으면
n+1시간에 녹은 상태에서 백조도 무조건 만날 수 있다.
시간복잡도는 (1500^2)*log(1500^2)*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;
int r, c;
char map[1501][1501];
bool visit[1501][1501];
int mov[1501][1501];
queue <pii> water;
vector <pii> bird;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int bfs_w()
{
	int cnt = 1;
	while(!water.empty())
	{
	
		int sizz = water.size();
		while (sizz--)
		{
			pii front = water.front();
			water.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = dx[i] + front.first;
				int ny = dy[i] + front.second;
				if (nx >= 0 && nx < r && ny >= 0 && ny < c && !visit[nx][ny] &&
					map[nx][ny] == 'X')
				{
					map[nx][ny] = '.';
					water.push({ nx,ny });
					mov[nx][ny] = cnt;
					visit[nx][ny] = true;
				}
			}
		}
		cnt++;
		
	}
	return cnt-1;
}
bool bfs_b(int num)
{
	memset(visit, 0, sizeof(visit));
	queue<pii> q;
	visit[bird[0].first][bird[0].second]= true;
	q.push({ bird[0].first,bird[0].second });
	while (!q.empty())
	{
		pii front = q.front();
		q.pop();
		if (front.first == bird[1].first && front.second == bird[1].second)
			return true;
		for (int i = 0; i < 4; i++)
		{
			int nx = front.first + dx[i];
			int ny = front.second + dy[i];
			if (nx >= 0 && nx < r && ny >= 0 && ny < c && mov[nx][ny] <= num && !visit[nx][ny])
			{
				q.push({ nx,ny });
				visit[nx][ny] = true;
			}
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == '.'||map[i][j]=='L')
			{
				water.push({ i,j });
			}
			if (map[i][j] == 'L')
			{
				bird.push_back({ i,j });
			}
		}
	}
	int left = 0;
	int right= bfs_w();
	int ans = 1e9;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (bfs_b(mid))
		{
			ans = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	cout << ans;
	return 0;
}

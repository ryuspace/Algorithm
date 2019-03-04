//https://www.acmicpc.net/problem/7569
/*풀이 : 3차원 배열을 bfs로 처음 돌려봤다. 방향은 상하좌우위아래 총 6개 이다.
안 익은 토마토 갯수를 미리 세놓고 처음 익은 토마토 위치를 큐에 넣어놓고
큐의 사이즈만큼 방향을 찾아보고 level을 올렸다.*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int arr[100][100][100];
bool visit[100][100][100];
int dx[6] = { -1,1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6]= { 0,0,0,0,-1,1 };
int m_, n_, h_;
int maxx= 0;
int cnt = 0;
int ans = 0;
queue< pair< int, pair<int, int> > > q;


void bfs()
{
	while (!q.empty())
	{
		int sizz = q.size();

		while (sizz--)
		{
			pair< int, pair<int, int> > front = q.front();
			q.pop();
			for (int i = 0; i < 6; i++)
			{
				int nx = front.second.first + dx[i];
				int ny = front.second.second + dy[i];
				int nz = front.first + dz[i];

				if (nx >= 0 && nx < n_  && ny >= 0 && ny < m_
					&& nz >= 0 && nz < h_ && arr[nz][nx][ny] == 0)
				{
					q.push({ nz,{ nx,ny } });
					arr[nz][nx][ny] = 1;
					cnt--;
				}
			}
		}
		ans++;

	}
	if (cnt == 0)
	{
		cout << ans-1;
	}
	else
	{
		cout << -1;
	}
}
int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	
	cin >> m_ >> n_ >> h_;
	for (int i = 0; i < h_; i++)
	{
		for (int j = 0; j < n_; j++)
		{
			for (int r = 0; r < m_; r++)
			{
				cin >> arr[i][j][r];
				if (arr[i][j][r] == 0)
					cnt++;
			}
		}
	}

	for (int i = 0; i < h_; i++)
	{
		for (int j = 0; j < n_; j++)
		{
			for (int r = 0; r < m_; r++)
			{
				if (arr[i][j][r]== 1)
				{
					q.push({ i,{j,r} });
				}
			}
		}
	}
	bfs();
}

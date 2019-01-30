//https://www.acmicpc.net/problem/16768
/*풀이 :*bfs를 돌려 k개 이상의 숫자가 몰려있을때 그 자리들을 0으로 처리한다.*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

int arr[101][101];
bool visit[101][101];
bool visit2[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };

int n, k;
queue < pair<int, int> > q;
queue < pair<int, int> > q2;
int bfs(int x, int y)
{
	int cnt = 1;
	int color = arr[x][y];
	visit[x][y] = true;
	q.push({ x,y });

	while (!q.empty())
	{
		pair <int, int> front = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = front.first + dx[i];
			int ny = front.second + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < 10 && visit[nx][ny] == false && arr[nx][ny] == color)
			{
				q.push({ nx,ny });
				visit[nx][ny] = true;
				cnt++;
			}
		}
	}
	return cnt;

}

void bfs2(int x, int y)
{
	int color = arr[x][y];
	arr[x][y] = 0;
	visit2[x][y] = true;
	q2.push({ x,y });

	while (!q2.empty())
	{
		pair <int, int> front = q2.front();
		q2.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = front.first + dx[i];
			int ny = front.second + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < 10 && visit2[nx][ny] == false && arr[nx][ny] == color)
			{
				q2.push({ nx,ny });
				visit2[nx][ny] = true;
				arr[nx][ny] = 0;
			}
		}
	}

}
int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < 10; j++)
		{
			arr[i][j] = tmp[j] - '0';
		}
	}


	while (true)
	{


		int cnt = 0;
		memset(visit, 0, sizeof(visit));
		memset(visit2, 0, sizeof(visit2));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (arr[i][j] != 0 && visit[i][j] == false)
				{

					if (bfs(i, j) >= k)
					{
						cnt++;
						bfs2(i, j);
					}
				}
			}
		}

		for (int i = 0; i < 10; i++)
		{
			int start = n - 1;
			for (int j = n - 1; j >= 0; j--)
			{
				if (arr[j][i] != 0)
				{
					arr[start][i] = arr[j][i];
					if (start != j)
					{
						arr[j][i] = 0;
					}

					start--;
				}
			}
		}

		memset(visit, 0, sizeof(visit));
		cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (arr[i][j] != 0 && visit[i][j] == false)
				{
					if (bfs(i, j) >= k)
					{
						cnt++;
					}
				}
			}
		}
		if (cnt == 0)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					cout << arr[i][j];
				}
				cout << '\n';
			}
			exit(0);
		}
	}


	return 0;
}

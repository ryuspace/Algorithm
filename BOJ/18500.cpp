//https://www.acmicpc.net/problem/18500
/*풀이 :
미네랄 1이랑 같은 문제지만 데이터가 추가되었다.
기존 방식 : 가장 하단의 미네랄을 하나 찾아 bfs를 이용해 기저 미네랄 클러스터를 찾는다.
밑에서부터 탐색하는데 기저 미네랄 클러스터의 일부가 아닌 미네랄을 찾아 몇 칸 까지 내려갈 수 있는지 찾는다. 
가장 밑에 행에서 미네랄 만날 때 까지만 찾고 break 했는데 반례가 있었다.
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;
int r, c, n;
char arr[101][101];
bool visit[101][101];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
void bfs(int rr,int cc)
{
	queue<pii> q;
	q.push({ rr,cc });
	visit[rr][cc] = true;

	while (!q.empty())
	{
		pii front = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + front.first;
			int ny = dy[i] + front.second;
			if (nx >= 0 && nx < r && ny >= 0 && ny < c && !visit[nx][ny] && arr[nx][ny] == 'x')
			{
				q.push({ nx,ny });
				visit[nx][ny] = true;
			}
		}
	}


}
void check(int num,int dir)
{
	memset(visit, 0, sizeof(visit));
	int high = r - num;

	if (dir == 0)
	{
		int cnt = 0;
		while (arr[high][cnt] != 'x' && cnt < c)
		{
			cnt++;
		}
		if (cnt < c)
		{
			arr[high][cnt] = '.';
			for (int i = 0; i < c; i++)
			{
				if (arr[r - 1][i] == 'x' && !visit[r-1][i])
				{
					bfs(r - 1, i);
				}
			}
			int mini = 1e9;
			for (int i = 0; i < c; i++)
			{
				for (int j = r - 2; j >= 0; j--)
				{
					if (!visit[j][i] && arr[j][i] == 'x')
					{
						int start = j + 1;
						int cnt = 0;
						while (start < r && arr[start][i] == '.')
						{
							cnt++;
							start++;
						}
						if (start < r && visit[start][i] == false)
							break;
						mini = min(mini, cnt);

					}
				}
			}
			if (mini >= 1e9)
				return;

			for (int i = r - 1; i >= 0; i--)
			{
				for (int j = 0; j < c; j++)
				{
					if (!visit[i][j] && arr[i][j] == 'x')
					{

						arr[i][j] = '.';
						arr[i + mini][j] = 'x';

					}
				}
			}
		}
		else
		{
			return;
		}
	}
	else
	{
		int cnt = c-1;
		while (arr[high][cnt] != 'x' && cnt >=0)
		{
			cnt--;
		}
		if (cnt >=0)
		{
			arr[high][cnt] = '.';
			for (int i = 0; i < c; i++)
			{
				if (arr[r - 1][i] == 'x' &&!visit[r-1][i])
				{
					bfs(r - 1, i);
				}
			}
			int mini = 1e9;
			for (int i = 0; i < c; i++)
			{
				for (int j = r - 2; j >= 0; j--)
				{
					if (!visit[j][i] && arr[j][i] == 'x')
					{
						int start = j + 1;
						int cnt = 0;
						while (start < r && arr[start][i] == '.')
						{
							cnt++;
							start++;
						}
						if (start < r && visit[start][i] == false)
							break;
						mini = min(mini, cnt);
					}
				}
			}

			if (mini >= 1e9)
				return;
			for (int i = r-1; i>=0; i--)
			{
				for (int j = 0; j < c; j++)
				{
					if (!visit[i][j] && arr[i][j] == 'x')
					{

						arr[i][j] = '.';
						arr[i + mini][j] = 'x';

					}
				}
			}
		}
		else
		{
			return;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> arr[i][j];
		}
	}

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		check(a,i%2);
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << arr[i][j];
		}
		cout << '\n';
	}
	return 0;
}

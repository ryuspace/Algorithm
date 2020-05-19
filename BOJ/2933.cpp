//https://www.acmicpc.net/problem/2933
/*풀이 :한 칸씩 없어지니까 여러 조각 조각이 우수수 떨어지는건 불가능.
클러스터 하나가 떨어질 수 밖에 없다. 원래 다 이어졌으니까 
핵심 : 맨 아래 첫번째 줄을 bfs 돌리면 밑에 큰 클러스터가 인식이 된다. 방문되지
않은 'x'는 클러스터가 아님. 밑으로 떨어뜨려야 한다. 합칠때는 미네랄과 클러스터의
열의 차이의 최소만큼 갈 수 있다. 어려웠다!!
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

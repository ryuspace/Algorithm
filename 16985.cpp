//https://www.acmicpc.net/problem/16985
/*풀이 : dfs가 여러개 중첩될 때는 가장 시간이 오래 걸리는 dfs부터 실행시켜주자.
1.순서 정하기 2.돌리기 이 순서로 하는데
돌릴 때 (0,0)과 (4,4)가 1이 아니면 그 다음 단계인 bfs를 할 필요 없다. 그리고
12번 이동한 경우가 있으면 이미 최소므로 더 할 필요 없다.
*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct point
{
	int x, y, z;
};
int jemul[5] = { 0,1,2,3,4 };
int arr[6][6][6];
int hi[6][6][6];
bool visit[6];
bool visit2[6];
int dx[6] = { -1,1,0,0,0,0 };
int dy[6] = { 0,0,-1,1,0,0 };
int dz[6] = { 0,0,0,0,-1,1 };
int minn = 1e9;
int play()
{
	int cnt = 0;
	bool visit3[6][6][6] = { 0, };
	queue<point> q;

	q.push({ 0,0,0 });
	visit3[0][0][0] = true;
	while (!q.empty())
	{
		int sizz = q.size();
		while (sizz--)
		{
			point front = q.front();
			q.pop();
			if (front.x == 4 && front.y == 4 && front.z == 4)
			{
				return cnt;
			}
			if (cnt >= minn)
				return minn;
			for (int i = 0; i < 6; i++)
			{
				int nx = dx[i] + front.x;
				int ny = dy[i] + front.y;
				int nz = dz[i] + front.z;
				if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && nz >= 0 && nz < 5 && !visit3[nx][ny][nz] &&
					hi[nx][ny][nz] == 1)
				{
					q.push({ nx,ny,nz });
					visit3[nx][ny][nz] = true;
				}
			}

		}
		cnt++;
	}
	return 1e9;
}
void rot(int num)
{
	int tmp[6][6] = { 0, };
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			tmp[i][j] = hi[num][i][j];
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			hi[num][i][j] = tmp[4 - j][i];
		}
	}
}
void dfs2(int cnt)
{
	if (cnt == 5)
	{
		if(hi[4][4][4]==1)
			minn = min(minn, play());
		if (minn == 12)
		{
			cout << 12;
			exit(0);
		}
		return;
	}
	for (int j = 0; j < 4; j++)
	{
		rot(cnt);
		if(hi[0][0][0]==1)
			dfs2(cnt + 1);
	}
}

int main()
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for (int r = 0; r < 5; r++)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				cin >> arr[r][i][j];
			}
		}
	}
	do
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				for (int r = 0; r < 5; r++)
				{
					hi[i][j][r] = arr[jemul[i]][j][r];
				}
			}
		}
		dfs2(0);

	} while (next_permutation(jemul, jemul + 5));
	if (minn == 1e9)
		cout << -1;
	else
		cout << minn;
	return 0;
}

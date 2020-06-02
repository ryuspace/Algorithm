/*1949번 등산로 조성
풀이 :
가장 높은 지점을 기준으로 dfs를 돌리는데
산이 깎인적이 있는 경우, 없는 경우로 나눈다.
now는 현재 높이가 어떤 산에서 넘어왔는지 체크한다.
그 이유는 다른 곳에서 온 등산로는 깎이지 않은 상태로 보여야 하기 때문이다.
직접적으로 map을 바꾸지 않음.
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
int t;
int n, k;
int arr[9][9];

bool visit[9][9];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int maxx;
void dfs(int x, int y, bool flag,int cnt,int now)
{
	maxx = max(maxx, cnt);
	for (int i = 0;i < 4;i++)
	{
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visit[nx][ny])
		{
			if (arr[nx][ny] >= now)
			{
				if (flag == 0 && arr[nx][ny] - now < k)
				{
					visit[nx][ny] = true;
					dfs(nx, ny, 1, cnt + 1, now -1);
					visit[nx][ny] = false;
				}
			}
			else
			{
				visit[nx][ny] = true;
				dfs(nx, ny, flag, cnt+1, arr[nx][ny]);
				visit[nx][ny] = false;
			}
		}
	}
}
int main()
{
	freopen("Test.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	for (int q = 1;q <= t;q++)
	{
		maxx = 0;
		int maxi = 0;
		cin >> n >> k;

		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < n;j++)
			{
				cin >> arr[i][j];
				maxi = max(maxi, arr[i][j]);
			}
		}

		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < n;j++)
			{
				if (arr[i][j] == maxi)
				{
					visit[i][j] = true;
					dfs( i,j, 0, 1,arr[i][j]);
					visit[i][j] = false;
				}
				
			}
		}
		cout << "#" << q << " " << maxx << '\n';

	}
	return 0;
}

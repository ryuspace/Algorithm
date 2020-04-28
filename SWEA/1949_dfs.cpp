/*1949번 등산로 조성
풀이 :
가장 높은 지점을 미리 벡터에 담아놓고 dfs를 돌리는데
산이 깎인적이 있는 경우, 없는 경우로 나눈다.
front.value는 산을 깎았으면 깎인 값을 큐에 넣어주기 위함이다.
그 이유는 다른 곳에서 온 등산로는 깎이지 않은 상태로 보여야 하기 때문이다.
직접적으로 map을 바꾸지 않음.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
typedef pair<int, int> pii;
int t, n, k;
int arr[9][9];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int hi = 0;
bool visit[9][9];
void dfs(int x,int y,int value,int len,int flag)
{
	hi = max(hi, len);
	for (int i = 0; i < 4; i++)
	{
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if (nx >= 0 && nx < n && ny >= 0  && ny< n && !visit[nx][ny])
		{
			if (value > arr[nx][ny])
			{
				visit[nx][ny] = true;
				dfs(nx, ny, arr[nx][ny], len + 1, flag);
				visit[nx][ny] = false;
			}
			else
			{
				if (k >= abs(value - arr[nx][ny])+1 && flag == 0 && value >=1)
				{
					visit[nx][ny] = true;
					dfs(nx, ny, value - 1, len + 1, 1);
					visit[nx][ny] = false;
				}
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
		hi = 0;
		int maxx = 0;
		vector <pii> v;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
				maxx = max(maxx, arr[i][j]);
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (arr[i][j] == maxx)
				{
					v.push_back({ i,j });
				}
			}
		}
		for (int i = 0; i < v.size(); i++)
		{
			visit[v[i].first][v[i].second] = true;
			dfs(v[i].first, v[i].second, arr[v[i].first][v[i].second], 1,0);
			visit[v[i].first][v[i].second] = false;
		}
		cout << "#" << r << " " << hi << '\n';
	}
	
	return 0;
}


//https://www.acmicpc.net/problem/2169
/*풀이 : 어떤 한 위치에 대해서 왼쪽 오른쪽 아래에서 오는 세 가지 경우중 최대값을 저장하는 dp 배열을
선언한다. visit 처리를 해 주어서 갔던 곳은 다시 못 가게 한다.
세 가지 경우로 나누는 이유는 잘 생각해보면 dp[x][y]를 한번 값을 set 했다고 항상 최대값일 보장이 없다. 어느 방향에서 왔냐에 따라 재귀 호출
될 범위가 달라질 수 있기 때문이다.(어렵)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
long long int arr[1001][1001];
long long int dp[3][1001][1001];//0 : 왼쪽에서 온 것, 1 : 오른쪽에서 온 것 2 : 아래에서 온 것
bool visit[1001][1001];
int dx[3] = { 0,0,1 };
int dy[3] = { -1,1,0 };
//왼쪽 오른쪽 아래쪽
long long int dfs(int dir, int x, int y)
{
	long long int guest[3];
	guest[0] = guest[1] = guest[2] = -2e9;
	if (x == n - 1 && y == m - 1)
		return arr[x][y];
	if (dp[dir][x][y] != -2e9)
		return dp[dir][x][y];
	visit[x][y] = true;
	for (int i = 0; i < 3; i++)
	{
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny])
		{
			guest[i] = dfs(i, nx, ny);
		}
	}
	visit[x][y] = false;
	return dp[dir][x][y]=max({ guest[0],guest[1],guest[2] }) + arr[x][y];
	//세 방향 중에서 온 값 중 최대값을 dp 배열에 넣는다.
}
int main()
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			dp[0][i][j] = dp[1][i][j] = dp[2][i][j] = -2e9;
		}
	}
	cout << dfs(0, 0, 0);
	return 0;
}

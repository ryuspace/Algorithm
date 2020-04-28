//https://www.acmicpc.net/problem/1103
/*풀이 : 한번 간 경로는 미리 메모이제이션 해서 다시 못 가게 한다.
만약 이미 방문한 곳을 다시 방문하려고 하면 무한반복 되므로 -1을 출력하고 꺼버린다.
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int n, m;
bool visit[51][51];
char arr[51][51];
int dp[51][51];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int dfs(int r, int c)
{
	if (dp[r][c] < 0)
		dp[r][c] = 0;
	if (dp[r][c] > 0)
		return dp[r][c] + 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = dx[i]*(arr[r][c]-'0') + r;
		int ny = dy[i]*(arr[r][c]-'0') + c;
		if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
			arr[nx][ny]!='H')
		{
			if (visit[nx][ny] == true)
			{
				cout << -1;
				exit(0);
			}
			visit[nx][ny] = true;
			dp[r][c] = max(dp[r][c], dfs(nx, ny));
			visit[nx][ny] = false;
		}
	}
	return dp[r][c] + 1;
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
		string tmp;
		cin >> tmp;
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = tmp[j];
		}
	}
	fill(&dp[0][0], &dp[n][m], -1);
	visit[0][0] = true;
	cout << dfs(0, 0);
	return 0;
}


//https://www.acmicpc.net/problem/1520
/*풀이 : dp를 이용해서 이미 갔던 경로를 다시 세지 않게 해준다.
현재를 기준으로 가지 않았던 방향으로 계속 개척해나가다가 목적지에 도착하면 1을 리턴해준다.

*/
#include <iostream>
#include <algorithm>

using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int dp[501][501];
int arr[501][501];
int m, h;

int dfs(int x,int y)
{
	if (dp[x][y] != -1)
	{
		return dp[x][y];
	}
	dp[x][y] = 0;
	if (x == m - 1 && y == h - 1)
		return dp[x][y]=1;
	//마지막 위치에서 다음 위치로 탐색할 때 물어올 건 없으니까 무조건 1..
	for (int i = 0; i < 4; i++)
	{
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if(nx>=0&&nx<m&&ny>=0&&ny<h&&arr[x][y]>arr[nx][ny])
			dp[x][y]+= dfs(nx, ny);
		//현재 위치에서 다음 위치로 탐색할 때 몇 개의 정답을 물어오는가..
	}
	return dp[x][y];
}
int main()
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> h;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < h; j++)
		{
			cin >> arr[i][j];
		}
	}
	fill(&dp[0][0], &dp[m][h], -1);
	cout << dfs(0, 0);
	return 0;
}

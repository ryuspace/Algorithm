//https://www.acmicpc.net/problem/1937
/*풀이 : 
dp + dfs 문제.
이미 방문한 지역은 들리지 않게 하는게 포인트.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int arr[501][501];
int dp[501][501];
int n;
//동남서북
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int dfs(int x,int y)
{
	if (dp[x][y] < 0)
		dp[x][y] = 0;
	else
		return dp[x][y] + 1;//이미 방문한 지역이다. 메모이제이션을 이용해 들어갈 수 있는 깊이를 리턴해준다.
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
			arr[x][y] < arr[nx][ny])
		{
			dp[x][y] = max(dp[x][y], dfs(nx, ny));
		}
	}
	return dp[x][y] + 1;//저장된 나의 깊이를 리턴해준다.
}
int main()
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			dp[i][j] = -1;
		}
	}
	int maxx = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			maxx=max(dfs(i, j),maxx);
		}
	}
	cout << maxx ;
	return 0;
}

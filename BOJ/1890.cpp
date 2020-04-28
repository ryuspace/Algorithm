//https://www.acmicpc.net/problem/1890
/*풀이 : 모든 맵이 0으로 뒤덮혀 있을 수도 있으니까 dp배열을 -1로 초기화 한다.
그리고 방문했으면 0으로 바꿔서 이미 방문된 지역이면 더 방문하지 않게 한다.
dp[x][y] : x,y 지역을 거쳐 목적지까지 가는 경로의 갯수.*/
#include <iostream>
#include <algorithm>

using namespace std;

int arr[101][101];
long long int dp[101][101];
int dx[2] = { 0,1 };
int dy[2] = { 1,0 };
int n;
long long int dfs(int x, int y)
{
	if (x == n - 1 && y == n - 1)
		return 1;
	if (dp[x][y] >= 0)
		return dp[x][y];
	dp[x][y] = 0;
	for (int i = 0; i < 2; i++)
	{
		int nx = (dx[i]*arr[x][y]) + x;
		int ny = (dy[i]*arr[x][y]) + y;
		if(nx>=0 && nx<n &&ny>=0 &&ny<n)
			dp[x][y] += dfs(nx, ny);//경로에 추가한다.
	}
	return dp[x][y];

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
	cout << dfs(0, 0);

	return 0;
}

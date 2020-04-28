//https://www.acmicpc.net/problem/14503
/*풀이 : 조건이 계속 반복되므로 방향을 맞추고 dfs를 돌린다.*/
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int r, c, d;
int arr[51][51];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };//북서남동

int ans = 0;
void dfs(int x, int y, int d)
{
	if (arr[x][y] == 1)
		return;
	if (arr[x][y] == 0)//현재 위치를 청소한다
	{
		arr[x][y] = 2;
		ans++;
	}
	for (int i = 0; i < 4; i++)//현재방향 기준 왼쪽으로 탐색 
	{
		d= (d + 1) % 4;//현재방향 기준 왼쪽 방향
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (arr[nx][ny] == 0)//청소할 공간이 있으면 방향을 더 탐색하지 않아도 된다.
		{
			dfs(nx, ny, d);
			return;
		}
	}
	//for 문 4번 돌면 원래 방향으로 돌아와있다.
	//네 방향 모두 청소가 되어있는 경우
	x += dx[(d + 2) % 4];
	y += dy[(d + 2) % 4];//후진한다.
	dfs(x, y, d);//후진하고 원래 방향으로 다시 dfs를 돌린다. 
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i <n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	if (d == 1)
		dfs(r, c, 3);
	else if (d == 3)
		dfs(r, c, 1);
	else
		dfs(r, c, d);

	cout << ans;
	return 0;
}

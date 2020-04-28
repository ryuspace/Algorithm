/*2105번 디저트 카페
풀이 : 어떤 좌표에서 밑으로 사각형을 그리는데
가능한 모든 사각형을 그려본다.
*/
#include <iostream>
#include <algorithm>
#include <cstring>;
using namespace std;

int dx[4] = { 1,1,-1,-1 };
int dy[4] = { 1,-1,-1,1 };
int n;
int arr[21][21];
bool visit[101];
int maxx = -1;
void dfs(int ori_x,int ori_y,int x,int y,int dir,int cnt)
{
	if (x < 0 || x >= n || y < 0 || y >= n)
		return;
	if (dir == 4)
		return;
	if (dir == 3 && x==ori_x&& y==ori_y)
	{
		maxx = max(cnt, maxx);
		return;
	}
	if (!visit[arr[x][y]])
	{
		visit[arr[x][y]] = true;
		dfs(ori_x,ori_y,x+dx[dir],y+dy[dir],dir,cnt+1);
		visit[arr[x][y]] = false;
	}
	if (!visit[arr[x][y]])
	{
		visit[arr[x][y]] = true;
		dfs(ori_x,ori_y,x + dx[(dir+1)%4], y + dy[(dir+1)%4], dir+1, cnt + 1);
		visit[arr[x][y]] = false;
	}

}
int main()
{
	int t;
	cin >> t;
	for (int r = 1; r <= t; r++)
	{
		maxx = -1;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				memset(visit, 0, sizeof(visit));
				dfs(i,j,i, j, 0,0);
			}
		}
		cout << '#' << r << " " << maxx << '\n';
	}

	return 0;
}

//https://www.acmicpc.net/problem/17070
/*풀이 : 이전 타입을 기억해서 다음 가능한 타입을 선택해준다. 목적지에 도달할 때 까지
반복.*/
#include <iostream>
#include <algorithm>

using namespace std;
int n;
int arr[17][17];
bool visit[17][17];
int res = 0;
//0 :가로 , 1: 세로 , 2: 대각선
void dfs(int type,int r, int c)
{
	if (r >= n - 1 && c >= n - 1)
	{
		if (r == n - 1 && c == n - 1)
		{
			res++;
		}
		return;
	}
	if (type == 1|| type == 2)//세로로
	{
		if (r + 1<n && arr[r + 1][c] == 0 && !visit[r + 1][c])
		{
			visit[r + 1][c] = true;
			dfs(1,r + 1, c);
			visit[r + 1][c] = false;
		}
	}
	if (type == 0 || type == 2)//가로로
	{
		if (c + 1<n &&arr[r][c + 1] == 0 && !visit[r][c + 1])
		{
			visit[r][c + 1] = true;
			dfs(0,r, c + 1);
			visit[r][c + 1] = false;
		}
	}
	if (type == 0 || type == 1 || type == 2)
	{
		if (r + 1<n && c + 1<n &&arr[r + 1][c] == 0 && !visit[r + 1][c]
			&& arr[r][c + 1] == 0 && !visit[r][c + 1] &&
			arr[r + 1][c + 1] == 0 && !visit[r + 1][c + 1])
		{
			visit[r + 1][c] = true;
			visit[r][c + 1] = true;
			visit[r + 1][c + 1] = true;
			dfs(2,r + 1, c + 1);
			visit[r + 1][c] = false;
			visit[r][c + 1] = false;
			visit[r + 1][c + 1] = false;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	visit[0][0] = true;
	visit[0][1] = true;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	dfs(0,0, 1);
	cout << res;
	return 0;
}

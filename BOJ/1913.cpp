//https://www.acmicpc.net/problem/1913
#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
int n,m;
int arr[1001][1001];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
//아래 오른 위 왼 순서로 방향 전환
int main()
{
	ios_base::sync_with_stdio(0);
	pii start = { 0,0 };
	
	pii ans = { 1,1 };
	int dir = 0;
	cin >> n >> m;
	arr[0][0] = n * n;
	for (int i = n * n-1; i >= 1; i--)
	{
		if (arr[start.first+dx[dir]][start.second+dy[dir]] != 0
			|| start.first + dx[dir] <0 || start.first + dx[dir] > n-1
			|| start.second +dy[dir]<0 || start.second+dy[dir]> n-1)//이미 숫자가 있거나 범위 밖으로 나가야 할 경우 방향전환을 해준다.
		{
			dir = (dir + 1) % 4;
		}
		
		start.first += dx[dir];
		start.second += dy[dir];
		arr[start.first][start.second] = i;
		if (i == m)
		{
			ans.first = start.first+1;
			ans.second = start.second + 1;
		}
	}
	for (int r = 0; r < n; r++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[r][j] << " ";
		}
		cout << '\n';
	}
	cout << ans.first << " " << ans.second;
	return 0;
}

//https://www.acmicpc.net/problem/16927
/*풀이 : 배열을 돌릴 수 있는 그룹으로 우선 나눈다.
R이 1억이여서 그냥 네이브하게 돌리면 시간초과가 난다.
그러므로 그룹마다 따로 따로 돌리는데 돌리는 횟수 % 그룹의 사이즈 만큼
돌리면 최악의 경우에도 한 그룹당 대략 1200번 돌리므로 시간이 훨씬 줄어든다.
모든 그룹을 돌리는 경우에도.. 1800*150 해서 27만번 돌린다. 하지만 R에 따라서
이렇게 까지 꽉 채워서 돌릴 일은 없다.
한번 돌릴 때 순수 시간복잡도는 4*n이므로 3억 가까이 나오지만
4*n은 가장 외곽부분을 돌리는 경우므로 실제로는 2*n정도 될 것이다. 그렇다면 
대략 1초면 통과할 것이다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int arr[301][301];
int n, m, k;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool check(int x, int y, int group)
{
	if (x >= group && x < n - group && y >= group && y < m - group)
		return true;
	return false;
}
void rotate(int r)
{
	queue<int> q;
	int dir = 0;
	int x = r;
	int y = r;
	q.push(arr[x][y]);
	while (true)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (check(nx, ny, r))
		{
			q.push(arr[nx][ny]);
			arr[nx][ny] = q.front();
			q.pop();
			x = nx;
			y = ny;
		}
		else
		{
			dir = (dir + 1) % 4;
		}
		if (nx == r && ny == r)
			break;

	}


}
int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	int group = min(n, m) / 2;

	for (int i = 0; i < group; i++)
	{
		int num = (n - 2 * i) * 2 + (m - 2 * i) * 2 - 4;
		int hi = k % num;
		while (hi--)
		{
			rotate(i);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}


}

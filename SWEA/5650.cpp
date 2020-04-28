/*5650번 핀볼게임
풀이 : 시뮬레이션..시키는 대로 한다.
0인 곳에 4방향으로 핀볼을 굴려본다.
블록의 모양 별로 방향 바꾸는거 일일이 처리해준다.
미리 방향 별로 한 칸 굴려보고 조건 따져본다.
그렇게 하지 않으면 무한루프가 도는 상황이 온다..웜홀이나 블록에 온 경우 등등
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
int t,n;
int arr[101][101];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
vector<pii> warm[11];

int play(pii start, int dir)
{
	int sum = 0;
	int x = start.first;
	int y = start.second;
	while (true)
	{
		x += dx[dir];
		y += dy[dir];
		if (arr[x][y] == -1 || x == start.first && y == start.second)//블랙홀
		{
			return sum;
		}
		while (x >= 0 && x < n && y >= 0 && y < n && arr[x][y] == 0)
		{
			x += dx[dir];
			y += dy[dir];
			if (arr[x][y] == -1 || x == start.first && y == start.second)//블랙홀
			{
				return sum;
			}
		}
		if (x < 0 || x >= n || y < 0 || y >= n)//벽
		{
			x -= dx[dir];
			y -= dy[dir];
			dir = (dir + 2) % 4;
			sum++;
		}
		if (arr[x][y] >= 1 && arr[x][y] <= 5)//블록
		{
			if (arr[x][y] == 1 && (dir == 1 || dir == 2))
			{
				if (dir == 1)
					dir = 0;
				else if (dir == 2)
					dir = 3;
			}
			else if (arr[x][y] == 2 && (dir == 0 || dir == 1))
			{
				if (dir == 0)
					dir = 3;
				else if (dir == 1)
					dir = 2;
			}
			else if (arr[x][y] == 3 && (dir == 0 || dir == 3))
			{
				if (dir == 0)
					dir = 1;
				else if (dir == 3)
					dir = 2;
			}
			else if (arr[x][y] == 4 && (dir == 2 || dir == 3))
			{
				if (dir == 2)
					dir = 1;
				else if (dir == 3)
					dir = 0;
			}
			else
			{
				dir = (dir + 2) % 4;
			}
			sum++;

		}
		else if (arr[x][y] >= 6 && arr[x][y] <= 10)//웜홀
		{
			pii one = warm[arr[x][y]][0];
			pii two = warm[arr[x][y]][1];
			if (x == one.first && y == one.second)
			{
				x = two.first;
				y = two.second;
			}
			else
			{
				x = one.first;
				y = one.second;
			}
		}
		if (arr[x][y] == -1 || x == start.first && y == start.second)//블랙홀
		{
			return sum;
		}
	}
}

int main()
{
	freopen("t.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin >> t;
	for(int q = 1; q <= t; q++)
	{
		for (int i = 0; i < 11; i++)
		{
			warm[i].clear();
		}
		pii start;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j] >= 6 && arr[i][j] <= 10)
				{
					warm[arr[i][j]].push_back(make_pair(i, j));
				}
			}
		}
		int maxx = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (arr[i][j] == 0)
				{
					start = make_pair(i, j);
					for (int r = 0; r < 4; r++)
					{
						maxx = max(maxx, play(make_pair(start.first, start.second), r));
					}
				}
			}
		}
		cout << "#" << q << " " << maxx << '\n';
	}
	return 0;
}

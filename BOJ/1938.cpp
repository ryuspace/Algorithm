//https://www.acmicpc.net/problem/1938
/*풀이 : 통나무를 기준으로 bfs를 돌린다. visit 처리는 mid를 기준으로 가로일 때와 세로일 때로 나눠서 해줬다.
변수가 6개가 생겨 구현하기 까다로웠다.
*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int tx[8] = { -1,-1,-1,1,1,1,0,0 };
int ty[8] = { 0,1,-1,0,1,-1,1,-1 };

bool visit[2][51][51];//가로와 mid
char arr[51][51];
int n;
struct point
{
	pii left, mid, right;
};
bool garo(pii one, pii two)
{
	if (one.first == two.first)
		return true;
	return false;
}
bool check(pii mid)
{
	for (int i = 0; i < 8; i++)
	{
		int nx = tx[i] + mid.first;
		int ny = ty[i] + mid.second;
		if (nx < 0 || nx >= n || ny < 0 || ny >= n)
			return false;
		if (arr[nx][ny] == '1')
			return false;
	}
	return true;
}
point des;
bool dess = false;
queue <point> q;

int bfs()
{
	int cnt = 0;
	while (!q.empty())
	{
		int sizz = q.size();
		while (sizz--)
		{
			point front = q.front();
			q.pop();
			if ((front.mid.first == des.mid.first) &&
				(front.mid.second == des.mid.second))
			{
				if (garo(front.left, front.mid) &&dess==0)
				{
					return cnt;
				}
				else if (!garo(front.left, front.mid) && dess == 1)
				{
					return cnt;
				}
			}
			for (int i = 0; i < 4; i++)
			{
				
				int ax = dx[i] + front.left.first;
				int ay = dy[i] + front.left.second;

				int bx = dx[i] + front.mid.first;
				int by = dy[i] + front.mid.second;

				int cx = dx[i] + front.right.first;
				int cy = dy[i] + front.right.second;
			
				if (arr[ax][ay]!='1' && arr[bx][by]!='1' && arr[cx][cy]!='1'&&
					ax >= 0 && ax < n && ay >= 0 && ay < n
					&& bx >= 0 && bx < n && by >= 0 && by < n
					&& cx >= 0 && cx < n && cy >= 0 && cy < n)
				{
					if (garo({ ax,ay }, { bx,by }))
					{
						if (!visit[0][bx][by])
						{
							visit[0][bx][by] = true;
							q.push({ { ax,ay }, { bx, by }, { cx, cy } });
						}
					}
					else
					{
						if (!visit[1][bx][by])
						{
							visit[1][bx][by] = true;
							q.push({ { ax,ay }, { bx, by }, { cx, cy } });
						}
					}
				}
			}
			if (check({ front.mid.first,front.mid.second }))
			{
				if (garo(front.left, front.mid) && !visit[1][front.mid.first][front.mid.second])
				{
					visit[1][front.mid.first][front.mid.second] = true;
					q.push({ {front.mid.first-1,front.mid.second},
						{front.mid.first,front.mid.second},
						{front.mid.first+1, front.mid.second} });
				}
				else if(!garo(front.left, front.mid) && !visit[0][front.mid.first][front.mid.second])
				{
					visit[0][front.mid.first][front.mid.second] = true;
					q.push({ {front.mid.first,front.mid.second-1 },
						{front.mid.first,front.mid.second},
						{front.mid.first,front.mid.second+1} });
				}
			}
		}
		cnt++;
	}
	return 0;
}
int main()
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	point start;
	int cnt = 0;
	int cnt2 = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'B')
			{
				if (cnt == 0)
				{
					start.left = { i,j };
				}
				else if (cnt == 1)
				{
					start.mid = { i,j };
				}
				else if (cnt == 2)
				{
					start.right = { i,j };
				}
				cnt++;
			}
			else if (arr[i][j] == 'E')
			{
				if (cnt2 == 0)
				{
					des.left = { i,j };
				}
				else if (cnt2 == 1)
				{
					des.mid = { i,j };
				}
				else if (cnt2 == 2)
				{
					des.right = { i,j };
				}
				cnt2++;
			}
		}
	}
	if (garo(start.left, start.mid))
	{
		visit[0][start.mid.first][start.mid.second] = true;
	}
	else
	{
		visit[1][start.mid.first][start.mid.second] = true;
	}
	if (garo(des.left, des.mid))
		dess = 0;
	else
		dess = 1;

	q.push(start);
	cout << bfs();

	return 0;
}

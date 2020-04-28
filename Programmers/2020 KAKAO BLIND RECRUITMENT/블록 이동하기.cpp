/*풀이 : 
로봇이 가로 방향일 때 -><- 모양이라 생각하고 세로일 때는 90도로 돌린 모양이라 생각하고 bfs를 돌려 방문체크를 한다.
로봇 모양에 방향을 부여함으로써 visit 처리가 수월해진다.
회전할 때는 회전 축 기준으로 대각선 4방향을 체크한다.
*/
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
struct point
{
	int x1, y1, dir1, x2, y2, dir2;
};
int n;
int arr[101][101];
bool visit[4][101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
//-> 아래 <- 위
//0   1   2  3
bool ok(int x, int y, int dir)
{
	if (x >= 0 && x < n && y >= 0 && y < n && !visit[dir][x][y] && arr[x][y] == 0)
	{
		return true;
	}
	return false;
}
bool ok2(int x, int y)
{
	if (x >= 0 && x < n && y >= 0 && y < n && arr[x][y] == 0)
	{
		return true;
	}
	return false;
}
int bfs()
{
	//-> 아래 <- 위
	//0   1   2  3
	int cnt = 0;
	queue<point> q;
	q.push({ 0,0,0,0,1,2 });
	visit[0][0][0] = true;
	visit[2][0][1] = true;
	while (!q.empty())
	{
		int sizz = q.size();
		while (sizz--)
		{
			point front = q.front();
			q.pop();
			if ((front.x1 == n - 1 && front.y1 == n - 1) || (front.x2 == n - 1 && front.y2 == n - 1))
				return cnt;
			
			//서행
			for (int i = 0; i < 4; i++)
			{
				int x1 = dx[i] + front.x1;
				int y1 = dy[i] + front.y1;
				int x2 = dx[i] + front.x2;
				int y2 = dy[i] + front.y2;
				int dir1 = front.dir1;
				int dir2 = front.dir2;
				if (ok(x1, y1, dir1) && ok(x2, y2, dir2))
				{
					q.push({ x1,y1,dir1,x2,y2,dir2 });
					visit[dir1][x1][y1] = true;
					visit[dir2][x2][y2] = true;
				}

			}
			//-> 아래 <- 위
			//0   1   2  3

			//회전
			if (front.x1 == front.x2)//가로
			{
				int x1 = front.x1 - 1;
				int y1 = front.y1;
				int x2 = front.x2 - 1;
				int y2 = front.y2;

				if (ok2(x2, y2) && ok(x1, y1, 1) && ok(front.x1, front.y1, 3))
				{
					q.push({ x1,y1,1,front.x1,front.y1,3 });
					visit[1][x1][y1] = true;
					visit[3][front.x1][front.y1] = true;

				}

				if (ok2(x1, y1) && ok(x2, y2, 1) && ok(front.x2, front.y2, 3))
				{
					q.push({ x2,y2,1,front.x2,front.y2,3 });
					visit[1][x2][y2] = true;
					visit[3][front.x2][front.y2] = true;
				}

				/////////////////////////////////
				x1 = front.x1 + 1;
				y1 = front.y1;
				x2 = front.x2 + 1;
				y2 = front.y2;

				if (ok2(x2, y2) && ok(x1, y1, 3) && ok(front.x1, front.y1, 1))
				{
					q.push({ front.x1,front.y1,1, x1,y1,3});
					visit[3][x1][y1] = true;
					visit[1][front.x1][front.y1] = true;
				}

				if (ok2(x1, y1) && ok(x2, y2, 3) && ok(front.x2, front.y2, 1))
				{
					q.push({ front.x2,front.y2,1 ,x2,y2,3 });
					visit[3][x2][y2] = true;
					visit[1][front.x2][front.y2] = true;
				}
			}
			else
			{
				//-> 아래 <- 위
				//0   1   2  3
				int x1 = front.x1;
				int y1 = front.y1-1;
				int x2 = front.x2;
				int y2 = front.y2-1;

				if (ok2(x2, y2) && ok(x1, y1, 0) && ok(front.x1, front.y1, 2))
				{
					q.push({ x1,y1,0,front.x1,front.y1,2 });
					visit[0][x1][y1] = true;
					visit[2][front.x1][front.y1] = true;
				}

				if (ok2(x1, y1) && ok(x2, y2, 0) && ok(front.x2, front.y2, 2))
				{
					q.push({ x2,y2,0,front.x2,front.y2,2 });
					visit[0][x2][y2] = true;
					visit[2][front.x2][front.y2] = true;
				}

				/////////////////////////////////
				x1 = front.x1;
				y1 = front.y1+1;
				x2 = front.x2;
				y2 = front.y2+1;

				if (ok2(x2, y2) && ok(x1, y1, 2) && ok(front.x1, front.y1, 0))
				{
					q.push({ front.x1,front.y1,0,x1,y1,2 });
					visit[2][x1][y1] = true;
					visit[0][front.x1][front.y1] = true;
				}

				if (ok2(x1, y1) && ok(x2, y2, 2) && ok(front.x2, front.y2, 0))
				{
					q.push({ front.x2,front.y2,0 ,x2,y2,2 });
					visit[2][x2][y2] = true;
					visit[0][front.x2][front.y2] = true;
				}


			}
		}
		cnt++;
	}
}
int solution(vector<vector<int>> board) {
	int answer = 0;
	n = board.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = board[i][j];
		}
	}
	answer = bfs();
	return answer;
}

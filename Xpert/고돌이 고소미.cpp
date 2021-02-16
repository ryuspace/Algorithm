#define _CRT_SECURE_NO_WARNINGS
#define MAXN 26
#define MAXQ MAXN*MAXN*MAXN*MAXN
#include <stdio.h>
#include <math.h>
int n;
int goX, goY,goHomeX,goHomeY,soX, soY,soHomeX,soHomeY;
int arr[MAXN][MAXN];
int visit[MAXN][MAXN][MAXN][MAXN]; //고돌이 고소미 동시 방문체크

int dx[9] = { -1,-1,-1,0,1,1,1,0,0 };
int dy[9] = { -1,0,1,1,1,0,-1,-1,0 }; //제자리도 가능 ㅡㅡ

struct node
{
	int goX, goY, soX,soY,cnt;
};

node Queue[MAXQ];
int left, right;

void Push(node point)
{
	Queue[right] = point;
	right++;
	if (right >= MAXQ)
		right = 0;
}

void Pop()
{
	left++;
	if (left >= MAXQ)
		left = 0;
}

node Front()
{
	return Queue[left];
}

int Empty()
{
	if (left == right)
		return 1;
	return 0;
}

void bfs()
{
	while (!Empty())
	{

		node front = Front();
		Pop();

		if (front.goX == goHomeX && front.goY == goHomeY && front.soX == soHomeX && front.soY == soHomeY)
		{
			printf("%d", front.cnt);
			return;
		}
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{

				int gx = dx[i] + front.goX;
				int gy = dy[i] + front.goY;
				int sx = dx[j] + front.soX;
				int sy = dy[j] + front.soY;


				if (gx >= 1 && gx <= n && gy >= 1 && gy <= n && sx >= 1 && sx <= n && sy >= 1 && sy <= n && !(abs(gx - sx) <= 1 && abs(gy - sy) <= 1) && !visit[gx][gy][sx][sy] && arr[gx][gy] == 0 && arr[sx][sy] == 0) //8방향 접근 못하는건 x좌표 y좌표 각각의 절댓값의 차가 1보다 작은 경우
				{
					visit[gx][gy][sx][sy] = 1;
					Push({ gx,gy,sx,sy,front.cnt + 1 });
				}
			}
			
		}
	}
}


int main() 
{
	scanf("%d", &n);
	scanf("%d %d %d %d", &goX, &goY, &goHomeX, &goHomeY);
	scanf("%d %d %d %d",&soX, &soY, &soHomeX, &soHomeY);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	visit[goX][goY][soX][soY] = 1;
	Push({ goX,goY,soX,soY,0 });
	bfs();
	return 0;
}

//https://www.acmicpc.net/problem/17143
/*풀이 : 그냥 시뮬레이션.. 크게 어려운 건 없었다. 구조체 배열을 만들어서 속력,이동방향,크기를
조절했다.*/
#include <iostream>
#include <algorithm>

using namespace std;
struct point
{
	int s, d, z;
};
int R, C, M, r, c, s, d, z;
point arr[101][101];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
//북 동 남 서
void mov()
{
	point cop[101][101] = { 0, };
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			if (arr[i][j].z != 0)
			{
				int x = i;
				int y = j;
				int dir_x = dx[arr[i][j].d];
				int dir_y = dy[arr[i][j].d];
				for (int m = 1; m <= arr[i][j].s; m++)
				{
					if ((x + dir_x <= 0 || x + dir_x >= R + 1 || y + dir_y <= 0 || y + dir_y >= C + 1)
						)
					{

						dir_x = dx[(arr[i][j].d + 2) % 4];
						dir_y = dy[(arr[i][j].d + 2) % 4];

						arr[i][j].d = (arr[i][j].d + 2) % 4;
					}
					x += dir_x;
					y += dir_y;

				}
				if (cop[x][y].z != 0 && arr[i][j].z > cop[x][y].z
					|| cop[x][y].z == 0)
				{
					cop[x][y] = arr[i][j];

				}
				arr[i][j].s = 0;
				arr[i][j].d = 0;
				arr[i][j].z = 0;
			}
		}
	}
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			arr[i][j] = cop[i][j];
		}
	}
}

int main()
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> R >> C >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> r >> c >> s >> d >> z;
		arr[r][c].s = s;
		if (d == 2)
			arr[r][c].d = 3 - 1;
		else if (d == 3)
			arr[r][c].d = 2 - 1;
		else
			arr[r][c].d = d - 1;
		arr[r][c].z = z;
	}
	int sum = 0;
	for (int i = 1; i <= C; i++)
	{
		for (int j = 1; j <= R; j++)
		{
			if (arr[j][i].z != 0)
			{
				sum += arr[j][i].z;
				arr[j][i] = { 0,0,0 };
				break;
			}
		}
		mov();
	}
	cout << sum;
	return 0;
}

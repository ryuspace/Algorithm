//https://www.acmicpc.net/problem/17143
/*풀이 : 그냥 시뮬레이션.. 크게 어려운 건 없었다. 구조체 배열을 만들어서 속력,이동방향,크기를
조절했다.
ps : 속도 하나하나를 움직이는걸 시뮬레이션을 했더니 재채점 결과 TLE가 떴다. 
방향에 이동속도를 곱하는 방식으로 시뮬레이션을 바꿨다.
범위를 넘어가면 방향을 반대로 해준다.

*/
#include <iostream>
#include <algorithm>
using namespace std;

int R, C, M;


struct point
{
	int s, d, z;
};

point arr[101][101];
int sum;

int dx[5] = {0, -1,1,0,0 };
int dy[5] = {0, 0,0,1,-1 };

void moveShark()
{
	point tmp[101][101];
	for (int i = 1;i <=R;i++)
	{
		for (int j = 1;j <=C;j++)
		{
			tmp[i][j] = { 0,0,0 };
		}
	}//초기화
	
	for (int i = 1;i <= R;i++)
	{
		for (int j = 1;j <= C;j++)
		{
			if (arr[i][j].z > 0)
			{
				int x = i;
				int y = j;
				int dir = arr[i][j].d;
				int sok = arr[i][j].s;
				while (true)
				{
					int nx = (sok * dx[dir]) + x;
					int ny = (sok * dy[dir]) + y;

					if (nx >= 1 && nx <= R && ny >= 1 && ny <= C)
					{
						if (tmp[nx][ny].z == 0 || tmp[nx][ny].z < arr[i][j].z)
							tmp[nx][ny] = { arr[i][j].s,dir,arr[i][j].z };
						break;
					}
					if (dir == 1 && nx <= 0)
					{
						nx = 1;
						sok -= x - 1;
						dir = 2;
					}
					else if (dir == 2 && nx > R)
					{
						nx = R;
						sok -= R - x;
						dir = 1;
					}
					else if (dir == 3 && ny >C) {
						ny = C;
						sok -= C-y;
						dir = 4;
					}
					else if (dir == 4 && ny<=0)
					{
						ny = 1;
						sok -= y-1;
						dir = 3;
					}

					x = nx;
					y = ny;
				}
				
			}
		}
	}
	for (int i = 1;i <= R;i++)
	{
		for (int j = 1;j <= C;j++)
		{
			arr[i][j] = tmp[i][j];
		}
	}

}
int main()
{
	//freopen("Test.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C>>M;
	for (int i = 0;i < M;i++)
	{
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		arr[r][c] = { s,d,z };
	}


	int now = 1;
	while (now != C+1)
	{
		for (int i = 1;i <= R;i++)
		{
			if (arr[i][now].z > 0)
			{
				sum += arr[i][now].z;
				arr[i][now] = { 0,0,0 };
				break;
			}
		}
		moveShark();
		now++;
	}
	cout << sum;
	return 0;
}

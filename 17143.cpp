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
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (arr[i][j].z != 0)
			{
				int ss = arr[i][j].s;
				int x = i;
				int y = j;
				int nx = i + (dx[arr[i][j].d])* ss;
				int ny = j+ (dy[arr[i][j].d])* ss;
				int idir = arr[i][j].d;
				while (true)
				{

					if (nx >= 0 && nx < R && ny >= 0 && ny < C)
						break;
					if (idir == 3 && ny < 0) {
						ss -= y; y = 0; idir = 1; }
					else if (idir == 1 && ny >= C) { ss -= C -1- y; y = C - 1; idir = 3; }
					else if (idir == 2 && nx >= R) { ss -= R - 1-x; x = R - 1; idir = 0; }
					else if (idir == 0 && nx < 0) { ss -= x; x = 0; idir = 2; }
					nx = x +  ss*dx[idir];
					ny = y + ss * dy[idir];
				}
				if (cop[nx][ny].z != 0 && arr[i][j].z > cop[nx][ny].z
					|| cop[nx][ny].z == 0)
				{
					cop[nx][ny] = arr[i][j];
					cop[nx][ny].d=idir;

				}
				arr[i][j].s = 0;
				arr[i][j].d = 0;
				arr[i][j].z = 0;
			}
		}
	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
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
		arr[r-1][c-1].s = s;
		if (d == 2)
			arr[r-1][c-1].d = 3 - 1;
		else if (d == 3)
			arr[r-1][c-1].d = 2 - 1;
		else
			arr[r-1][c-1].d = d - 1;
		arr[r-1][c-1].z = z;
	}
	int sum = 0;
	for (int i = 0; i < C; i++)
	{
		for (int j = 0; j < R; j++)
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

//https://www.acmicpc.net/problem/5373
/*풀이 : 큐브를 고정해놓고 위,아래,왼쪽,오른쪽,앞,뒤 면에서 내가 보는 면이 1 2 3 / 4 5 6 / 7 8 9 설정한다.  반시계 방향은 시계 방향으로 3번 돌린 것과 같다.*/
#include <iostream>
#include <algorithm>

using namespace std;

char arr[6][9];
char tmp[6][9];
int rotat[9] = { 6,3,0,7,4,1,8,5,2 };
void init()
{
	for (int i = 0; i < 9; i++)
	{
		arr[0][i] = 'w';
		tmp[0][i] = 'w';
	}
	for (int i = 0; i < 9; i++)
	{
		arr[1][i] = 'y';
		tmp[1][i] = 'y';
	}
	for (int i = 0; i < 9; i++)
	{
		arr[2][i] = 'g';
		tmp[2][i] = 'g';
	}
	for (int i = 0; i < 9; i++)
	{
		arr[3][i] = 'b';
		tmp[3][i] = 'b';
	}
	for (int i = 0; i < 9; i++)
	{
		arr[4][i] = 'r';
		tmp[4][i] = 'r';
	}
	for (int i = 0; i < 9; i++)
	{
		arr[5][i] = 'o';
		tmp[5][i] = 'o';
	}
}
void fun(char al, char bu)
{
	if (al == 'U')
	{
		for (int i = 0; i < 9; i++)
		{
			arr[0][i] = tmp[0][rotat[i]];
		}
		arr[4][0] = tmp[3][0];
		arr[4][1] = tmp[3][1];
		arr[4][2] = tmp[3][2];

		arr[2][0] = tmp[4][0];
		arr[2][1] = tmp[4][1];
		arr[2][2] = tmp[4][2];

		arr[5][0] = tmp[2][0];
		arr[5][1] = tmp[2][1];
		arr[5][2] = tmp[2][2];

		arr[3][0] = tmp[5][0];
		arr[3][1] = tmp[5][1];
		arr[3][2] = tmp[5][2];
	}
	else if (al == 'D')
	{
		for (int i = 0; i < 9; i++)
		{
			arr[1][i] = tmp[1][rotat[i]];
		}
		arr[3][6] = tmp[4][6];
		arr[3][7] = tmp[4][7];
		arr[3][8] = tmp[4][8];

		arr[4][6] = tmp[2][6];
		arr[4][7] = tmp[2][7];
		arr[4][8] = tmp[2][8];


		arr[2][6] = tmp[5][6];
		arr[2][7] = tmp[5][7];
		arr[2][8] = tmp[5][8];

		arr[5][6] = tmp[3][6];
		arr[5][7] = tmp[3][7];
		arr[5][8] = tmp[3][8];


	}
	else if (al == 'F')
	{
		for (int i = 0; i < 9; i++)
		{
			arr[4][i] = tmp[4][rotat[i]];
		}

		arr[3][0] = tmp[0][6];
		arr[3][3] = tmp[0][7];
		arr[3][6] = tmp[0][8];

		arr[0][6] = tmp[2][8];
		arr[0][7] = tmp[2][5];
		arr[0][8] = tmp[2][2];

		arr[2][8] = tmp[1][6];
		arr[2][5] = tmp[1][7];
		arr[2][2] = tmp[1][8];

		arr[1][6] = tmp[3][0];
		arr[1][7] = tmp[3][3];
		arr[1][8] = tmp[3][6];

	}
	else if (al == 'B')
	{
		for (int i = 0; i < 9; i++)
		{
			arr[5][i] = tmp[5][rotat[i]];
		}

		arr[0][0] = tmp[3][2];
		arr[0][1] = tmp[3][5];
		arr[0][2] = tmp[3][8];

		arr[3][2] = tmp[1][0];
		arr[3][5] = tmp[1][1];
		arr[3][8] = tmp[1][2];

		arr[1][0] = tmp[2][6];
		arr[1][1] = tmp[2][3];
		arr[1][2] = tmp[2][0];

		arr[2][6] = tmp[0][0];
		arr[2][3] = tmp[0][1];
		arr[2][0] = tmp[0][2];
	}
	else if (al == 'L')
	{
		for (int i = 0; i < 9; i++)
		{
			arr[2][i] = tmp[2][rotat[i]];
		}

		arr[0][0] = tmp[5][8];
		arr[0][3] = tmp[5][5];
		arr[0][6] = tmp[5][2];

		arr[5][2] = tmp[1][2];
		arr[5][5] = tmp[1][5];
		arr[5][8] = tmp[1][8];

		arr[1][2] = tmp[4][6];
		arr[1][5] = tmp[4][3];
		arr[1][8] = tmp[4][0];

		arr[4][6] = tmp[0][6];
		arr[4][3] = tmp[0][3];
		arr[4][0] = tmp[0][0];

	}
	else if (al == 'R')
	{
		for (int i = 0; i < 9; i++)
		{
			arr[3][i] = tmp[3][rotat[i]];
		}

		arr[0][8] = tmp[4][8];
		arr[0][5] = tmp[4][5];
		arr[0][2] = tmp[4][2];

		arr[4][8] = tmp[1][0];
		arr[4][5] = tmp[1][3];
		arr[4][2] = tmp[1][6];

		arr[1][0] = tmp[5][0];
		arr[1][3] = tmp[5][3];
		arr[1][6] = tmp[5][6];

		arr[5][0] = tmp[0][8];
		arr[5][3] = tmp[0][5];
		arr[5][6] = tmp[0][2];
	}
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		init();
		int rot;
		cin >> rot;
		for (int j = 0; j < rot; j++)
		{
			char al, bu;
			cin >> al >> bu;
			if (bu == '+')
			{
				fun(al, bu);
				for (int k = 0; k< 6; k++)
				{
					for (int r = 0; r < 9; r++)
					{
						tmp[k][r] = arr[k][r];
					}
				}
			}
			else
			{
				fun(al, bu);
				for (int k = 0; k< 6; k++)
				{
					for (int r = 0; r < 9; r++)
					{
						tmp[k][r] = arr[k][r];
					}
				}
				fun(al, bu);
				for (int k = 0; k< 6; k++)
				{
					for (int r = 0; r < 9; r++)
					{
						tmp[k][r] = arr[k][r];
					}
				}
				fun(al, bu);
				for (int k = 0; k< 6; k++)
				{
					for (int r = 0; r < 9; r++)
					{
						tmp[k][r] = arr[k][r];
					}
				}
			}
		}
		for (int r = 0; r < 9; r++)
		{
			cout << arr[0][r];
			if ((r + 1) % 3 == 0)
				cout << '\n';
		}
	}

	return 0;
}


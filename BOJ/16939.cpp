//https://www.acmicpc.net/problem/16939
/*풀이 : 큐빙이랑 비슷한 문제였다 구현하기 고통스러웠다.
다행히 큐브 돌리는데서는 문제가 없었지만 체크하는데서 문제가 있었다.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int tmp[7][5];
int tmp2[7][5];

void left(int idx)
{
	int arr[7][5];
	for (int i = 1; i <= 6; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			arr[i][j] = tmp[i][j];
		}
	}

	if (idx == 1)
	{
		for (int i = 1; i <= 2; i++)
		{
			tmp[4][i] = arr[2][i];
		}
		for (int i = 1; i <= 2; i++)
		{
			tmp[6][i] = arr[4][i];
		}
		for (int i = 1; i <= 2; i++)
		{
			tmp[5][i] = arr[6][i];
		}
		for (int i = 1; i <= 2; i++)
		{
			tmp[2][i] = arr[5][i];
		}
		tmp[1][1] = arr[1][2];
		tmp[1][2] = arr[1][4];
		tmp[1][3] = arr[1][1];
		tmp[1][4] = arr[1][3];
	}
	else
	{
		for (int i = 3; i <= 4; i++)
		{
			tmp[4][i] = arr[2][i];
		}
		for (int i = 3; i <= 4; i++)
		{
			tmp[6][i] = arr[4][i];
		}
		for (int i = 3; i <= 4; i++)
		{
			tmp[5][i] = arr[6][i];
		}
		for (int i = 3; i <= 4; i++)
		{
			tmp[2][i] = arr[5][i];
		}
		tmp[3][1] = arr[3][3];
		tmp[3][2] = arr[3][1];
		tmp[3][3] = arr[3][4];
		tmp[3][4] = arr[3][2];
	}

	

	
}


void up(int idx)
{
	int arr[7][5];
	for (int i = 1; i <= 6; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			arr[i][j] = tmp[i][j];
		}
	}

	if (idx == 1)
	{
		tmp[1][1] = arr[2][1];
		tmp[1][3] = arr[2][3];


		tmp[2][1] = arr[3][1];
		tmp[2][3] = arr[3][3];

		tmp[3][1] = arr[6][4];
		tmp[3][3] = arr[6][2];

		tmp[6][4] = arr[1][1];
		tmp[6][2] = arr[1][3];

		tmp[4][1] = arr[4][2];
		tmp[4][2] = arr[4][4];
		tmp[4][3] = arr[4][1];
		tmp[4][4] = arr[4][3];



	}
	else
	{
		tmp[1][2] = arr[2][2];
		tmp[1][4] = arr[2][4];

		tmp[2][2] = arr[3][2];
		tmp[2][4] = arr[3][4];

		tmp[3][2] = arr[6][3];
		tmp[3][4] = arr[6][1];

		tmp[6][3] = arr[1][2];
		tmp[6][1] = arr[1][4];

		tmp[5][1] = arr[5][3];
		tmp[5][2] = arr[5][1];
		tmp[5][3] = arr[5][4];
		tmp[5][4] = arr[5][2];
	}

}


void twist(int idx)//왼쪽으로 돎
{
	int arr[7][5];
	for (int i = 1; i <= 6; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			arr[i][j] = tmp[i][j];
		}
	}
	if (idx == 1)
	{
		tmp[4][4] = arr[1][3];
		tmp[4][2] = arr[1][4];

		tmp[3][2] = arr[4][4];
		tmp[3][1] = arr[4][2];

		tmp[5][1] = arr[3][2];
		tmp[5][3] = arr[3][1];

		tmp[1][3] = arr[5][1];
		tmp[1][4] = arr[5][3];


		tmp[2][1] = arr[2][2];
		tmp[2][2] = arr[2][4];
		tmp[2][3] = arr[2][1];
		tmp[2][4] = arr[2][3];
	}
	else
	{
		tmp[5][4] = arr[1][2];
		tmp[5][2] = arr[1][1];

		tmp[3][3] = arr[5][4];
		tmp[3][4] = arr[5][2];

		tmp[2][1] = arr[3][3];
		tmp[2][3] = arr[3][4];

		tmp[1][2] = arr[2][1];
		tmp[1][1] = arr[2][3];

		tmp[6][1] = arr[6][2];
		tmp[6][2] = arr[6][4];
		tmp[6][3] = arr[6][1];
		tmp[6][4] = arr[6][3];
	}

	
}
void reset()
{
	for (int i = 1; i <= 6; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			tmp[i][j] = tmp2[i][j];
		}
	}

}
bool check()
{
	for (int i = 1; i <= 6; i++)
	{
		int col = tmp[i][1];
		for (int j = 1; j <= 4; j++)
		{
			if (tmp[i][j] != col)
				return false;
		}
	}
	return true;
}
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 1; i <= 6; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			cin >> tmp[i][j];
			tmp2[i][j] = tmp[i][j];
		}
	}
	bool f = false;

	left(1);

	f |= check();
	reset();

	left(1);
	left(1);
	left(1);

	f |= check();
	reset();

	left(2);

	f |= check();
	reset();

	left(2);
	left(2);
	left(2);

	f |= check();
	reset();


	up(1);
	f |= check();
	reset();
	up(1);
	up(1);
	up(1);
	f |= check();
	reset();

	up(2);
	f |= check();
	reset();
	up(2);
	up(2);
	up(2);
	f |= check();
	reset();

	twist(1);
	f |= check();
	reset();
	twist(1);
	twist(1);
	twist(1);
	f |= check();
	reset();

	twist(2);
	f |= check();
	reset();
	twist(2);
	twist(2);
	twist(2);
	f |= check();
	reset();

	cout << f;
	return 0;

}

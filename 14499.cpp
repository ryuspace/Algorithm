//https://www.acmicpc.net/problem/14499
/*풀이 : 시뮬레이션.주사위의 위치를 숫자로 담아서 동서남북 방향으로 움직였을 때
위치의 숫자를 바꿔준다.*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;
int dice[7];
int arr[21][21];
pii start;
int n, m, x, y, k;
void fun(int a)
{
	int tmp[7];
	for (int i = 1; i <= 6; i++)
	{
		tmp[i] = dice[i];
	}
	if (a == 1)//동
	{
		if (start.second + 1 >= m)
		{
			return;
		}
		start.second += 1;
		dice[1] = tmp[4];
		dice[2] = tmp[2];
		dice[3] = tmp[1];
		dice[4] = tmp[6];
		dice[5] = tmp[5];
		dice[6] = tmp[3];
		if (arr[start.first][start.second] == 0)
		{
			arr[start.first][start.second] = dice[6];
		}
		else
		{
			dice[6] = arr[start.first][start.second];
			arr[start.first][start.second] = 0;
		}
	}
	else if (a == 2)//서
	{
		if (start.second - 1 < 0)
		{
			return;
		}
		start.second -= 1;
		dice[1] = tmp[3];
		dice[2] = tmp[2];
		dice[3] = tmp[6];
		dice[4] = tmp[1];
		dice[5] = tmp[5];
		dice[6] = tmp[4];
		if (arr[start.first][start.second] == 0)
		{
			arr[start.first][start.second] = dice[6];
		}
		else
		{
			dice[6] = arr[start.first][start.second];
			arr[start.first][start.second] = 0;
		}
	}
	else if (a == 3)//북
	{
		if (start.first - 1<0)
		{
			return;
		}
		start.first -= 1;
		dice[1] = tmp[5];
		dice[2] = tmp[1];
		dice[3] = tmp[3];
		dice[4] = tmp[4];
		dice[5] = tmp[6];
		dice[6] = tmp[2];
		if (arr[start.first][start.second] == 0)
		{
			arr[start.first][start.second] = dice[6];
		}
		else
		{
			dice[6] = arr[start.first][start.second];
			arr[start.first][start.second] = 0;
		}
	}
	else if (a == 4)//남
	{
		if (start.first + 1 >= n)
		{
			return;
		}
		start.first += 1;
		dice[1] = tmp[2];
		dice[2] = tmp[6];
		dice[3] = tmp[3];
		dice[4] = tmp[4];
		dice[5] = tmp[1];
		dice[6] = tmp[5];
		if (arr[start.first][start.second] == 0)
		{
			arr[start.first][start.second] = dice[6];
		}
		else
		{
			dice[6] = arr[start.first][start.second];
			arr[start.first][start.second] = 0;
		}
	}

	cout << dice[1] << '\n';
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int a;
			cin >> a;
			arr[i][j] = a;
		}
	}
	start = { x,y };
	for (int i = 0; i < k; i++)
	{
		int a;
		cin >> a;
		fun(a);
	}
	return 0;
}

//https://www.acmicpc.net/problem/15662
/*풀이 : 돌릴 톱니바퀴 기준으로 좌우로 같이 돌아가는 구간을 체크한다.*/
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>;
using namespace std;

int top[1001][9];
int tmp[1001][9];
int dirr[1001];
int t, k;

void init()
{
	for (int i = 1; i <= t; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			tmp[i][j] = top[i][j];
		}
	}
}
void clock(int num,int dir)
{
	if (dir == 1)
	{
		for (int i = 0; i < 8; i++)
		{
			top[num][(i + 1)%8] = tmp[num][i];
		}
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			top[num][i] = tmp[num][(i + 1) % 8];
		}
	}
}

void fun(int a, int b)
{
	memset(dirr, 0, sizeof(dirr));
	dirr[a] = b;
	int x = t; 
	int y = 1;
	for (int i = a; i < t; i++)
	{
		if (top[i][2] != top[i + 1][6])
		{
			dirr[i + 1] = -dirr[i];//이전 톱니바퀴의 반대방향으로 돌아간다.
		}
		else
		{
			x = i;
			break;
		}
	}
	for (int i = a; i > 1; i--)
	{
		if (top[i][6] != top[i - 1][2])
		{
			dirr[i - 1] = -dirr[i];
		}
		else
		{
			y = i;
			break;
		}
	}

	for (int i = y; i <=x; i++)
	{
		clock(i, dirr[i]);
	}
}
int main() {

	ios_base::sync_with_stdio(0);
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		string tmpp;
		cin >> tmpp;
		for (int j = 0; j < 8; j++)
		{
			top[i][j] = tmpp[j] - '0';
		}
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		init();
		int a, b;
		cin >> a >> b;
		fun(a, b);
	}
	int cnt = 0;
	for (int i = 1; i <= t; i++)
	{
		if (top[i][0])
			cnt++;
	}
	cout << cnt;
	return 0;
}

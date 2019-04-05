//https://www.acmicpc.net/problem/16918
/*풀이 : 짝수 시간대에는 무조건 전부 폭탄이다. 홀수 시간대에는
n번째 시간의 폭탄들의 상하좌우도 폭탄으로 맞춰주고 .과 'O'의 위치를 반전시켜주면
n+2번째 시간의 맵 모양이다. 이를 반복.*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int r, c, n;
int arr[201][201];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void bfs()
{
	int cnt = 1;
	while (cnt != n)
	{
		queue<pii> q;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (arr[i][j] == 0)
					q.push({ i,j });
			}
		}

		while (!q.empty())
		{
			pii front = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = dx[i] + front.first;
				int ny = dy[i] + front.second;
				if (nx >= 0 && nx < r &&ny >= 0 && ny < c)
				{
					arr[nx][ny] = 0;
				}
			}
		}

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				arr[i][j] = 1 - arr[i][j];
			}
		}
		cnt += 2;
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (arr[i][j] == 0)
			{
				cout << 'O';
			}
			else
				cout << '.';
		}
		cout << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> r >> c >> n;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			char numm;
			cin >> numm;
			if (numm == 'O')
			{
				arr[i][j] = 0;
			}
			else if (numm == '.')
			{
				arr[i][j] = 1;
			}
		}
	}

	if (n % 2 == 1)
		bfs();
	else
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cout << 'O';
			}
			cout << '\n';
		}
	}
	return 0;
}

/*4615번 재미있는 오셀로 게임
풀이 : 간단한 시뮬레이션.
내 돌과 내 돌 사이에 상대편 돌'만' 있으면 그 돌을 모두 내 돌로 바꿔준다.
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int t,n,m;
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };
int arr[9][9];
//흑1 백2
void check(int x, int y,int num)
{
	int w = 0, b = 0;
	for (int i = 0; i < 8; i++)
	{
		int nx = dx[i] + x;
		int ny = dy[i] + y;

		while(nx >= 0 && nx < n && ny >= 0 && ny < n&&arr[nx][ny]!=num &&arr[nx][ny]!=0)
		{
			if (num == 1 && arr[nx][ny]==2)
			{
				w++;
			}
			else if (num == 2 && arr[nx][ny] == 1)
			{
				b++;
			}

			nx += dx[i];
			ny += dy[i];
		}
		bool flag = false;
		if (nx >= 0 && nx < n && ny >= 0 && ny < n && arr[nx][ny] == num && arr[nx][ny] != 0)
		{
			if (num == 1 && w >= 1 || num==2 && b>=1)
			{
				flag = true;
			}
		}
		if (flag)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			while (nx >= 0 && nx < n && ny >= 0 && ny < n && arr[nx][ny] != num)
			{
				if (num == 1 && arr[nx][ny] == 2)
				{
					arr[nx][ny] = 1;
				}
				else if (num == 2 && arr[nx][ny] == 1)
				{
					arr[nx][ny] = 2;
				}
				nx += dx[i];
				ny += dy[i];
			}
		}
		
	}
}
int main()
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	for (int r = 1; r <= t; r++)
	{
		memset(arr, 0, sizeof(arr));
		cin >> n >> m;
		arr[n / 2 - 1][n / 2 - 1] = 2;
		arr[n / 2 - 1][n / 2] = 1;
		arr[n / 2][n / 2 - 1] = 1;
		arr[n / 2][n / 2] = 2;
		for (int i = 0; i < m; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			arr[a-1][b-1] = c;
			check(a-1, b-1,c);

		}
		int b = 0, w = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (arr[i][j] == 1)
					b++;
				else if (arr[i][j] == 2)
					w++;
			}
		}
		cout << "#" << r << " " << b << " " << w << '\n';
	}

	return 0;
}

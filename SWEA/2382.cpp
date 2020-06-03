/*2382번 미생물 격리
풀이 : 시뮬레이션..어떤 한 공간에 여러 미생물이 몰릴 때
그 몰리는 미생물 중 군집이 큰 애의 방향으로 선택되는거 주의!
위치가 다들 다르므로 같은 위치의 약품처리에 있는 애들끼리 겹칠 일은 없다.
그 외 까다로운 부분은 없었다.
*/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int t;
int n, m, k;

struct point
{
	int su, dir;
};
point arr[101][101];
int maxi[101][101];
point tmp[101][101];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
//상 우 하 좌
int main()
{
	freopen("Test.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	for (int q = 1;q <= t;q++)
	{

		int sum = 0;
		cin >> n >> m >> k;
		for (int i = 0;i < k;i++)
		{
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			if (d== 1)
			{
				d = 0;
			}
			else if (d == 4)
			{
				d = 1;
			}
			arr[a][b] = { c,d };
		}
		for(int hi=1;hi<=m;hi++)
		{
			memset(maxi, 0, sizeof(maxi));
			for (int i = 0;i < n;i++)
			{
				for (int j = 0;j < n;j++)
				{
					tmp[i][j] = { 0,0 };
				}
			}
			for (int i = 0;i < n;i++)
			{
				for (int j = 0;j < n;j++)
				{
					if (arr[i][j].su > 0)
					{
						int nx = dx[arr[i][j].dir] + i;
						int ny = dy[arr[i][j].dir]+ j;
						if (nx == 0 || nx == n - 1 || ny == 0 || ny == n - 1)
						{
							arr[i][j].dir = (arr[i][j].dir + 2) % 4;
							arr[i][j].su /= 2;
						}
						if (tmp[nx][ny].su > 0)
						{
							if (maxi[nx][ny] < arr[i][j].su)
							{
								maxi[nx][ny] = arr[i][j].su;
								tmp[nx][ny].dir = arr[i][j].dir;
								tmp[nx][ny].su += arr[i][j].su;
							}
							else
							{
								tmp[nx][ny].su += arr[i][j].su;
							}
						}
						else
						{
							tmp[nx][ny].dir = arr[i][j].dir;
							tmp[nx][ny].su += arr[i][j].su;
							maxi[nx][ny] = arr[i][j].su;
						}
						arr[i][j] = { 0,0 };
					}
				}
			}
			for (int i = 0;i < n;i++)
			{
				for (int j = 0;j < n;j++)
				{
					arr[i][j] = tmp[i][j];
				}
			}
		}
		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < n;j++)
			{
				if (arr[i][j].su > 0)
				{
					sum += arr[i][j].su;
				}
			}
		}
		cout << "#" << q << " " << sum << '\n';
		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < n;j++)
			{
				arr[i][j] = tmp[i][j] = { 0,0 };
			}
		}
	}

	return 0;
}

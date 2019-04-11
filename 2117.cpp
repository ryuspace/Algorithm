/*2117번 홈 방범 서비스
풀이 : 서비스를 제공받을 위치를 선택하고 현재 위치에서 집의 거리를
측정해 그 거리만큼 집이 몇 개가 있는지 파악하고 손익을 따져본다.
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef pair<int, int> pii;
int t, n, m;
int arr[21][21];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int myon[41];
int gap[41];
int main()
{
	freopen("t.txt", "r", stdin);
	ios_base::sync_with_stdio(0);

	for (int i = 1; i <= 40; i++)
	{
		myon[i] = i * i + (i - 1)*(i - 1);
	}
	cin >> t;
	for (int z = 1; z <= t; z++)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
			}

		int maxx = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				memset(gap, 0, sizeof(gap));
				//i,j가 고정위치
				for (int k = 0; k < n; k++)
				{
					for (int r = 0; r < n; r++)
					{

						if (arr[k][r] == 1)
						{
							gap[abs(i - k) + abs(j - r) + 1] += m;
						}

					}
				}
				for (int k = 1; k <= n * 2; k++)
				{

					gap[k] += gap[k - 1];
					//cout << gap[k] << " ";
					if (gap[k] - myon[k] >= 0)
						maxx = max(maxx, gap[k] / m);
				}
			}
		}
		cout << "#" << z << " " << maxx << '\n';
	}
	return 0;
}

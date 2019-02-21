//https://www.acmicpc.net/problem/11978
/*맵에 방문한 시간을 적어둔다. 
만약 이미 방문된 경우 현재 시간에 전에 방문한 시간을 빼준 값과 min값을 비교한다. min은  현재 시간에 전에 방문한 시간을 빼준 값의 최소 */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int arr[4004][4004];

int main()
{
	int n;
	cin >> n;
	char tmp;
	int dir;
	int now = 0;
	int x = 1000;
	int y = 1000;
	int Min = 1e9;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp >> dir;

		if (tmp == 'N')
		{
			for (int j = 1; j <= dir; j++)
			{
				now++;
				x--;
				if (arr[x][y] != 0)
				{
					Min = min(Min, now - arr[x][y]);
				}
				arr[x][y] = now;

			}
		}
		else if (tmp == 'E')
		{
			for (int j = 1; j <= dir; j++)
			{
				now++;
				y++;
				if (arr[x][y] != 0)
				{

					Min = min(Min, now - arr[x][y]);
				}
				arr[x][y] = now;
			}
		}
		else if (tmp == 'S')
		{
			for (int j = 1; j <= dir; j++)
			{
				now++;
				x++;
				if (arr[x][y] != 0)
				{

					Min = min(Min, now - arr[x][y]);
				}
				arr[x][y] = now;
			}
		}
		else
		{
			for (int j = 1; j <= dir; j++)
			{
				now++;
				y--;
				if (arr[x][y] != 0)
				{
					Min = min(Min, now - arr[x][y]);
				}
				arr[x][y] = now;

			}
		}

	}
	if (Min == 1e9)
	{
		cout << -1;
	}
	else
	{
		cout << Min;
	}
	return 0;
}

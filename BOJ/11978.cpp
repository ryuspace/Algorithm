//https://www.acmicpc.net/problem/11978
/*맵에 방문한 시간을 적어둔다. 
만약 이미 방문된 경우 현재 시간에 전에 방문한 시간을 빼준 값과 min값을 비교한다. min은  현재 시간에 전에 방문한 시간을 빼준 값의 최소 */
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int arr[4004][4004];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int x = 1000, y = 1000, time = 0;
	int minn = 1e9;
	char dir;
	int num;

	cin >> n;
	for (int i = 0; i < 4004; i++)
	{
		for (int j = 0; j < 4004; j++)
		{
			arr[i][j] = 1e9;
		}
	}

	arr[x][y] = 0;
	//cout << x << " " << y << " " << arr[x][y] << '\n';
	for (int i = 0; i < n; i++)
	{
		//cout << x << " " << y << " " << arr[x][y] << '\n';
		cin >> dir >> num;
		if (dir == 'N')
		{
			for (int j = 0; j < num; j++)
			{

				x--;
				time++;
				//cout << x << " " << y << " " << arr[x][y] << '\n';
				if (arr[x][y] != 1e9)
				{
					minn = min(minn, time - arr[x][y]);
				}
				arr[x][y] = time;
			}
		}
		else if (dir == 'E')
		{
			for (int j = 0; j < num; j++)
			{
				y++;
				time++;
				if (arr[x][y] != 1e9)
				{
					minn = min(minn, time - arr[x][y]);

				}
				arr[x][y] = time;
			}
		}
		else if (dir == 'S')
		{
			for (int j = 0; j < num; j++)
			{
				x++;
				time++;
				//cout << x << " " << y << " " << arr[x][y] << '\n';
				if (arr[x][y] != 1e9)
				{

					minn = min(minn, time - arr[x][y]);
				}
				arr[x][y] = time;
			}
		}
		else
		{
			for (int j = 0; j < num; j++)
			{
				y--;
				time++;
				if (arr[x][y] != 1e9)
				{
					minn = min(minn, time - arr[x][y]);
				}
				arr[x][y] = time;
			}
		}
	}
	if (minn == 1e9)
		cout << -1;
	else
		cout << minn;

	
	return 0;
}

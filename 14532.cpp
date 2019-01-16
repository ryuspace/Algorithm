//https://www.acmicpc.net/problem/14532
/*풀이 : 누군가를 가린 숫자들을 제외한 모든 숫자가 후보가 될 수 있다.*/
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int arr[11][11];

vector<int> v;

bool visit[10];
bool cover[10];
int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 1; j <= n; j++)
		{
			arr[i][j] = tmp[j - 1] - '0';
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (!visit[arr[i][j]] && arr[i][j] != 0)
			{
				visit[arr[i][j]] = true;
				int Max_x = 0, Max_y = 0;
				int Min_x = 1e9, Min_y = 1e9;
				int x, y;
				for (int r = 1; r <= n; r++)
				{
					for (int k = 1; k <= n; k++)
					{
						if (arr[r][k] == arr[i][j])
						{
							x = r;
							Max_x = max(Max_x, x);
							Min_x = min(Min_x, x);
							y = k;
							Max_y = max(Max_y, y);
							Min_y = min(Min_y, y);

						}
					}
				}

				for (int r = Min_x; r <= Max_x; r++)
				{
					for (int k = Min_y; k <= Max_y; k++)
					{
						if (arr[r][k] != arr[i][j])
						{
							cover[arr[r][k]]=true;
						}
					}
				}
			}

		}
	}
	int cnt = 0;
	for (int i = 0; i <= 9; i++)
	{
		if (cover[i] == false && visit[i] == true)
		{
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}

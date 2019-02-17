//https://www.acmicpc.net/problem/14927
/*풀이 : 가장 위에 라인에 전구를 껐는지 켰는지 모든 상태에 대해 나머지 상태를 체크한다.
나를 기준으로 위에가 켜져있으면 나를 눌러서 꺼야한다.*/
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

int arr[20][20];
int arr2[20][20];//원본유지
bool check[20];
int dx[5] = {0,-1,1,0,0 };
int dy[5] = {0,0,0,-1,1};
int n;

int start2()
{
	int cnt = 0;

	for (int j = 0; j < n; j++)
	{
		if (check[j] == true)
		{
			for (int i = 0; i < 5; i++)
			{
				int nx = 0 + dx[i];
				int ny = j + dy[i];
				arr[nx][ny] = 1 - arr[nx][ny];
	
			}
			cnt++;
		}
	}


	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i - 1][j] == 1)
			{
				for (int n = 0; n < 5; n++)
				{
					arr[i + dx[n]][j + dy[n]] = 1 - arr[i + dx[n]][j + dy[n]];
				}
				cnt++;
			}
		}
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 1)
			{
				return 999999999;
			}
		}
	}
	return cnt;
}

int Min = 999999999;

void start(int cnt)
{

	if (cnt == n)
	{
		int tmp = start2();
		Min = min(tmp, Min);
		memcpy(arr, arr2, sizeof(arr));
		return;
	}
	check[cnt] = false;
	start(cnt + 1);
	check[cnt] = true;
	start(cnt + 1);
}

int main() {

	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			arr2[i][j] = arr[i][j];
		}
	}
	start(0);
	if (Min == 999999999)
	{
		cout << -1;
	}
	else
	{
		cout << Min;
	}
	return 0;
}

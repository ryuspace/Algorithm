//https://www.acmicpc.net/problem/1018
/*풀이 : 가능한 nxm의 체스판의 종류 2가지를 미리 만들어 놓는다. 그리고 입력 받은 map에서 
다른 부분을 표시해놓고 8칸씩 다른부분을 찾는다.*/
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

char arr[51][51];

char map1[51][51];
char map2[51][51];

int cnt1[51][51];
int cnt2[51][51];

int main() {

	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int n, m;
	cin >> n >> m;
	


	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < tmp.length(); j++)
		{
			arr[i][j] = tmp[j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if ((i + j) % 2 == 0)
			{
				map1[i][j] = 'B';
				if (map1[i][j] != arr[i][j])
				{
					cnt1[i][j] = 1;
				}
			}
			else
			{
				map1[i][j] = 'W';
				if (map1[i][j] != arr[i][j])
				{
					cnt1[i][j] = 1;
				}
			}

		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if ((i + j) % 2 == 0)
			{
				map2[i][j] = 'W';
				if (map2[i][j] != arr[i][j])
				{
					cnt2[i][j] = 1;
				}
			}
			else
			{
				map2[i][j] = 'B';
				if (map2[i][j] != arr[i][j])
				{
					cnt2[i][j] = 1;
				}
			}
		}
	}

	//첫번째 체스판 부터

	int Max1 = 3000;
	for (int i = 0; i <= n-8; i++)
	{
		for (int j = 0; j <= m-8; j++)
		{
			int cntt1 = 0;
			for (int n = i; n < 8 + i; n++)
			{
				for (int m = j; m < 8 + j; m++)
				{
					cntt1 += cnt1[n][m];
				}
			}
			Max1 = min(Max1, cntt1);
		}

	}

	int Max2 = 3000;
	for (int i = 0; i <= n - 8; i++)
	{
		for (int j = 0; j <= m - 8; j++)
		{
			int cntt2 = 0;
			for (int n = i; n < 8 + i; n++)
			{
				for (int m = j; m < 8 + j; m++)
				{
					cntt2 += cnt2[n][m];
				}
			}
			Max2 = min(Max2, cntt2);
		}

	}

	cout << min(Max1, Max2);
	return 0;
}

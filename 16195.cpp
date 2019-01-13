//https://www.acmicpc.net/problem/16195
/*풀이 : 이전 위치에서 내가 넣은 값이 들어가기 전의 상태가 현재 상태..*/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

long long int memo[1001][1001];

int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int t, n, m;

	long long int cnt = 0;
	memo[1][1] = 1;
	memo[2][1] = 1;
	memo[2][2] = 1;
	memo[3][1] = 1;
	memo[3][2] = 2;
	memo[3][3] = 1;
	for (int i = 4; i <= 1000; i++)
	{
		for (int j = 1; j <= 1000; j++)
		{
			if (i - 1 > 0)
			{
				memo[i][j] = (memo[i][j] + memo[i - 1][j - 1]) % 1000000009;
			}
			if (i - 2 > 0)
			{
				memo[i][j] = (memo[i][j] + memo[i - 2][j - 1]) % 1000000009;
			}
			if (i - 3 > 0)
			{
				memo[i][j] = (memo[i][j] + memo[i - 3][j - 1]) % 1000000009;
			}
		}
	}
	for (int i = 1; i <= 1000; i++)
	{
		for (int j = 2; j <= 1000; j++)
		{
			memo[i][j] = (memo[i][j] + memo[i][j - 1]) % 1000000009;
		}
	}
	cin >> t;
	while (t--)
	{
		long long int sum = 0;
		cin >> n >> m;
		cout << memo[n][m] << '\n';
	}
	return 0;
}

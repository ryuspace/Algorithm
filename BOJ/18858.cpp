//https://www.acmicpc.net/problem/18858
/*풀이 : dp[i][j][r] : i까지 왔는데 현재 j다. 전전 상태는 0,1,2로 표시 가능.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <string>

using namespace std;
#define MOD 998244353
long long int dp[1001][101][3];//전 현재 전전->전 상태 0이면 오름 1이면 평지 2면 내림
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int j = 1; j <= m; j++)
	{
		for (int r = 0; r <= 2; r++)
		{
			dp[1][j][1] = 1;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int r = j+1; r <=m; r++)
			{
				dp[i][j][2] = dp[i][j][2]%MOD+ dp[i - 1][r][1]%MOD + dp[i - 1][r][2]%MOD;
			}
			dp[i][j][1]= dp[i][j][1]%MOD +dp[i - 1][j][0]%MOD + dp[i - 1][j][1]%MOD+ dp[i - 1][j][2]%MOD;

			for (int r = 1; r <j; r++)
			{
				dp[i][j][0] = dp[i][j][0]%MOD + dp[i - 1][r][0]%MOD  + dp[i - 1][r][1]%MOD + dp[i - 1][r][2]%MOD;
			}
			
		}
	}

	long long int sum = 0;
	for (int j = 1; j <= m; j++)
	{
		sum =sum%MOD+ dp[n][j][0]%MOD+ dp[n][j][1]%MOD+ dp[n][j][2]%MOD;
	}
	cout << sum%MOD;
	return 0;
}

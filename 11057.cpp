//https://www.acmicpc.net/problem/11057
/*풀이 : 현재 숫자가 n이면 이전 순서의 0~n-1까지의 경우를 모두 더해준다.*/
#include <iostream>
#include <algorithm>

using namespace std;

long long int dp[1001][11];
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i <= 9; i++)
	{
		dp[1][i] = i+1;
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			for (int r = 0; r <= j; r++)
			{
				dp[i][j] = (dp[i][j]+dp[i - 1][r])%10007;
			}
		}
	}
	cout << dp[n][9]%10007;
	return 0;
}

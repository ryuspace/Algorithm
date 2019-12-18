//https://www.acmicpc.net/problem/2225
/*풀이 : 계차수열을 이용해 n^2만에 풀 수도 있지만 그 방법은 생각해내지 못했다.
dp[i][j] : j개의 숫자로 i를 만듦로 선언해서 j-1개의 숫자로 i-ㅁ의 숫자를 만들어내는
방법을 모두 더했다. ㅁ은 당연히 0~n까지.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
long long int dp[201][201];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i <= n; i++)
	{
		dp[i][1] = 1;
	}
	for (int j = 2; j <= k; j++)
	{
		for (int i = 0; i <= n; i++)
		{
			for (int r = 0; r <= i; r++)
			{
				dp[i][j] = (dp[i][j] + dp[i - r][j - 1]) % 1000000000;
			}
		}
	}
	cout << dp[n][k];
	return 0;
}

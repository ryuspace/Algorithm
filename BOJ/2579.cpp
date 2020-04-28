//https://www.acmicpc.net/problem/2579
/*풀이 : dp[i][j]는 i번째 계단을 오를 건데 현재 j번 연속이다*/
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int step[301];
int dp[301][2];
int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> step[i];
	}
	dp[1][0] = step[1];
	dp[2][0] = step[2];
	dp[2][1] = step[1] + step[2];

	for (int i = 3; i <= n; i++)
	{
		dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + step[i];
		dp[i][1] = dp[i - 1][0] + step[i];
	}
	cout << max(dp[n][0], dp[n][1]);
	return 0;

}

//https://www.acmicpc.net/problem/1535
/*풀이 : 체력이 0이 되지 않게 얻을 수 있는 최대 행복을 dp[100]에다 저장해놓는다.*/
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int hp[21];
int happy[21];

int dp[101];
int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> hp[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> happy[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 100; j >= hp[i]+1; j--)
		{
			dp[j] = max(dp[j], dp[j - hp[i]]+happy[i]);
		}
	}
	cout << dp[100];
	return 0;

}

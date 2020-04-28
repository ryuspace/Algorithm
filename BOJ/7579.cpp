//https://www.acmicpc.net/problem/7579
/*풀이 : 기존의 냅색으로 풀기에는
메모리 M 바이트를 수용할 공간이 모잘랐다.
dp[x] : x 가격으로 최대한 얻을 수 있는 메모리
dp 배열을 조금 다르게 접근하였다.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[101];
int brr[101];
int dp[10222];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i <= 10221; i++)
	{
		dp[i] = -1;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> brr[i];
	}
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		int cost = brr[i];
		for (int j = 10221; j >= 0; j--)
		{
			if (j - cost >= 0)
			{
				if (dp[j - cost] != -1)
				{
					if (dp[j] == -1)
					{
						dp[j] = dp[j - cost] + arr[i];
					}
					else
					{
						dp[j] = max(dp[j], dp[j - cost] + arr[i]);
					}
				}
			}
		}
	}
	for (int i = 0; i <= 10221; i++)
	{

		if (dp[i] >= m)
		{
			cout << i;
			exit(0);
		}
	}
	return 0;
}

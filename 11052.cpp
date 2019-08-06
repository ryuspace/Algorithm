//https://www.acmicpc.net/problem/11052
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[10001];
int dp[10001];//dp[n] : 카드 n개를 구입했을 때 최대값
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i;j++)
		{
			dp[i] = max(dp[i], dp[i-j] + arr[j]);
		}
	}
	cout << dp[n];
	return 0;
}


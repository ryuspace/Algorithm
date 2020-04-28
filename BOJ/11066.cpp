//https://www.acmicpc.net/problem/11066
/*풀이 : 
dp[i][j] : i부터 j까지 파일을 합치는데 드는 최소 비용.
i~j 사이에 구간을 나눠 그 구간에 대해 나눠서 합쳐보고 최소 비용을 찾아본다.
시간복잡도 : O(n^3)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int arr[501];
int dp[501][501];

int main(void)
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int k;
		cin >> k;
		for (int i = 1; i <= k; i++)
		{
			cin >> arr[i];
		}

		for (int i = 2; i <= k; i++)
		{
			arr[i] += arr[i - 1];
		}
		for (int i = 1; i <= k; i++)
		{
			for (int j = 1; j <= k-i; j++)
			{
				dp[j][j + i] = 1e9;
				for (int r = j; r <= j+i; r++)
				{
					dp[j][j + i] = min(dp[j][j+i], arr[j + i] - arr[j - 1] + dp[j][r] + dp[r+1][j + i]);
				}
			}
		}
		cout << dp[1][k] << '\n';
	}
	return 0;
}

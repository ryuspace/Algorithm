//https://www.acmicpc.net/problem/9465
/*풀이 : https://blog.naver.com/coke_mania/221537502952
를 참고했습니다.*/
#include <iostream>
#include <algorithm>

using namespace std;

int arr[2][100001];
int dp[2][100001];
int main()
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int r = 0; r < t; r++)
	{
		int n;
		cin >> n;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
			}
		}
		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		for (int i = 1; i < n; i++)
		{
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + arr[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + arr[1][i];
		}
		cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
	}

	return 0;
}

//https://www.acmicpc.net/problem/17069
/*풀이 : dp를 이용해 현재 위치에서 올 수 있는 위치들의 경우의 수를 더해준다.
맨 윗줄로만 이어진 파이프는 중간에 벽이 생기기 전까지 가능한 경우의 수는 가로로 쭉 이은
한가지이므로 dp 배열을 처음에 초기화 해준다.*/
#include <iostream>
#include <algorithm>

using namespace std;
int n;
int arr[33][33];
long long int dp[3][33][33];
int res = 0;

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (arr[0][i] == 1)
			break;
		dp[0][0][i] = 1;
	}

	//0:가로 1:세로 2: 대각선
	for (int i = 1; i <n; i++)
	{
		for (int j = 2; j < n; j++)//(1,2) 부터 파이프가 시작된다!
		{
			if (arr[i][j] == 0)
			{
				if (arr[i][j-1] == 0)
				{
					dp[0][i][j] = dp[0][i][j-1] + dp[2][i][j-1];
				}
				if (arr[i-1][j] == 0)
				{
					dp[1][i][j] = dp[1][i-1][j] + dp[2][i-1][j];
				}
				if (arr[i-1][j] == 0 &&
					arr[i][j-1] == 0)
				{
					dp[2][i][j] = dp[0][i-1][j-1] + dp[1][i-1][j-1] + dp[2][i-1][j-1];
				}
			}
		
		}
	}
	cout << dp[0][n - 1][n - 1]+dp[1][n - 1][n - 1]+dp[2][n - 1][n - 1];
	return 0;
}

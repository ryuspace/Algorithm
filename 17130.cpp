//https://www.acmicpc.net/problem/17130
/*풀이 : n과 m이 각각 1000이므로
완탐 돌리면 3^1000승 나와서 시간초과.
현재 위치에서 왼쪽 대각선 위, 왼쪽,왼쪽 대각선 아래의 최대값으로
갱신해준다. 현재 위치에 당근이 있으면 +1을 해준다.
토끼는 오른쪽으로만 움직이므로 그 왼쪽거는 볼 것도 없다.
dp배열을 미리 -1로 초기화하고 토끼위치를 0으로 초기화 해서
dp배열 값을 갱신해줄때 최대값이 -1이 나왔다는 것은 벽에서 부터 왔거나
토끼위치의 왼쪽에서 왔단 뜻이므로 이 경우에는 무시해준다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
char arr[1002][1002];
int dp[1002][1002];
int maxx = -1;

int main()
{
	ios_base::sync_with_stdio(0);
	int col=0;
	cin >> n >> m;
	for (int i = 0; i < 1002; i++)
		for (int j = 0; j < 1002; j++)
			dp[i][j] = -1;
	for (int i = 1; i <=n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (arr[i][j] == 'R')
			{
				col = j;
				dp[i][j] = 0;
				break;
			}
		}
	}
	int maxx = -1;
	for (int j = col+1; j <= m; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (arr[i][j] != '#')
			{
				dp[i][j] = max({ dp[i - 1][j - 1],dp[i][j - 1],dp[i + 1][j - 1] });
				if (dp[i][j] == -1)
					continue;
				if (arr[i][j] == 'C')
				{
					dp[i][j]++;
				}
				if (arr[i][j] == 'O')
				{
					maxx = max(maxx, dp[i][j]);
				}
			}
		}
	}
	cout << maxx;
	return 0;

}

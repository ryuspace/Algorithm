//https://www.acmicpc.net/problem/1495
/*풀이 : 완탐으로 하면 2^200만큼 시간이 걸려서 tle가 뜬다.
매 차례마다 가능한 숫자가 2배씩 늘어 점화식을 찾기 어려워 힌트를 얻었다.
dp[N][M] : N 번째 일때 M의 볼륨이 가능한가 라고 세우고
매 차례 0~m까지 가능한 볼륨들을 체크해준다.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n, s, m;
int arr[101];
int dp[101][1001];
int main()
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> s >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	dp[0][s] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (dp[i - 1][j])
			{
				if (j + arr[i-1] <= m)
				{
					dp[i][j + arr[i-1]] = 1;
				}
				if (j - arr[i-1] >= 0)
				{
					dp[i][j - arr[i-1]] = 1;
				}
			}
			
		}
	}
	int maxx = -1;
	for (int i = 0; i <= m; i++)
	{
		if(dp[n][i]==1)
			maxx = max(i, maxx);
	}
	cout << maxx;
	return 0;
}

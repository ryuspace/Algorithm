//https://www.acmicpc.net/problem/2281
/*풀이 : 행에 대해서는 비교할 필요없다. 그 이유는.... 아마
값을 구하기 위해서 열만 보면 되니깐 그래서 인 것 같다. 다시 풀어보자*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 1004
int arr[MAX];
int dp[MAX][MAX];	//열,인덱스
int n, m;
int minn = 1e9;
int func(int y,int idx)
{
	if (idx == n+1)
		return 0;
	if (dp[y][idx] != 1e9)
		return dp[y][idx];
	//다른 행
	dp[y][idx] = min(dp[y][idx], func(arr[idx] + 2, idx + 1) + ((m - (y - 2)) * (m - (y - 2))));
	//같은 행
	if (y + arr[idx] - 1 <= m)
		dp[y][idx] = min(dp[y][idx], func(y + arr[idx] + 1, idx + 1));

	return dp[y][idx];
}
int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i <= MAX-1; i++)
	{
		for (int j = 1; j <= MAX-1; j++)
		{
			dp[i][j] = 1e9;
		}
	}
	func(1, 1);
	cout << dp[1][1];
	return 0;
}


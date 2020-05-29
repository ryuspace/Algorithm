//https://www.acmicpc.net/problem/4811
/*풀이 : 
top-down dp의 가장 기본. 
dp[x][y] : 현재 한 조각짜리 x개 반 조각짜리 y개가 있는데 경우의 수
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int t,n;
long long int dp[31][31];
long long int go(int w, int h)
{
	if (w == 0 && h == 0)
	{
		return 1;
	}

	if (dp[w][h] != -1)
	{
		return dp[w][h];
	}

	dp[w][h] = 0;
	
	if(w-1>=0)
		dp[w][h]+=go(w - 1, h + 1);

	if(h-1>=0)
		dp[w][h]+=go(w, h - 1);

	return dp[w][h];
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0;i < 31;i++)
	{
		for (int j = 0;j < 31;j++)
		{
			dp[i][j] = -1;
		}
	}
	cin >> t;
	while (t!=0)
	{
		cout<<go(t, 0)<<'\n';
		cin >> t;
	}
	return 0;
}

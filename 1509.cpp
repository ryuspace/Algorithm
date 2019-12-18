//https://www.acmicpc.net/problem/1509
/*풀이 : i~j번째의 구간에서 팰린드롬이면 j-1번째에서의 최소구간과 합해준다. 
memo배열을 이용해 i~j번째가 팰린드롬인지 체크해주고 나중에 같은 구간을 또 방문하면 호출을 방지해준다.
약 n^3이지만 팰린드롬 구하는 시간을 줄여서 통과가 된 것 같다.
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int dp[2501];
int memo[2501][2501];
string tmp;
int pal(int x, int y)
{
	if (x >= y)
	{
		return memo[x][y] = 1;
	}
	if (memo[x][y] != 1e9)
	{
		return memo[x][y];
	}

	if (tmp[x] == tmp[y])
	{
		return memo[x][y]=pal(x + 1, y - 1);
	}
	else
	{
		return memo[x][y] = 0;
	}
	
}
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> tmp;
	fill(&memo[0][0], &memo[tmp.length()][tmp.length()], 1e9);
	for (int i = 0; i < tmp.length(); i++)
	{
		dp[i] = 1e9;
		for (int j = 0; j <=i; j++)
		{
			if (pal(j, i))
			{
				if (i == 0 && j == 0)
					dp[0] = 1;
				else
					dp[i] = min(dp[i], dp[j - 1] + 1);
			}
		}
	}
	cout << dp[tmp.length() - 1];
	return 0;
}

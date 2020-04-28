//https://www.acmicpc.net/problem/9084
/*풀이 : n번째 동전까지 m원이 나오는 모든 경우를 더한다.*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int dp[10001];
int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		memset(dp, 0, sizeof(dp));
		vector<int> v;
		int n,m;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			int a;
			cin >> a;
			v.push_back(a);
		}
		cin >> m;
		dp[0] = 1;
		for (int j = 0; j < n; j++)
		{
			for (int k = v[j]; k <= m; k++)
			{
				dp[k] += dp[k - v[j]];
			}
		}
		cout << dp[m] << '\n';
	}
	return 0;
}

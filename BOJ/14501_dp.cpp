//https://www.acmicpc.net/problem/14501
/*풀이 : top-down dp로 기존 dfs 코드에서 바꿨다.*/
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
int n;
pii arr[16];
int dp[16];
int maxi;
int dfs(int num)
{
	if (num == n + 1)
	{
		return 0;
	}
	if (dp[num] != -1)
	{
		return dp[num];
	}
	dp[num] = 0;
	
	int num1 = 0;
	int num2 = 0;
	if (num + arr[num].first <= n + 1)
	{
		num1 = dfs(num + arr[num].first) + arr[num].second;
	}
	if(num+1<=n+1)
		num2 = dfs(num + 1);
	dp[num] = max(num1,num2);

	return dp[num];
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		dp[i] = -1;
		cin >> arr[i].first >> arr[i].second;
	}
	cout<<dfs(1);
	return 0;
}

//https://www.acmicpc.net/problem/12865
/*풀이 : 
dp[x][y] : 현재 x개까지 탐색했는데 y만큼 무게가 차 있을 때 최대 가치
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
int n, k;
pii arr[101];
int dp[101][100001];

int go(int w,int cnt)
{
	if (cnt == n)
	{
		return 0;
	}

	int r1 = 0, r2 = 0;

	if (dp[cnt][w] != -1)
		return dp[cnt][w];

	dp[cnt][w] = 0;

	if (w + arr[cnt].first <= k)
		r1 = arr[cnt].second+go(w + arr[cnt].first,cnt + 1);

	r2 = go(w, cnt + 1);

	return dp[cnt][w] = max(r1, r2);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k;

	for (int i = 0;i < n;i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}

	for (int i = 0;i <= k;i++)
	{
		for(int j=0;j<n;j++)
			dp[j][i] = -1;
	}

	cout<<go(0, 0);
	
	return 0;
}

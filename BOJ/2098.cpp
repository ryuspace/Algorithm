//https://www.acmicpc.net/problem/2098
/*풀이 : 욕심쟁이 판다랑 비슷한 문제. 이미 갔던 최단 경로는 dp배열에 저장해 다시 가지 못 하게 한다.
비트마스킹을 써서 방문한 도시의 번호의 비트를 체크해서 방문 표시를 한다.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[17][17];
int dp[17][1 << 17];

int dfs(int now,int visited)
{
	if (visited == (1 << n) - 1)
	{
		if (arr[now][0] != 0)
			return arr[now][0];
		else
			return 1e9;
	}
	if (dp[now][visited] > 0)
		return dp[now][visited];

	int minn = 1e9;
	for (int i = 0; i < n; i++)
	{
		if (arr[now][i] != 0 && !(visited & (1 << i)))
		{
			minn = min(minn, dfs(i, visited | (1 << i)) + arr[now][i]);
		}
	}
	dp[now][visited] = minn;
	return dp[now][visited];
}
int main()
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout<<dfs(0, 1);
	return 0;
}

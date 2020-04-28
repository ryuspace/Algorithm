//https://www.acmicpc.net/problem/1949
/*풀이 : N이 10000이므로 Naive하게 완전탐색을 돌리면 TLE가 난다.
어떤 루트노드가 선택되었을 때, 선택되지않았을 때로 나누고
선택되었으면 자식노드가 선택되지않았을 때의 최댓값을,
선택되지않았으면 자식노드가 선택되거나 선택되지않았을 때 둘 중 더 큰 값으로 선택을 해주어
어떤 루트노드의 최대값을 구해준다.
이는 dp로 해결할 수 있고 dp배열은 dp[선택여부][현재노드]로 정의할 수 있다.
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int house[10002];
vector<int> v[10002];
int dp[2][10002];
int dfs(int num,int parent,bool flag)
{
	int ret = 0;
	if (dp[flag][num] > 0)
		return dp[flag][num];
	if (flag == true)
		dp[flag][num]=ret += house[num];
	for (int i = 0; i < v[num].size(); i++)
	{
		if (v[num][i] != parent)
		{
			if (flag == false)
			{
				ret += max(dfs(v[num][i],num, false), dfs(v[num][i], num, true));
			}
			else
			{
				ret += dfs(v[num][i], num, false);
			}
		}
		
	}
	return dp[flag][num]=ret;
	
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> house[i];
	}
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, 0, false);
	dfs(1, 0, true);

	cout << max(dp[0][1], dp[1][1]);
	return 0;
}

//https://www.acmicpc.net/problem/2422
/*벡터에 각각 안되는 경우를 넣는다.
dfs를 이용해 가능한 모든 순열을 만들어보고
안되는 경우를 체크해본다.*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> v[201];
int hi[10001];
int ans = 0;
void dfs(int cnt, int idx)
{
	if (cnt == 3)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < v[hi[i]].size(); j++)
			{
				if (i == 0)
				{
					if (v[hi[i]][j] == hi[1]
						|| v[hi[i]][j] == hi[2])
						return;
				}
				else if (i == 1)
				{
					if (v[hi[i]][j] == hi[0]
						|| v[hi[i]][j] == hi[2])
						return;
				}
				else if (i == 2)
				{
					if (v[hi[i]][j] == hi[0]
						|| v[hi[i]][j] == hi[1])
						return;
				}
			}
		}
		ans++;
		return;
	}
	for (int i = idx; i <= n; i++)
	{
		hi[cnt] = i;
		dfs(cnt + 1, i + 1);
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(0, 1);
	cout << ans;
	return 0;
}

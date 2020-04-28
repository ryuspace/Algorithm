//https://www.acmicpc.net/problem/5567
/*풀이 : 처음엔 dfs를 이용하니까 복잡하게 연결되었을 때 문제가 생겼었다.
친구 관계를 visit 처리를 해주니까 간단하게 친구 관계를 파악할 수 있다. */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v[501];
bool visit[501];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int res = 0;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < v[1].size(); i++)
	{
		visit[v[1][i]] = true;
		int hi = v[1][i];
		for (int j = 0; j < v[hi].size(); j++)
		{
			visit[v[hi][j]] = true;
		}
	}
	for (int i = 2; i <= n; i++)
	{
		if (visit[i] == true)
			res++;
	}
	cout << res;
	return 0;
}

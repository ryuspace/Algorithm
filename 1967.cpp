//https://www.acmicpc.net/problem/1967
/*풀이 : 임의의 한 점에서 가장 먼 노드를 찾고 그 노드에서 또 가장 먼 노드를 찾은 것의 가중치 합이 트리의 지름이다.*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector < pair<int, int> > v[10001];
bool visit[10001];
int ans, endd;
void dfs(int start, int score)
{
	if (ans < score)
	{
		ans = score;
		endd = start;
	}
	visit[start] = true;
	for (int i = 0; i < v[start].size(); i++)
	{
		if (visit[v[start][i].first] == false)
		{
			dfs(v[start][i].first,score+v[start][i].second);
		}
	}

}
int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	dfs(1, 0);
	memset(visit, 0, sizeof(visit));
	ans = 0;
	dfs(endd, 0);
	cout << ans;
	return 0;
}

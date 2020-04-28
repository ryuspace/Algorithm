//https://www.acmicpc.net/problem/1325
/*풀이 : 정점마다 dfs를 이용해 dfs 함수가 몇번 호출되었는지 세고 그 횟수의 최대인 정점들을 찾는다.
하지만 bfs가 더 빠르게 동작함.. */
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;
int n, m;
vector <int> v[10001];
bool visit[10001];
int arr[10001];
int maxx = 0;
int maxx2 = 0;
void dfs(int n)
{
	maxx2++;
	visit[n] = true;
	for (int i = 0; i < v[n].size(); i++)
	{
		if (!visit[v[n][i]])
			dfs(v[n][i]);
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
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
	{
		memset(visit, 0, sizeof(visit));
		dfs(i);
		arr[i] = maxx2;
		maxx = max(maxx, maxx2);
		maxx2 = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		if (maxx == arr[i])
			cout << i << " ";
	}
	return 0;
}

//https://www.acmicpc.net/problem/1761
/*풀이 : 루트노드를 기준으로 깊이가 깊어지는 방향으로 지금 트리의 가중치와 이전 트리의 가중치를 더하는 배열을 만든다.
그리고 최소공통조상을 구하고 두 노드의 가중치를 더하고 최소공통조상의 가중치 두배(두번 더 더해졌으니까)를 빼주면
원하는 값이 나온다.*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
vector<pii> v[40001];
bool c[40001];
int d[40001];
int parent[40001][17];
int dist[40001];
int n;
void dfs(int node, int depth,int sum)
{
	c[node] = true;
	d[node] = depth;
	dist[node] = sum;
	for (int i = 0; i < v[node].size(); i++)
	{
		if (c[v[node][i].first] == true)
			continue;
		parent[v[node][i].first][0] = node;
		dfs(v[node][i].first, depth + 1,sum+v[node][i].second);
	}
}
//16까지
void set()
{
	for (int i = 1; i <= 16; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
		}
	}

}

int lca(int x,int y)//x와 y의 최소공통조상을 찾자!
{
	if (d[x] > d[y])
	{
		swap(x, y);
	}//y가 더 깊이 깊게 유지

	for (int i = 16; i >= 0; i--)
	{
		if (d[y] - d[x] >= (1 << i))
		{
			y = parent[y][i];
		}//2^(i)보다 차이가 적게 날때까지 올려보내자

	}
	if (x == y)
	{
		return x;
	}
	for (int i = 16; i >= 0; i--)
	{
		if (parent[x][i] != parent[y][i])
		{
			x = parent[x][i];
			y = parent[y][i];
		}

	}

	return parent[x][0];
}
int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	dfs(1, 0,0);
	set();
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int a, b;
		cin >> a >> b;
		int num = lca(a, b);
		cout << dist[a] + dist[b] - dist[num] * 2<<'\n';
	}
	return 0;
}

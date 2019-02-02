//https://www.acmicpc.net/problem/2307
/*풀이 : 전체에 대해서 dikstra를 돌리고 dikstra 경로를 역추적 해서 경로를 하나씩 지워나가면서 지연시간의 최대를 찾는다. 최단 경로로 갈 것이고 최단 경로가 아닌 곳을 지우면 의미가 없다.*/
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <cstring>
using namespace std;

int V, E;
int k;

vector < pair<int, int> > vec[1001];
int parent[1001];
priority_queue< pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;

int price[20001];

int dikstra(int u,int v)
{
	for (int i = 1; i <= V; i++)
	{
		price[i] = 1e9;
	}
	price[1] = 0;
	q.push({ 0,1 });

	while (!q.empty())
	{
		int node = q.top().second;
		int pr = q.top().first;
		q.pop();
		if (price[node] < pr)
			continue;
		for (int i = 0; i < vec[node].size(); i++)
		{
			int next_node = vec[node][i].first;
			int next_price = vec[node][i].second;
			if ((node == u && next_node == v) || (node == v && next_node == u))
			{
				continue;
			}
			if (next_price + pr < price[next_node])
			{
				price[next_node] = next_price + pr;
				q.push({ next_price + pr,next_node });
				parent[next_node] = node;
			}
		}
	}
	return price[V];

}
int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	memset(parent, -1, sizeof(parent));
	cin >> V >> E;
	for (int i = 0; i<E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back({ b,c });
	}
	int Minn=dikstra(0,0);
	int vertex = V;
	int ans = 0;
	while (parent[vertex] != -1)
	{
		int u = vertex;
		int v = parent[u];
		ans = max(ans, dikstra(u, v));
		vertex = v;
	}
	if (ans == 1e9)
	{
		cout << -1;
	}
	else
	{
		cout << ans - Minn;
	}
	return 0;
}

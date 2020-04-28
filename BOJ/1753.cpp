//https://www.acmicpc.net/problem/1753
//풀이 : 최소비용을 가진 정점이 큐의 가장 위에 와야하니까 우선순위 큐를 이용한다.
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int V, E;
int k;

vector < pair<int, int> > vec[20001];
priority_queue< pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
int price[20001];

void dikstra()
{
	for (int i = 1; i <= V; i++)
	{
		price[i] = 1e9;
	}
	price[k] = 0;
	q.push({ 0,k });

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
			if (next_price + pr < price[next_node])
			{
				price[next_node] = next_price + pr;
				q.push({ next_price + pr,next_node });
			}
		}
	}


}
int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	cin >> V >> E;
	cin >> k;
	for (int i = 0; i<E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back({ b,c });
	}
	dikstra();
	for (int i = 1; i <= V; i++)
	{
		if (price[i] == 1e9)
		{
			cout << "INF" << '\n';
		}
		else
		{
			cout << price[i] << '\n';
		}
	}
	return 0;
}

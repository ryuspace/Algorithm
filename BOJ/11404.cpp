//https://www.acmicpc.net/problem/11404
/*풀이 : 전형적인 다익스트라 문제*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int, int> pii;
int n, m;
vector<pii> v[101];
int price[101];
priority_queue<pii, vector<pii>, greater<pii> >pq;
void dikstra(int num)
{
	for (int i = 1; i <= n; i++)
	{
		price[i] = 1e9;
	}
	price[num] = 0;
	pq.push({ 0, num});
	while (!pq.empty())
	{
		int node = pq.top().second;
		int pr = pq.top().first;
		pq.pop();
		if (pr > price[node])//이 노드로 가는 방법의 price가 기존에 이 노드로 가는 방법의 최소 price보다 비싸면 탐색할 필요도 없다.
			continue;
		for (int i = 0; i < v[node].size(); i++)
		{
			int next_node = v[node][i].second;
			int next_price = v[node][i].first;
			if (next_price + pr < price[next_node])
			{
				price[next_node] = next_price + pr;
				pq.push(make_pair(next_price + pr, next_node));
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(make_pair(c, b));
	}
	for (int i = 1; i <= n; i++)
	{
		dikstra(i);
		for (int j = 1; j <= n; j++)
		{
			if (price[j] == 1e9)
				cout << 0 << " ";
			else
				cout << price[j] << " ";
		}
		cout << '\n';
	}
	return 0;
}

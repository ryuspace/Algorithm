//https://www.acmicpc.net/problem/16763
/*풀이 : n번째 풀을 기점으로 다익스트라를 돌려 각 정점에서 n까지 가는 최단 경로를 구한 후
haybale의 위치의 최단경로 값과 그 맛만큼 뺀 가중치를 고려해 다익스트라를 또 돌려 본다.
그래서 어떤 정점에 갔는데 기존에 다익스트라 돌린 것보다 더 작거나 같은 값이 나오면
haybale에서 먹은 것이 이득이니깐 체크해준다.
기존 다익스트라의 최단경로를 담은 배열을 price라고 하고 haybale이 2에 있으면
price[2]-맛을 한 그 값은 2번 위치에서 n번 위치를 간 경우에서의 최단경로를 보장한다. 
애초에 n번에서 다익을 돌린거니깐! <=이걸 생각해내기가 어려웠다.
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <cstring>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
int n, m, k;
vector<pii> v[50001];
int price[50001];
int hi[50001];
bool ans[50001];
void dik()
{
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push({ 0,n });
	price[n] = 0;
	while (!pq.empty())
	{
		pii front = pq.top();
		int pr = front.first;
		int node = front.second;
		pq.pop();
		for (int i = 0; i < v[node].size(); i++)
		{
			int next_node = v[node][i].first;
			int next_pr = v[node][i].second;
			if (price[next_node] < pr + next_pr)
				continue;
			price[next_node] = next_pr + pr;
			pq.push({ next_pr+pr,next_node });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		price[i] = 1e9;
		hi[i] = 1e9;
	}
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	dik();
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		hi[a] = price[a] - b;
		pq.push({ hi[a],a });
	}
	while (!pq.empty())
	{
		pii front = pq.top();
		pq.pop();
		int pr = front.first;
		int node = front.second;
		if (price[node] >= hi[node])
		{
			ans[node] = 1;
		}
		for (int i = 0; i < v[node].size(); i++)
		{
			int next_pr = v[node][i].second;
			int next_node = v[node][i].first;
			if (hi[next_node] < pr + next_pr)
				continue;
			hi[next_node] = next_pr + pr;
			pq.push({ next_pr+pr,next_node });
		}
	}
	for (int i = 1; i < n; i++)
	{
		cout << ans[i] << '\n';
	}
	return 0;
}

//https://www.acmicpc.net/problem/1238
/*풀이 : 모든 정점에서 x로 가는 걸 일일이 다익을 돌리지 말고
정점에서 정점으로 가는 역방향을 새로운 벡터에 담고 x에서 임의의 점으로 다익을 돌리면
한번에 돌아가는 길의 최단거리를 찾을 수 있는 것이 포인트 ! */
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;
vector <pii> v[1001];
vector <pii> v2[1001];
int pri[1001];
int ans[1001];
int n, m, x;
int dik(int start,int des,vector<pii> v[1001])
{
	fill(pri, pri + n+1, 1e9);
	priority_queue<pii, vector<pii>, greater<pii>> pq;//greater이 오름차순
	pq.push({ 0,start });
	pri[start] = 0;
	while (!pq.empty())
	{
		pii front = pq.top();
		pq.pop();
		int price = front.first;
		int node = front.second;
		if (price > pri[node])
			continue;
		for (int i = 0; i < v[node].size(); i++)
		{
			int next_node = v[node][i].first;
			int next_price = v[node][i].second;
			if (pri[next_node] > next_price+price)
			{
				pri[next_node] = next_price+price;
				pq.push({ next_price + price,next_node });
			}
		}
	}
	return pri[des];
}
int main()
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v2[b].push_back({ a,c });
	}
	int maxx = 0;
	dik(x,1,v);
	for (int i = 1; i <= n; i++)
	{

		ans[i] = pri[i];
	}
	dik(x, 1,v2);
	for (int i = 1; i <= n; i++)
	{
		maxx = max(maxx, ans[i] + pri[i]);
	}
	cout << maxx;
	return 0;
}

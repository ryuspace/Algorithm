//https://www.acmicpc.net/problem/1922
/*풀이 : 프림 알고리즘을 그대로 적용하면 된다. 방문되지 않은 노드의
비용이 가장 적은 간선을 선택할 것이므로 priority queue를 사용한다.*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

vector < pair <int, int> > vec[10001];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>> > q;
bool visit[10001];
int v, e;
int price;
void prim(int n)
{
	visit[n] = true;
	for (int i = 0; i < vec[n].size(); i++)
	{
		if (visit[vec[n][i].second] == false)
		{
			q.push({ vec[n][i].first,vec[n][i].second });
		}
	}
	while (!q.empty())
	{
		pair <int, int> front = q.top();
		q.pop();
		if (visit[front.second] == false)
		{
			price += front.first;
			prim(front.second);
			return;

		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	cin >> v >> e;
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back({ c,b });
		vec[b].push_back({ c,a });
	}
	prim(1);
	cout << price;
	return 0;
}

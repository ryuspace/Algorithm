//https://www.acmicpc.net/problem/5719
/*풀이 : 처음 다익스트라를 돌려서 최단경로를 찾고 그 최단경로의 부모를 
벡터 배열에다 담는다. 그리고 그 벡터 배열을 역추적 하여 그 길을 전부 막고
다시 다익스트라를 돌린다.*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;
int price[501];
vector<int> parent[501];
priority_queue<pii, vector<pii>, less<pii> > pq;
vector<pii> v[501];
int n, m, start, End;
void dik(int start, int end)
{
	for (int i = 0; i <= n; i++)
		price[i] = 1e9;
	price[start] = 0;
	pq.push({ 0,start });
	while (!pq.empty())
	{
		pii front = pq.top();
		pq.pop();
		int node = front.second;
		int pr = front.first;
		if (price[node] < pr)
			continue;
		for (int i = 0; i < v[node].size(); i++)
		{
			if (v[node][i].first == -1)
				continue;
			int next_price = v[node][i].first;
			int next_node = v[node][i].second;
			if (price[next_node] > pr + next_price)
			{
				parent[next_node].clear();
			}
			if (price[next_node] >= pr + next_price)
			{
				pq.push({ pr + next_price,next_node });
				parent[next_node].push_back(node);
				price[next_node] = pr + next_price;
			}
		}
	}
}
void Erase(int pos)
{
	queue<int> q;
	q.push(pos);
	while (!q.empty())
	{
		int front = q.front();
		q.pop();
		for (int i = 0; i < parent[front].size(); i++)
		{
			int back = parent[front][i];
			for (int j = 0; j < v[back].size(); j++)
			{
				if (v[back][j].second == front)
				{
					v[back][j].first = -1;
				}

			}
			q.push(back);
		}
	}
}
int main()
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while (true)
	{
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		cin >> start >> End;
		for (int i = 0; i < m; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			v[a].push_back({ c,b });
		}
		dik(start, End);
		Erase(End);
		dik(start, End);
		if (price[End] >= 1e9)
			cout << -1 << '\n';
		else
			cout << price[End] << '\n';
		for (int i = 0; i <= 500; i++)
		{
			parent[i].clear();
			v[i].clear();
		}
	}
	return 0;
}

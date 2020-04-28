//https://www.acmicpc.net/problem/1939
/*풀이 : 연결된 다리를 dfs를 이용하여 푼다. 이분탐색을 이용해 건널 수 있는 최대 중량을 찾는다.*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector <pair<int, int> > v[1000001];


bool visit[100001];
int start, End;
bool bfs(int limit)
{
	queue <int> q;
	visit[start] = true;
	q.push(start);

	while (!q.empty())
	{
		int front = q.front();
		q.pop();
		if (front == End)
			return true;
		for (int i = 0; i < v[front].size(); i++)
		{
			int next = v[front][i].first;
			int nextcost = v[front][i].second;
			if (visit[next] == false && nextcost >=limit)
			{
				visit[next] = true;
				q.push(next);
			}
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int n, m;
	int a, b, c;
	int Max_c = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
		Max_c = max(Max_c, c);
	}

	cin >> start >> End;
	int left = 1;
	int right = Max_c;
	int ans = 0;
	while (left <= right)
	{
		memset(visit, false, sizeof(visit));
		int mid = (left + right) / 2;
		if (bfs(mid))
		{
			if (ans < mid)
				ans = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}

	}
	cout << ans;
	return 0;
}

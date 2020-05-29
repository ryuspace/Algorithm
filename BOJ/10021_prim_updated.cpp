//https://www.acmicpc.net/problem/10021
/*
풀이 : 기존 E*E + Vlog(E) 프림 알고리즘에서 다익스트라 개념을 약간 추가해서 V(log(E))로 개선시켰다.
우선 임의의 한 정점을 잡고, (1~n) 모든 정점과 가중치를 pq에 넣고 (c이상인 값만) 방문하지 않은 정점 중 최소 가중치를 매번 갱신해준다.
매번 큐에서 기준 정점을 빼낼 때 그 정점은 다시 갈 일이 없으니깐 visit 처리를 그쪽에서 해준다.

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <functional>
using namespace std;

typedef pair<int, int> pii;
int n, c;
pii arr[2001];
bool visit[2001];
int price[2001];
priority_queue<pii, vector<pii>, greater<pii> > pq;
int sum;

int dis(pii one, pii two)
{
	int hi = abs(one.first - two.first);
	int bye = abs(one.second - two.second);
	return hi * hi + bye * bye;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> c;

	for (int i = 0;i < n;i++)
	{
		price[i] = 1e9;
		int a, b;
		cin >> a >> b;
		arr[i] = { a,b };
	}
	pq.push({ 0,0 });

	price[0] = 0;
	while (!pq.empty())
	{
		pii front = pq.top();
		pq.pop();
		if (visit[front.second])
			continue;
		visit[front.second] = true;
		for (int i = 0;i < n;i++)
		{
			if (!visit[i] && dis(arr[front.second], arr[i]) >= c && price[i] > dis(arr[front.second], arr[i]))
			{
				pq.push({ dis(arr[front.second],arr[i]),i });
				price[i] = dis(arr[front.second], arr[i]);
			}
		}
	}

	int sum = 0;
	bool flag = false;
	for (int i = 0;i < n;i++)
	{
		if (price[i] == 1e9)
		{
			flag = true;
			break;
		}
		else
		{
			sum += price[i];
		}
	}
	if (flag)
	{
		cout << -1;
	}
	else
	{
		cout << sum;
	}
	return 0;
}

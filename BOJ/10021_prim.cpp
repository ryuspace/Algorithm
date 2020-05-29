//https://www.acmicpc.net/problem/10021
/*풀이 :
파이프를 연결하는 간선의 가중치가 C이상인 것들만 연결을 표시하고 프림 알고리즘을 이용해서 최소 스패닝 트리를 구한다.
시간복잡도 (E*log(E))
4000000*log(4000000) => 약 8400만 시간 개선이 조금 필요하다/

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
int a, b;
vector<pii> point;
vector<pii> v[2001];
bool visit[2001];
priority_queue<pii,vector<pii>,greater<pii> > pq;
int sum;

void prim(int num)
{
	visit[num] = true;
	for (int i = 0;i < v[num].size();i++)
	{
		if(!visit[v[num][i].first])
			pq.push({ v[num][i].second,v[num][i].first });
	}

	while (!pq.empty())
	{
		pii front = pq.top();
		pq.pop();
		int price = front.first;
		int new_node = front.second;
		if (!visit[new_node])
		{
			sum += price;
			prim(new_node);
			return;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> c;
	for (int i = 0;i < n;i++)
	{
		cin >> a >> b;
		point.push_back({ a,b });
	}
	for (int i = 0;i < point.size();i++)
	{
		for (int j = i + 1;j < point.size();j++)
		{
			if (pow(abs(point[i].first - point[j].first),2) + pow(abs(point[i].second - point[j].second),2) >= c)
			{
				v[i].push_back({ j,pow(abs(point[i].first - point[j].first),2) + pow(abs(point[i].second - point[j].second),2) });
				v[j].push_back({ i,pow(abs(point[i].first - point[j].first),2) + pow(abs(point[i].second - point[j].second),2) });
			}
		}
	}
	prim(0);
	bool flag = false;
	for (int i = 0;i < n;i++)
	{
		if (!visit[i])
		{
			flag = true;
			break;
		}
	}
	if (sum == 0 || flag)
	{
		cout << -1;
	}
	else
		cout << sum;
	return 0;
}

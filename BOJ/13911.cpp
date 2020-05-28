//https://www.acmicpc.net/problem/13911
/*풀이 : 나름의 발상의 전환이 필요했던 문제.
다익스트라 알고리즘이 시간복잡도가 E(log(E))지만 모든 집의 정점에서 맥세권 스세권을 찾으려면 사실상 V*E(log(E)) 이므로 시간 내에 찾을 수 없다.
모든 맥도날드로 가는 dummy 정점 하나와 모든 스타벅스로 가는 dummy 정점 하나만 있으면 그 정점에서만 총 2번 다익스트라 돌리면 맥도날드와 스타벅스는
들렸다는 보장이 되니까 최단 경로를 알 수 있다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>

using namespace std;

typedef pair<long long int, long long int> pll;
typedef long long int ll;

int v, e;
vector<pll> vec[10005];
ll gap[2][100005];
int mac_x, su_x;
int mac_n, su_n;
bool house[10001];
void dik(int num,int dir)
{
	priority_queue<pll, vector<pll>, greater<pll> > pq;
	pq.push(make_pair(0,num));
	gap[dir][num] = 0;
	while (!pq.empty())
	{
		pll front = pq.top();
		pq.pop();
		ll price = front.first;
		int node = front.second;
		for (int i = 0;i < vec[node].size();i++)
		{
			int new_price = vec[node][i].second;
			int new_node = vec[node][i].first;
			if (price + new_price < gap[dir][new_node])
			{
				gap[dir][new_node] = price + new_price;
				pq.push(make_pair( price + new_price,new_node ));
			}
		}

	}

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> v >> e;
	for (int i = 1;i <= v;i++)
	{
		for (int j = 0;j < 2;j++)
		{
			gap[j][i] = 1e18;

		}
	}
	for (int i = 0;i < e;i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back({ b,c });
		vec[b].push_back({ a,c });
	}
	cin >> mac_n >> mac_x;

	for (int i = 0;i < mac_n;i++)
	{
		int a;
		cin >> a;
		vec[a].push_back({ 10001,0 });
		vec[10001].push_back({ a,0 });
		house[a] = true;
	}
	cin >> su_n >> su_x;
	//10001번 맥도날드 더미노드
	for (int i = 0;i < su_n;i++)
	{
		int a;
		cin >> a;
		vec[a].push_back({ 10002,0 });
		vec[10002].push_back({ a,0 });
		house[a] = true;
	}

	dik(10001,0);
	dik(10002, 1);

	ll mini = 1e18;
	for (int i = 1;i <= v;i++)
	{
		if (!house[i] && gap[0][i] <= mac_x && gap[1][i] <= su_x)
		{
			mini = min(mini, gap[0][i] + gap[1][i]);
		}
	}
	if (mini != 1e18)
		cout << mini;
	else
		cout << -1;
	return 0;
}

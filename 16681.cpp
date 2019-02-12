//https://www.acmicpc.net/problem/16681

/*풀이 : 거리를 가장 적게 가는게 가치 높이는데 영향이 있다 . 집 -> 지점 고려대 ->지점 이렇게 다익을 2번 돌린다. 배열에 2개의 다익의 정보가 담기게 한다.
for문을 돌려 지점별로 탐색해 가장 가치가 높은 것을 찾는다. 가치는 음수가 나올 수 있으므로 Max를 여유롭게 -1e18로 초기화한다. price의 정보가 하나라도 1e18 이면
그 지점은 가지 못하므로 continue. long long형 주의*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
typedef pair<long long int, long long int> pii;
int h[100001];
vector < pii > v[100001];
priority_queue < pii, vector <pii>, greater<pii> > pq;
long long int price[2][100001]; //올라가는 다익 하나 내려가는 다익 하나..2개

void dikstra(int start, int test)
{
	for (int i = 0; i <= 100000; i++)
	{
		price[test][i] = 1e18;
	}
	price[test][start] = 0;

	pq.push({ 0,start });

	while (!pq.empty())
	{
		long long int pr = pq.top().first;
		long long int node = pq.top().second;
		pq.pop();

		if (price[test][node] < pr)
			continue;
		for (int i = 0; i < v[node].size(); i++)
		{
			long long int next_pr = v[node][i].second;
			long long int next_node = v[node][i].first;

			if (pr + next_pr < price[test][next_node] && h[node]<h[next_node])
			{

				price[test][next_node] = next_pr + pr;
				pq.push({ next_pr + pr,next_node });
			}
		}
	}

}
int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int n, m, d, e;
	cin >> n >> m >> d >> e;

	for (int i = 1; i <= n; i++)
	{
		cin >> h[i];
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	dikstra(1, 0);
	dikstra(n, 1);
	long long int Max = -1e18;
	for (int i = 2; i < n; i++)
	{
		long long int tmp = h[i] * e - (price[0][i] * d + price[1][i] * d);
		if (price[0][i] == 1e18 || price[1][i] == 1e18)
			continue;
		Max = max(tmp, Max);
	}
	if (Max == -1e18)
	{
		cout << "Impossible";
	}
	else
	{
		cout << Max;
	}
	return 0;
}

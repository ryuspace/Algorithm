//https://www.acmicpc.net/problem/1967
/*풀이 : 한 점에서 다른 한 점을 지나는 경로가 가장 먼 경우를 트리의 지름이라고 한다. 

트리의 지름에 해당되는 두 점을 A와 B라 하고 임의의 점을 C라고 하고, 그 C와 가장 먼 곳에 있는 정점을 D라고 하자. 
그럼 3가지 경우를 생각할 수 있다.
1.C와 D중 적어도 하나가 A와 B랑 겹친다. => 반드시 (A==C || A==D) && (B==C || B==D) 일 수 밖에 없다.
2.C에서 D까지 가는 경로가 A에서 B까지 가는 경로에 겹친다. => 이것 또한 (A==C || A==D) && (B==C || B==D) 일 수 밖에 없다.
3.C에서 D까지 가는 경로가 A에서 B까지 가는 경로에 겹치지 않는다.=> 이런 상황은 벌어질 수 없다. A에서 B까지 가는 경로가 C에서 D까지 가는
경로보다 길다? 그럼 그게 트리의 지름이겠지? 무조건 겹치게 되어있다. 즉 A나 B에 도착할 수 밖에 없다.

결론 : 임의의 한 점에서 가장 먼 노드를 찾고 그 노드에서 또 가장 먼 노드를 찾은 것의 가중치 합이 트리의 지름이다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector < pair<int, int> > v[10001];
bool visit[10001];
int ans, endd;
void dfs(int start, int score)
{
	if (ans < score)
	{
		ans = score;
		endd = start;
	}
	visit[start] = true;
	for (int i = 0; i < v[start].size(); i++)
	{
		if (visit[v[start][i].first] == false)
		{
			dfs(v[start][i].first,score+v[start][i].second);
		}
	}

}
int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	dfs(1, 0);
	memset(visit, 0, sizeof(visit));
	ans = 0;
	dfs(endd, 0);
	cout << ans;
	return 0;
}

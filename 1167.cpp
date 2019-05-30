//https://www.acmicpc.net/problem/1167
/*풀이 : 임의의 정점을 잡고 가장 먼 거리의 점을 찾는다.
그리고 그 점을 기준으로 또 가장 먼 거리의 점을 찾으면 
그 거리들의 합이 트리의 지름이 된다.*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
typedef pair<int, int> pii;
vector <pii> vec[100001];
bool visit[100001];
int now = 0;
int point;
void dfs(int num,int len)
{
	visit[num]=true;
	for (int i = 0; i < vec[num].size(); i++)
	{
		if (!visit[vec[num][i].first])
		{
			dfs(vec[num][i].first, len + vec[num][i].second);
		}
	}
	if (now < len)
	{
		now = len;
		point = num;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int v;
	cin >> v;
	for (int i = 1; i <= v; i++)
	{
		int num;
		cin >> num;
		int a, b;
		cin >> a;
		while (a != -1)
		{
			cin >> b;
			vec[num].push_back({ a,b });
			cin >> a;
		}
	}
	dfs(1, 0);
	memset(visit, 0, sizeof(visit));
	dfs(point, 0);
	cout << now;
	return 0;
}

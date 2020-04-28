//https://www.acmicpc.net/problem/15481
/*풀이 : 전체적으로 MST를 구하고 입력된 가중치를 추가한다. 입력된 정점이 u와 v라고
할때 u~ lca(u,v) ~ v 까지 경로 중 가장 긴 경로를 제거한다. 그렇게 하면 MST는 유지되면서 원하는 쿼리를 해결할 수 있다.

*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
struct point
{
	int a, b, gap;
};
long long n, m;
vector<pii> mst[200001];
bool cmp(point & a, point & b)
{
	return a.gap < b.gap;
}
int parent[200001];
int find(long long a)
{
	if (a == parent[a])
		return a;
	return parent[a] = find(parent[a]);
}
void uni(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}
long long mst_hap;
bool visit[200001];
int depth[200001];
int parent2[200001][21];
long long dist[200001][21];
void dfs(int num, int d)
{
	for (int i = 0; i < mst[num].size(); i++)
	{
		if (!visit[mst[num][i].first])
		{
			parent2[mst[num][i].first][0] = num;

			depth[mst[num][i].first] = d + 1;

			dist[mst[num][i].first][0] = mst[num][i].second;

			visit[mst[num][i].first] = true;

			dfs(mst[num][i].first, d + 1);
		}
	}
}

void sett()
{
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			parent2[j][i] = parent2[parent2[j][i - 1]][i - 1];
			dist[j][i] = max(dist[j][i - 1], dist[parent2[j][i - 1]][i - 1]);
			//dist 구하는 거 핵심 부분이다. 현재 노드에서 2^i 앞에 있는 부모까지 가장 긴 가중치를 탐색할 건데 그 경로를 반으로 나눴다 생각하면 앞선 반 경로는 이미 구해놓은 상태다. 이해가 가지 않는다면 다시 그림으로 그려보자!
		}
	}
}

long long  go(int a, int b)
{
	long long  maxx = 0;
	if (depth[a] > depth[b])
		swap(a, b);
	for (int i = 19; i >= 0; i--)
	{
		if (depth[b] - depth[a] >= (1 << i) )
		{
			maxx = max(maxx, dist[b][i]);
			b = parent2[b][i];
		}
	}
	if (a == b)
		return maxx;
	for (int i = 19; i >= 0; i--)
	{
		if (parent2[a][i] != parent2[b][i])
		{
			maxx = max(maxx, max(dist[a][i], dist[b][i]));
			a = parent2[a][i];
			b = parent2[b][i];
		}
	}
	maxx = max(maxx, max(dist[a][0], dist[b][0]));
	return maxx;
}
int main()
{
	vector<point> v;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ a,b,c });
	}

	vector<point> vv;
	vv = v;
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++)
	{
		if (!(find(v[i].a) == find(v[i].b)))
		{
			uni(v[i].a, v[i].b);
			mst[v[i].a].push_back({ v[i].b,v[i].gap });
			mst[v[i].b].push_back({ v[i].a,v[i].gap });
			mst_hap += v[i].gap;
		}
	}
	
	visit[1] = true;

	dfs(1, 0);

	sett();

	for (int i = 0; i < m; i++)
	{
		cout << mst_hap + vv[i].gap - go(vv[i].a, vv[i].b) << '\n';

	}
	return 0;
}

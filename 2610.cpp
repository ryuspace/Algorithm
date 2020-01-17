//https://www.acmicpc.net/problem/2610
/*풀이 : union_find를 이용해 그룹을 구하고 , 
모든 정점을 기준으로 bfs를 돌리는데 가장 마지막 사람까지 도달한 최소 시간을 구하고
이 그룹에서의 최소시간에 도달한 것이면 체크해준다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int, int> pii;
int parent[101];
vector<int> v[101];
bool visit[101];
int group[101];
int group2[101];
int find(int a)
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
	{
		parent[b] = a;
	}
	else
	{
		parent[a] = b;
	}
}
void bfs(int num)
{
	int cnt = 0;
	memset(visit, 0, sizeof(visit));
	queue<int> q;
	q.push(num);
	visit[num] = true;
	while (!q.empty())
	{
		int sizz = q.size();
		while (sizz--)
		{
			int front = q.front();
			q.pop();
			for (int i = 0; i < v[front].size(); i++)
			{
				if (!visit[v[front][i]])
				{
					visit[v[front][i]] = true;
					q.push(v[front][i]);
				}
			}
		}
		cnt++;
	}
	if (group2[parent[num]] > cnt)
	{
		group2[parent[num]] = cnt;
		group[parent[num]] = num;
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
		group2[i] = 1e9;
		group[i] = 1e9;
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		parent[a] = find(a);
		parent[b] = find(b);
		uni(a, b);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		parent[i]= find(i);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!visit[parent[i]])
		{
			cnt++;
			visit[parent[i]] = true;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		bfs(i);
	}
	vector<int> ans;
	for (int i = 1; i <= n; i++)
	{
		if (group[i] != 1e9)
		{
			ans.push_back(group[i]);
		}
	}
	cout << cnt << '\n';
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << '\n';
	}
}

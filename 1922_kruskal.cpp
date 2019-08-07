//https://www.acmicpc.net/problem/1922
/*풀이 :
크루스칼 알고리즘을 이용해서
정점에서 정점으로 가는 경로를 비용이 최소인 순서로 정렬한다.
그리고 union_find를 이용해서 사이클이 생기지 않으면 
그 경로의 비용을 더한다.*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int parent[1001];
struct point
{
	int x, y, dis;
};
bool cmp(const point& a, const point& b)
{
	return a.dis < b.dis;
}
int getParent(int x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = getParent(parent[x]);
}
void unionParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}
int find(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if (a == b)
		return 1;
	else
		return 0;
}
int main()
{
	ios_base::sync_with_stdio(0);
	vector<point> v;
	int n,m;
	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}
	for (int j = 0; j < m; j++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ a,b,c });
	}
	int sum = 0;
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++)
	{
		if (!find(v[i].x , v[i].y ))
		{
			sum += v[i].dis;
			unionParent(v[i].x , v[i].y );
		}
	}
	cout << sum;
	return 0;
}

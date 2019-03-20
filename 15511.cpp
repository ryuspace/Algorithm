//https://www.acmicpc.net/problem/15511
//풀이 : union-find 나의 적들들은 같은 팀이여야해 근데 적들의 부모가 내 부모가 나온다면..? 모순
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v[1000001];
int parent[1000001];

int find(int a)
{
	if (a == parent[a])
	{
		return a;
	}
	return parent[a] = find(parent[a]);
}

bool merge(int num,int a, int b)
{

	if (find(a) == find(num) || find(b) == find(num))
	{
		return true;
	}
	a = find(a);
	b = find(b);
	parent[a] = b;
	return false;
}
int main()
{
	
	ios_base::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{	
		parent[i] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < v[i].size(); j++) 
		{
			if (merge(i,v[i][j - 1], v[i][j]))
			{
				cout << "IMPOSSIBLE";
				exit(0);
			}

		}
	}
	cout << "POSSIBLE";
	return 0;
}

//https://www.acmicpc.net/problem/1765
/*풀이 : 친구 관계면 union 해주고 적 관계면 내 적과 적을 union 해준다.*/
#include <iostream>
#include <algorithm>

using namespace std;

int e[1001];
int parent[1001];
int find(int a)
{
	if (a == parent[a])
		return a;
	return parent[a] = find(parent[a]);
}

void unionn(int a, int b)
{
	a = find(a);
	b = find(b);

	parent[a] = b;
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
	for (int i = 0; i < m; i++)
	{
		char a;
		int b, c;
		cin >> a >> b >> c;
		if (a == 'E')
		{
			if (e[b] != 0)
			{
				unionn(e[b], c);
			}
			if (e[c] != 0)
			{
				unionn(e[c], b);
			}
			e[b] = c;
			e[c] = b;

		}
		else
		{
			unionn(b, c);
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i == find(i))
		{
			cnt++;
		}
	}
	cout << cnt;
	
	return 0;
}

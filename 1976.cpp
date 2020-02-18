//https://www.acmicpc.net/problem/1976
/*풀이 :
처음에 브루트 포스로 할라고 했는데 생각해내기가 좀 어렵다. Union Find를 이용해서 시작 도시를 기준으로 나머지 도시와 parent가 같은지 체크하면 끝.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
int n, m;
int parent[201];


int findd(int a)
{
	if (a == parent[a])
		return a;
	return a = findd(parent[a]);
}
void uni(int a, int b)
{
	a = findd(a);
	b = findd(b);
	if (a < b)
	{
		parent[b] = a;
	}
	else
	{
		parent[a] = b;
	}
}
int main(void)
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int a;
			cin >> a;
			if (a == 1)
			{
				uni(i, j);
			}
		}
	}
	int a;
	cin >> a;
	for (int i = 1; i < m; i++)
	{
		int b;
		cin >> b;
		if (parent[findd(a)] != parent[findd(b)])
		{
			cout << "NO" << '\n';
			exit(0);
		}
	}
	cout << "YES";
	return 0;
}

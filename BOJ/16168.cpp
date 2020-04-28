//https://www.acmicpc.net/problem/16168
/*풀이 : 우선 그래프가 1개가 아니면 무조건 안된다. 그래프가 1개라면
오일러 경로를 이용해 한붓 그리기가 가능한지 체크한다.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int degree[3001];
int parent[3001];

int find(int a)
{
	if (a == parent[a])
		return a;
	return a = find(parent[a]);
}
void Union(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		parent[i] = i;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		degree[a]++;
		degree[b]++;
		Union(a, b);
	}
	for (int i = 2; i <= n; i++)
	{
		if (find(i) != find(i-1))
		{
			cout << "NO";
			exit(0);
		}
	}
	int h = 0;
	for (int i = 1; i <= n; i++)
	{
		if (degree[i] % 2 == 1)
			h++;
	}
	if (h == 2 || h == 0)
		cout << "YES";
	else
		cout << "NO";
	return 0;

}

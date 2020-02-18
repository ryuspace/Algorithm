//https://www.acmicpc.net/problem/1976
/*풀이 :
플로이드 워셜 방법으로 모든 정점에서 정점간에 최단거리를 구하고 여행 경로에서 각 경로를 갈 수 있는지 체크한다.
포인트 : 같은 지점으로 가는 경로는 가중치가 무조건 0이다. 조심..
*/
#include <iostream>
#include <algorithm>

using namespace std;

int arr[201][201];
int go[1001];
int main(void)
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			arr[i][j] = 1e9;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int a;
			cin >> a;
			if (a == 1)
			{
				arr[i][j] = 1;
			}
			if (i == j)
			{
				arr[i][j] = 0;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int r = 1; r <= n; r++)
			{
				if (arr[j][r] > arr[j][i] + arr[i][r])
				{
					arr[j][r] = arr[j][i] + arr[i][r];
				}
			}
		}
	}

	for (int i = 1; i <= m; i++)
	{
		cin >> go[i];
	}
	for (int i = 1; i <= m - 1; i++)
	{
		if (arr[go[i]][go[i + 1]] >= 1e9)
		{

			cout << "NO" << '\n';
			exit(0);
		}
	}
	cout << "YES" << '\n';
	return 0;
}

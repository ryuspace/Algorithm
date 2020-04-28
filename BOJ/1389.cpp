//https://www.acmicpc.net/problem/1389
/*풀이 : n이 작으면 간단한 플로이드 와샬 알고리즘을 사용한다.
플로이드 와샬 알고리즘 : 모든 정점에서 모든 정점으로 가는 최단 경로.
방법은 어떤 정점에서 어떤 정점으로 가기 위해 모든 정점을 거쳐봐서 최단 경로를 찾는다
시간복잡도 O(n^3)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int arr[101][101];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	fill(&arr[0][0], &arr[0][0] + (101) * (101), 1e9);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int r = 1; r <= n; r++)
			{
				if (arr[j][i] + arr[i][r] < arr[j][r])
				{
					arr[j][r] = arr[j][i] + arr[i][r];
				}
			}
		}
	}
	int minn = 1e9;
	int idx = 0;
	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		for (int j = 1; j <= n; j++)
		{
			if (i != j)
			{
				sum += arr[i][j];
			}
		}
		if (minn > sum)
		{
			minn = sum;
			idx = i;
		}
	}
	cout << idx;
	return 0;
}


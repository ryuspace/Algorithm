//https://www.acmicpc.net/problem/17208
/*풀이 : 주문을 넣어본다. 이전에 나왔던 주문 이후에 넣을 수 있는지 배열에 체크.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int arr[301][301];
int n, m, k;
int maxx = 0;
void go(int a, int b)
{
	int brr[301][301] = { 0, };
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (arr[i][j] != 0 && i + a <= m && j + b <= k)
			{
				if (arr[i + a][j + b] < arr[i][j] + 1)
				{
					arr[i + a][j + b] = 0;
					brr[i + a][j + b] = arr[i][j] + 1;
					maxx = max(maxx, brr[i + a][j + b]);
				}
			}
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			arr[i][j] += brr[i][j];
		}
	}
	if (a <= m && b <= k)
	{
		arr[a][b] = 1;
		maxx = max(maxx, arr[a][b]);
	}

}
int main(void)
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		go(a, b);
	}
	cout << maxx;
	return 0;
}

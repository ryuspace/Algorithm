//https://www.acmicpc.net/problem/14890
/*풀이 : 이미 경사로인 곳은 visit 배열로 체크해주자!
또 어디서 경사로를 놓을때 이미 경사로이면 pass~~
열체크할때는 그냥 원래 배열의 행 열을 돌려서
평소처럼 행,열 검사하면 된다.*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int a[101][101];
int b[101][101];
int n, l;
int ans = 0;
void sol(int row, int a[101][101])
{
	bool visit[101][101];
	memset(visit, false, sizeof(visit));
	int temp = a[row][0];
	for (int i = 0; i < n; i++)
	{
		if (abs(a[row][i] - temp) > 1)
			return;
		if (temp > a[row][i])
		{
			int cnt = 0;
			int num = a[row][i];
			for (int j = i; j <= l + i-1; j++)
			{
				if (j >= n)
					break;
				if (visit[row][j])
					return;
				if (a[row][j] == num)
				{
					cnt++;
					visit[row][j] = true;
				}
			}
			if (cnt != l)
				return;
			i = l + i-1;
			if (i >= n)
				break;
		}
		else if (temp<a[row][i])
		{
			int cnt = 0;
			int num = temp;
			for (int j = i-1; j > i-1-l; j--)
			{
				if (j < 0)
					break;;
				if (visit[row][j])
					return;
				if (a[row][j] == num)
				{
					cnt++;
					visit[row][j] = true;
				}
			}
			if (cnt != l)
				return;
		}
		temp = a[row][i];
	}
	ans++;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> l;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			b[j][i] = a[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		sol(i, a);
		sol(i, b);
	}
	cout << ans;
	return 0;
}

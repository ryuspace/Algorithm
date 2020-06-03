/*2112번 보호 필름
풀이 : dfs를 이용해 약품을 주입할 위치를 뽑고 맵을 탐색해 성능검사가 통과되는지 파악한다.
현재 약품을 주입한 갯수의 최소보다 많은 갯수는 탐색할 필요가 없다.
*/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int t;
int arr[14][21];
bool visit[14];
int mini = 1e9;
int d, w, k;

bool play()
{
	for (int j = 0;j < w;j++)
	{
		int maxx = 0;
		int cnt = 1;
		int me = arr[0][j];
		for (int i = 1;i < d;i++)
		{
			if (arr[i][j] == me)
			{
				cnt++;
			}
			else
			{
				maxx = max(maxx, cnt);
				cnt = 1;
			}
			me = arr[i][j];
		}
		maxx = max(maxx, cnt);
		if (maxx < k)
			return false;
	}
	return true;
}
void color(int idx, int type)
{
	for (int i = 0;i < w;i++)
	{
		arr[idx][i] = type;
	}
}
void dfs(int idx,int cnt)
{
	if (mini <= cnt)
		return;

	if (cnt <= d)
	{
		if (play())
		{
			mini = min(mini, cnt);
		}
	}
	if (cnt == d)
		return;
	for (int i = idx;i < d;i++)
	{
		if (!visit[i])
		{
			int tmp[21];
			visit[i] = true;
			for (int j = 0;j < w;j++)
			{
				tmp[j] = arr[i][j];
			}
			for (int j = 0;j <=1;j++)
			{
				color(i, j);
				dfs(i, cnt + 1);
			}

			visit[i] = false;
			for (int j = 0;j < w;j++)
			{
				arr[i][j] = tmp[j];
			}
		}
	}
}
int main()
{
	//freopen("Test.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	for (int q = 1;q <= t;q++)
	{
		mini = 1e9;
		cin >> d >> w >> k;
		for (int i = 0;i < d;i++)
		{
			for (int j = 0;j < w;j++)
			{
				cin >> arr[i][j];
			}
		}
		dfs(0, 0);
		cout << "#" << q << " " << mini << '\n';
	}
	return 0;
}

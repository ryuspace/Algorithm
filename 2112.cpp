/*2112번 수영장
풀이 : dfs를 이용해 약품을 주입할 위치를 뽑고 맵을 탐색해 성능검사가 통과되는지 파악한다.
현재 약품을 주입한 갯수의 최소보다 많은 갯수는 탐색할 필요가 없다.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int t, d, w, k;
int arr[14][21];
bool visit[14];
//0은 A 1은 B;
int res = 1e9;

bool check()
{
	for (int i = 0; i < w; i++)
	{
		bool flag = false;
		int a = 0, b = 0;
		for (int j = 0; j < d; j++)
		{
			if (arr[j][i] == 0)
			{
				a++;
				b = 0;
			}
			else
			{
				b++;
				a = 0;
			}
			if (a >= k || b >= k)
			{
				flag = true;
				break;
			}
		}
		if (!flag)
			return false;
	}
	return true;
}
void magic(int idx,int hi)
{
	for (int i = 0; i < w; i++)
	{
		arr[idx][i] = hi;
	}
}
void dfs(int idx,int cnt)
{
	if (idx >= d || cnt >= res)
	{
		return;
	}
	int tmp[21] = { 0, };
	
	visit[idx] = true;
	for (int r = 0; r < w; r++)
	{
		tmp[r] = arr[idx][r];
	}
	for (int j = 0; j < 2; j++)
	{
		magic(idx, j);
		if (check())
		{
			res = min(res, cnt + 1);
		}
		dfs(idx + 1, cnt + 1);
	}
	visit[idx] = false;
	for (int r = 0; r < w; r++)
	{
		arr[idx][r]= tmp[r];
	}

	dfs(idx + 1, cnt);
}
int main()
{
	freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	for (int r = 1; r <= t; r++)
	{
		res = 1e9;
		cin >> d >> w >> k;
		for (int i = 0; i < d; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> arr[i][j];
			}
		}
		if (check())
			res = 0;
		else
			dfs(0, 0);
		cout << "#" << r << " " << res << '\n';
	}
	
	return 0;
}

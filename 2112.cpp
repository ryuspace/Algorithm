/*2112번 수영장
풀이 : dfs를 이용해 약품을 주입할 위치를 뽑고 맵을 탐색해 성능검사가 통과되는지 파악한다.
현재 약품을 주입한 갯수의 최소보다 많은 갯수는 탐색할 필요가 없다.
*/
#include<iostream>
#include<algorithm>
#include <cstring>
int t;
int d, w, k;
int arr[14][21];
bool visit[14];
using namespace std;

bool check()
{
	for (int i = 0; i < w; i++)
	{
		int cntt = 0;
		bool flag = false;
		int num = arr[0][i];
		for (int j = 0; j < d; j++)
		{
			if (arr[j][i] == num)
			{
				cntt++;
			}
			else
			{
				if (cntt >= k)
				{
					flag = true;
					break;
				}
				else
				{
					cntt = 1;
					num = arr[j][i];
				}
			}

		}
		if (cntt >= k)
		{
			flag = true;
		}
		if (!flag)
			return false;
	}
	return true;
}
int minn = 1e9;
void magic(int idx, int alpa, int cnt)
{
	for (int i = 0; i < w; i++)
	{
		arr[idx][i] = alpa;
	}
	if (check())
	{
		minn = min(minn, cnt);
	}
}
void dfs(int idx, int cnt)
{
	int tmp[14][21];
	if (idx >= d || cnt > k || cnt >= minn)
	{
		return;
	}
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < w; j++)
		{
			tmp[i][j] = arr[i][j];
		}
	}
	dfs(idx + 1, cnt);//안뿌림..
	for (int i = 0; i < 2; i++)
	{
		magic(idx, i, cnt);
		if (minn <= cnt)
			return;
		dfs(idx + 1, cnt + 1);
	}
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < w; j++)
		{
			arr[i][j] = tmp[i][j];
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	//freopen("t.txt", "r", stdin);
	cin >> t;
	for (int r = 1; r <= t; r++)
	{
		memset(visit, 0, sizeof(visit));
		minn = 1e9;
		cin >> d >> w >> k;
		for (int i = 0; i < d; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> arr[i][j];
			}
		}
		if (check())
		{
			cout << "#" << r << " " << 0 << '\n';
		}
		else
		{
			dfs(0, 1);
			cout << "#" << r << " " << minn << '\n';
		}


	}

	return 0;
}

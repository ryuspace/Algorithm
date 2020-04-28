//https://www.acmicpc.net/problem/18808
/*풀이 : 전형적인 시뮬레이션이지만 
can 함수의 효율성에 따라 시간이 갈렸다.
처음에는 스티커를 붙여봤는데 스티커의 구성요소를 전부 붙이는지 여부를 따졌는데 시간이 꽤 들었다.
스티커 붙여볼 위치가 공간이 넘어가는지 체크를 하면 상당히 많이 커트가 된다.
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef pair<int, int> pii;
int n, m, k;
int sticker[101][11][11];
int map[41][41];
pii idx[101];
int sticker_cnt[101];
int sum;
int tmp[11][11];
void rotate(int num)
{
	int r = idx[num].first;
	int c = idx[num].second;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			tmp[i][j] = sticker[num][i][j];
			sticker[num][i][j] = 0;
		}
	}
	
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < r; j++)
		{
			sticker[num][i][j] = tmp[r-1 - j][i];
		}
	}
	idx[num].first = c;
	idx[num].second = r;
}
bool can(int r,int c,int num)
{

	if (r + idx[num].first >n || c + idx[num].second > m)//범위 초과!
		return false;

	for (int i = r; i < r+ idx[num].first; i++)
	{
		for (int j = c; j < c+ idx[num].second; j++)
		{
			if (map[i][j] == 1 && sticker[num][i - r][j - c] == 1)
				return false;
		}
	}

	return true;
}
void on(int r, int c, int num) {
	for (int i = r; i < r + idx[num].first; i++)
	{
		for (int j = c; j < c + idx[num].second; j++)
		{
			if (map[i][j] == 0 && sticker[num][i - r][j - c] == 1)
				map[i][j] = 1;
		}
	}

}
int maxi = 0;
bool go(int cnt)
{
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (can(i, j, cnt))
			{
				on(i, j, cnt);
				return true;
			}

		}
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	for (int t = 0; t < k; t++)
	{
		int sum = 0;
		cin >> idx[t].first >> idx[t].second;
		for (int i = 0; i < idx[t].first; i++)
		{
			for (int j = 0; j < idx[t].second; j++)
			{
				cin >> sticker[t][i][j];
				if (sticker[t][i][j] == 1)
				{
					sum++;
				}
			}
		}
		sticker_cnt[t] = sum;
		for (int i = 0; i < 4; i++)
		{
			if (go(t))
			{
				maxi += sum;
				break;
			}
			rotate(t);
		}


	}
	cout << maxi;
	return 0;
}

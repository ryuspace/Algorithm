/* 4012번 요리사
풀이 : n/2개의 가능한 숫자를 고르고 남은 n/2 개는 선택되지 않은 것 고르는게 중요하다.
한 그룹 내에서는 선택된 숫자 3개가 순서가 중요하지 않으므로
오름차순으로 수를 선택해 줘서 시간을 더 줄인다.
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int n, m;
int t;
int arr[17][17];
int jemul[17];
bool visit[17];
int cook()
{
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 0; j < n / 2; j++)
		{
			sum1 += arr[jemul[i]][jemul[j]];
		}
	}
	for (int i = n / 2; i < n; i++)
	{
		for (int j = n / 2; j < n; j++)
		{
			sum2 += arr[jemul[i]][jemul[j]];
		}
	}
	return abs(sum1 - sum2);
}
int minn = 1e9;
void dfs(int cnt,int idx)
{
	if (cnt == n/2)
	{
		int idxx = n / 2;
		for (int i = 0; i < n; i++)
		{
			if (!visit[i])
			{
				jemul[idxx] = i;
				idxx++;
			}
		}
		minn=min(cook(),minn);
		return;
	}
	for (int i = idx; i < n; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			jemul[cnt] = i;
			dfs(cnt + 1,i+1);
			visit[i] = false;
		}

	}

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> t;
	for (int r = 1; r <= t; r++)
	{
		minn = 1e9;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
			}
		}
		dfs(0,0);
		cout <<"#"<<r<<" "<< minn << '\n';
	}
	return 0;

}

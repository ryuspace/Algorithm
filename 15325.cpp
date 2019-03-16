//https://www.acmicpc.net/problem/15325
/*풀이 :2^40은 시간초과 나므로 2^20으로 나눈다. 
H와 K를 담은 벡터를 반으로 나누고 처음 반은 그 인덱스에서 끝나는 가능한 모든 경우의 K의 합을
인덱스 배열의 벡터에 담고 남은 반은 그 인덱스에서 시작하는 가능한 모든 경우의 K의 합을
인덱스 배열의 벡터에 담는다.그리고 앞의 반, 뒤의 반을 기준으로 탐색하는데 
앞의 인덱스가 뒤의 인덱스보다 작은 경우 K 이상의 코인을 먹는 경우를 찾아준다.
(lower_bound) 이용.*/
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int,ll> pil;
vector <pil> v;
vector <ll> hi[41];

int n;
ll k;
ll a, b;
ll res = 0;
void dfs1(int idx,int past,ll cnt, ll sum)
{
	if (cnt == 0)
	{
		hi[idx].push_back(sum);
		if (sum >= k)
			res++;
		return;
	}
	if (past >= v[cnt-1].first)
	{
		dfs1(idx, v[cnt-1].first, cnt - 1, sum + v[cnt-1].second);

	}
	dfs1(idx, past, cnt - 1, sum);
}

void dfs2(int idx,int past,ll cnt, ll sum)
{
	if (cnt == n-1)
	{
		hi[idx].push_back(sum);
		if (sum >= k)
			res++;
		return;
	}
	if (past <= v[cnt+1].first)
	{
		dfs2(idx, v[cnt+1].first, cnt + 1, sum + v[cnt+1].second);

	}
	dfs2(idx, past, cnt + 1, sum);
}

int main()
{

	scanf("%d %lld", &n, &k);

	for (int i = 0; i < n; i++)
	{
		scanf("%d %lld", &a, &b);
		v.push_back({ a,b });
	}
	//절반은 이 인덱스에서 끝나는 경우, 절반은 이 인덱스에서 시작하는 경우
	for (int i = 0; i < n / 2; i++)
	{
		dfs1(i,v[i].first, i, v[i].second);
	}
	for (int i = n/2; i < n; i++)
	{
		dfs2(i, v[i].first, i, v[i].second);
	}
	for (int i = n/2; i < n; i++)
	{
		sort(hi[i].begin(), hi[i].end());
	}
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 0; j < hi[i].size(); j++)
		{
			for (int r = n / 2; r < n; r++)
			{
				if (v[i].first <= v[r].first)
				{
					res += hi[r].end() -
						lower_bound(hi[r].begin(), hi[r].end(), k - hi[i][j]);
				}
			}
		}
	}
	printf("%lld", res);
	return 0;
}

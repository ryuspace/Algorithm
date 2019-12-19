//https://www.acmicpc.net/problem/1114
/*풀이 : 부분 부분 자르는 거 이 코드를 참고하자..*/
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int L, K, C;
int cut[10002];

bool isPossible(int log)
{
	int k;
	int start = L, cnt = 0;
	int diff = 0;
	for (k = K - 1; k >= 0; k--)
	{
		//k+1 지점에서 자를거야!
		diff += cut[k + 1] - cut[k];
		if (diff > log)
		{
			diff = cut[k + 1] - cut[k];//이전 부분은 log보다 작은게 확실 하니깐 내 부분만 자르자!
			cnt++;
			if (diff > log)//애초에 log로 자를 수 없는 경우니깐 false로 리턴.
			{
				return false;
			}
		}
	}
	return cnt <= C;
}
int main(void)
{
	scanf("%d %d %d", &L, &K, &C);
	for (int k = 1; k <= K; k++) scanf("%d", &cut[k]);
	cut[0] = 0, cut[++K] = L;
	sort(cut, cut + K + 1);
	int ans1 = (int)2e9;
	int l = 0, r = (int)(1e9 + 1);
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (isPossible(mid))
		{
			ans1 = min(ans1, mid);
			r = mid - 1;
		}
		else l = mid + 1;
	}
	int diff = 0, cnt = 0;
	int idx = K;
	for (int k = K - 1; k >= 0; k--)
	{
		diff += cut[k + 1] - cut[k];
		if (diff > ans1)
		{
			cnt++;
			diff = cut[k + 1] - cut[k];
			idx = k + 1;
		}
	}
	if (cnt < C) idx = 1;//이 부분 주의 C보다 적은 경우로 자르는 걸 수도 있어!
	printf("%d %d\n", ans1, cut[idx]);
	return 0;
}

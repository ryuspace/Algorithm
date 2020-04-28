//https://www.acmicpc.net/problem/16987
/*풀이 : dfs를 이용해 첫번째 계란부터 마지막 계란 까지
깨뜨릴 수 있는 모든 계란의 경우의 수를 만들어 최대값을 구한다.*/
#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
int n;
pii arr[9];
int res = 0;
void dfs(int now,int cnt)
{
	if (cnt == n)//마지막 계란 까지 도착
	{
		int cntt = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i].first <= 0)
				cntt++;
		}
		res = max(res, cntt);
		return;
	}
	int cnt2 = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[now].first <= 0)//내 손에 있는게 깨졌으면 어떤 계란도 깨뜨릴 수 없다. 다음 계란으로 넘어가자.
		{
			dfs(now + 1, cnt + 1);
		}
		else if (i != now && arr[i].first > 0)//어떤 하나를 깨뜨리면 다음 계란으로 넘어가자.
		{
			arr[now].first -= arr[i].second;
			arr[i].first-= arr[now].second;
			dfs(now + 1, cnt + 1);
			arr[now].first += arr[i].second;
			arr[i].first+= arr[now].second;
			cnt2++;
		}
	}
	if (cnt2 == 0) {//손에 계란은 있지만 깨뜨릴 수 있는 계란이 없는 경우.. 다음 계란으로 넘어가자.
		dfs(now + 1, cnt + 1);
	}
	
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;
	dfs(0,0);
	cout << res;
	return 0;
}

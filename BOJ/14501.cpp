//https://www.acmicpc.net/problem/14501
/*풀이 : 마지막 날이 오기 전까지 상담이 가능한 모든 경우를 구해서 최댓값을 구한다.*/
#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
int n;
pii arr[16];
int maxx = 0;
void dfs(int cnt, int sum)
{
	maxx = max(sum, maxx);
	if (cnt == n)
		return;
	if (cnt + 1 <= n)
		dfs(cnt + 1, sum);
	if (cnt + arr[cnt].first <= n)
		dfs(cnt + arr[cnt].first, sum + arr[cnt].second);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t, p;
		cin >> t >> p;
		arr[i] = { t,p };
	}
	dfs(0, 0);
	cout << maxx;
	return 0;
}

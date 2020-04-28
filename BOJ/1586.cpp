//https://www.acmicpc.net/problem/15486
/*풀이 : n이 1,500,000 이므로 O(n)에는 끝내야 한다. 그러기 위해 dp를 사용했다.
dp[i] : i날까지의 가능한 상담을 다 했다.
내가 지금 상담하면 현재 + 상담일수 날에 상담이 끝나는데 기존에 이 날에 있던 수익 vs
현재까지의 최고수익 + 현재 상담해서 도착하는 날의 수익을 더함. 이 둘 중 최대값을 현재 상담해서 도착하는 날의 dp배열 값으로 갱신해준다. */
#include <iostream>
#include <algorithm>

using namespace std;
int dp[1500001];
int main()
{
	ios_base::sync_with_stdio(0);
	int maxx = 0;
	int maxx2 = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		maxx = max(dp[i], maxx);
		if (i + a <= n)
			dp[i + a] = max(dp[i + a], maxx + b);
		maxx2 = max(dp[i + a], maxx2);
	}
	cout << maxx2;
	return 0;
}

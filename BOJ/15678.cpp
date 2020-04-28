//https://www.acmicpc.net/problem/15678
/*풀이 : dp문제.. 이번에 넣을 숫자가 범위 밖이면 앞에있는 애 빼주고 새로 들어갈 숫자가
뒤에서부터 셌을때 더 크다면 계속 빼준다..*/
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

deque < pair<long long int, int> > dq;
long long int dp[100001];
int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int n, d;
	cin >> n >> d;
	for (int i = 0; i < n; i++)
	{
		long long int a;
		cin >> a;
		while (!dq.empty() && dq.front().second < i - d) {
			dq.pop_front();
		}
		if (!dq.empty())
		{
			dp[i] = max(a, dq.front().first + a);
		}
		else
		{
			dp[i] = a;
		}

		while (!dq.empty() && dq.back().first <= dp[i]) {
			dq.pop_back();
		}
		dq.push_back({ dp[i],i });
	}
	long long int maxx = -1e18;
	for (int i = 0; i < n; i++)
	{
		maxx = max(dp[i], maxx);
	}
	cout << maxx;
	return 0;
}

//https://www.acmicpc.net/problem/18291
/*풀이 : 고속 거듭 제곱 알고리즘. 원래는 O(n) 걸리는거 O(log(N))으로 줄여줌
2^n이면 n이 짝수 -> 2^(n/2)*2^(n/2)
        n이 홀수 -> 2^((n-1)/2)*2^((n-1)/2)
*/
#include <iostream>
#include <algorithm>

using namespace std;
#define MOD 1000000007

long long calc(int x, int y)
{
	if (y == 0)
		return 1;

	else if (y % 2 == 0)
	{
		long long num = calc(x, y / 2) % (MOD);
		return ((num % (MOD))* (num % (MOD)))%(MOD);

	}
	else
	{
		long long num = calc(x, (y-1)/ 2) % (MOD);
		return ((num % (MOD)) * (num % (MOD))*x) % (MOD);

	}
}


int main(void)
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		if (n == 1 || n==2)
		{
			cout << 1 << '\n';
		}
		else
		{
			cout << calc(2, n - 2) << '\n';
		}
	}
	return 0;
}

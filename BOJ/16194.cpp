//https://www.acmicpc.net/problem/16194
/*풀이 : n번째 카드를 직접 사는 것과 다른 카드를 조합해서 사는 것 중에 최소인 것을
계속 비교한다.. i-1번째에서 첫번째 카드를 산다.. i-2번째에서 두번째 카드를 산다..*/
#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001];
int memo[1001];
int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];

	}
	memo[0] = 1e9;
	memo[1] = arr[1];
	for (int i = 2; i <= n; i++)
	{
		memo[i] = arr[i];
		for (int j = 1; j <= i; j++)
		{
			memo[i] = min(memo[i], memo[i - j]+arr[j]);
		}
	}
	cout << memo[n];

	return 0;
}

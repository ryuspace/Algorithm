//https://www.acmicpc.net/problem/17626
/*풀이 : 완탐으로 어떻게 시도해볼라고 했지만 역시 ㅎ dp로 해야겠다는 생각이 들었다.
dp배열 정의는 나까지 몇개의 제곱수의 갯수로 이루어졌는지이다.
dp[j-i*i]를 하면 현재 i*i의 제곱수를 포함할건데 그 이전에 만든 최소 갯수....
*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int dp[50001];
int arr[225];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= sqrt(n); i++)
		arr[i] = i * i;
	fill(&dp[0], &dp[n+1],1e9);
	dp[0] = 0;

	for (int i = 1; i <= sqrt(n); i++)
	{
		for (int j = i*i; j <= n; j++)
		{
			dp[j] = min(dp[j], dp[j - i*i] + 1);
		}
	}
	cout << dp[n];
	return 0;
}

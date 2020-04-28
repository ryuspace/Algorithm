/*풀이 : dp[x][y] x는 앞에 숫자 지우기 찬스 사용 여부, y는 현재의 나 */
#include <iostream>
#include <algorithm>

using namespace std;

long long int dp[2][200001];
long long int arr[200001];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long int maxx = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	dp[0][0] = 1;
	dp[1][0] = 1;

	for (int i = 1; i < n; i++)
	{
		dp[0][i] = dp[1][i] = 1;
		if (arr[i - 2] < arr[i])
		{
			dp[0][i] = max(dp[0][i], dp[1][i - 2] + 1);//지우기 찬스를 이번에 쓸 것이다 . 그럼 데려올 애는 찬스를 쓴 적이 없는 친구여야 한다.
		}
		if (arr[i - 1] < arr[i])
		{
			dp[1][i] = dp[1][i - 1] + 1;//찬스를 안 썼으니 안 쓴 친구를 그대로 끌어다 온다.
			dp[0][i] = max(dp[0][i], dp[0][i - 1] + 1);//이미 찬스를 쓴 상태. 앞에 있는 친구중 찬스 쓴 애를 그대로 끌어다 온다.
		}
	}
	for (int i = 0; i < n; i++)
	{
		long long int maxx2 = max(dp[0][i], dp[1][i]);
		maxx = max(maxx, maxx2);
	}
	cout << maxx;

	return 0;
}

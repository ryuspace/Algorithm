//https://www.acmicpc.net/problem/2616
/*풀이 : 올해 초는 아예 이해하지 못 하고 넘어간 문젠데 지금은 금방 보고 이해해서 기분이 좋다.
dp[x][y] : x번째의 소형기관차를 몰건데 y번까지 몰거다.. 이때 가장 많이 수용할 수 있는 손님의 합.
이번 소형기관차를 모는 경우와 몰지 않는 경우를 나눠서 dp배열을 갱신할 수 있다.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int arr[50001];
int dp[4][50001];
int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int n, c;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++)
	{
		arr[i + 1] = arr[i + 1] + arr[i];//손님의 부분 합을 쉽게 구하기 위해 하는 작업.
	}
	cin >> c;

	for (int i = 1; i <= 3; i++)
	{
		for (int j = i * c; j <= n; j++)
		{
			dp[i][j] = max(dp[i][j-1], arr[j] - arr[j - c] + dp[i - 1][j - c]); //dp[i][j-1]인 이유는 j번째 소형기관차를 선택해서 끄는게 이득이냐 아니면 선택하지 않고 그 이전까지의 결과값을 선택하는게 이득이냐 체크
		}
	}

	cout << dp[3][n];
	return 0;
}

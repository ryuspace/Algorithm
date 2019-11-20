//https://www.acmicpc.net/problem/2618
/*풀이 : 경찰차가 올 수 있는 모든 경우의 수를 따지면 2^1000가지 이므로 당연히 시간 안에 AC가 안된다. 
dp인 것 까진 감 잡았지만 점화식을 세우기가 어려웠다. 
결국 힌트를 얻고 문제를 해결하였다. 여태까지 풀었던 dp와 느낌이 사뭇 달랐다.
자세한 코드 설명은 주석을 통해 하겠습니다.
*/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
typedef pair<int, int> pii;

int n, m;
int dp[1004][1004];//dp[x][y] : 경찰차 1번이 x위치에 있고 2번이 y위치에 있을 때 거리의 합의 최소
int choose[1004][1004];//choose[x][y] : 경찰차 1번이 x위치에 있고 2번이 y위치에 있는데 둘 중 누가 다음 위치로 갔는지 표시
pii now[1004];

int dis(pii& a, pii& b)
{
	return abs(b.second - a.second) + abs(b.first - a.first);
}
int solve(int x, int y)//경찰차 1이 x에 있고 2가 y에 있을 때 next로 보낼 것이다.
{
	if (x == m + 1 || y == m + 1)
		return 0;//더 갈 곳이 없다.
	int next = max(x, y) + 1;//두 경찰차 중 가장 멀리있는 경찰차까지는 조사가 끝났다고 볼 수 있는 것이 포인트! 그래서 그 다음 인덱스가 다음 위치이다.
	if (dp[x][y] != -1)
		return dp[x][y];//이미 이 위치에 있을 때 최소를 구한 기록이 있으므로 불필요한 재귀는 pass!

	int a = solve(next, y) + dis(now[x], now[next]);//x를 next로 보낸다.
	int b = solve(x, next) + dis(now[y], now[next]);//y를 next로 보내본다.
	if (a < b)
	{
		dp[x][y] = a;
		choose[x][y] = 1;
	}
	else
	{
		dp[x][y] = b;
		choose[x][y] = 2;
	}
	//둘 중 작은 경우를 선택한다.
	return dp[x][y];

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	now[0] = { 1,1 };
	now[1] = { n,n };
	memset(dp, -1, sizeof(dp));
	for (int i = 2; i < m + 2; i++)
	{
		int a, b;
		cin >> a >> b;
		now[i] = make_pair(a, b);
	}
	int k1 = 0;
	int k2 = 1;
	cout << solve(0, 1) << '\n';
	while (!(k1 == m + 1 || k2 == m + 1))
	{
		cout << choose[k1][k2] << '\n';
		if (choose[k1][k2] == 1)
		{
			k1 = max(k1, k2) + 1;
		}
		else
		{
			k2 = max(k1, k2) + 1;
		}

	}
}

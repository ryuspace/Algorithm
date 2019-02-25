//https://www.acmicpc.net/problem/2096
/*이전단계에서 어디서 내려올 수 있는지 .. 단순 dp문제 하지만 메모리 초과가 나므로
이전 값을 계속 재사용한다.*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int dp1[2][3];
int dp2[2][3];
int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		dp1[1][0] = max(dp1[0][0], dp1[0][1])+a;
		dp1[1][1] = max(max(dp1[0][0], dp1[0][1]), dp1[0][2])+b;
		dp1[1][2] = max(dp1[0][1], dp1[0][2])+c;

		dp2[1][0] = min(dp2[0][0], dp2[0][1])+a;
		dp2[1][1] = min(min(dp2[0][0], dp2[0][1]), dp2[0][2])+b;
		dp2[1][2] = min(dp2[0][1], dp2[0][2])+c;
		for (int j = 0; j < 3; j++)
		{
			dp1[0][j] = dp1[1][j];
			dp2[0][j] = dp2[1][j];
		}
	}

	int Max = max(dp1[1][0], dp1[1][1]);
	int Min = min(dp2[1][0], dp2[1][1]);
	Max = max(Max, dp1[1][2]);
	Min = min(Min, dp2[1][2]);
	cout << Max << " "<<Min << '\n';
	return 0;
}

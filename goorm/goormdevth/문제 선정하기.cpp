//https://devth-preview.goorm.io/exam/53763/devth-preview-kor/quiz/1
/*풀이 :
백준의 앱 문제랑 비슷하다.
dp 배열 선언 :
dp[x][y] => x장까지 선택해서 나머지 y를 만들었다.
중복을 고려하기 조금 힘들었다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
#define MOD 1000000007
long long int dp[48][1001];

int n, k;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		long long int dp2[48][1001];
		for (int j = 2; j <= k; j++)
		{
			for (int r = 0; r < n; r++)
			{
				dp2[j][(r+i)%n] = dp2[j][(r+i)%n]%MOD+dp[j - 1][r]%MOD;
			}
		}
		dp[1][i] = 1;
		for (int j = 1; j <= k; j++)
		{
			for (int r = 0; r < n; r++)
			{
				if(dp[j][r]!=dp2[j][r] && dp2[j][r]!=0)
					dp[j][r] = dp2[j][r];
			}
		}
	}
	cout << dp[k][0]%MOD;
	return 0;
}

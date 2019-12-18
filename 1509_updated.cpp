//https://www.acmicpc.net/problem/1509
/*풀이 : 문쟈열의 중간을 잡아 양쪽으로 홀수 팰린드롬, 짝수 팰린드롬을 체크한다.
팰린드롬이면 이전 문자열까지의 최소 갯수와 현재 찾아낸 팰린드롬 (1) 더한 것과 기준 이전의 문자열의 최소 갯수와 비교를 해본다.
O(n^2)만에 해결이 가능하다.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int dp[2501];
string tmp;
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> tmp;
	fill(&dp[0], &dp[tmp.length()], 1e9);
	for (int i = 0; i < tmp.length(); i++)
	{
		//짝수개의 팰린드롬
		for (int j = 0; (i - j >= 0 && i + j + 1 < tmp.length()); j++)//항상 짝수개는 홀수개 일 때 보다 같은 turn이라도 더 뒤에 것의 팰린드롬까지 포함하고 있다.
		{

			if (tmp[i - j] == tmp[i + j + 1])
			{
				if (i - j - 1 < 0)
				{
					dp[i + j + 1] = 1;
				}
				else
				{
					dp[i + j + 1] = min(dp[i + j + 1], dp[i - j - 1] + 1);
				}
			}
			else
			{
				break;
			}
		}
		//홀수개의 팰린드롬
		for (int j = 0; (i - j >= 0 && i + j < tmp.length()); j++)
		{
			if (tmp[i - j] == tmp[i + j])
			{
				if (i - j -1< 0)
				{
					dp[i+j] = 1;
				}
				else
				{
					dp[i + j] = min(dp[i+j], dp[i-j-1]+1);
				}
			}
			else
			{
				break;
			}
		}
		
	}
	cout << dp[tmp.length() - 1];
	return 0;
}

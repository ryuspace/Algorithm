//https://www.acmicpc.net/problem/2240
/*풀이 : 현재 어떤 자두나무에 있고 이전에 어떤 자두나무에 있을 때 모든 상황을 고려해서 모든 상황 중
최대값을 현재 배열에 넣고 이를 반복한다.*/
#include <iostream>
#include <algorithm>

using namespace std;

int jadu[1002];
int memo[3][1002][32];//나무,시간,위치

int main()
{
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int t, w, ans = 0;
	cin >> t >> w;
	
	for (int i = 1; i <= t; i++)
	{
		cin >> jadu[i];
	}
	if (jadu[1] == 1)
	{
		for (int j = 0; j <= w; j++)
		{
			memo[1][1][j] = 1;
		}
	}
	memo[2][1][0] = 0;//처음에 자두는 1 위치에 있으니까 자두가 2에서 떨어지고 시간이 0이면 자두를 먹지 못한다
	if (jadu[1] == 2)
	{
		for (int j = 1; j <= w; j++)
		{
			memo[2][1][j] = 1;
		}
	}

	for (int i = 2; i <= t; i++)
	{
		for (int j = 0; j <= w; j++)
		{
			if (jadu[i] == 1)//나무 1에서 자두가 떨어진다. 	
			{
				memo[1][i][j] = max(memo[1][i][j], memo[1][i - 1][j] + 1);
				memo[1][i][j] = max(memo[1][i][j], memo[2][i - 1][j - 1] + 1);
				//현재 나는 자두나무 1에 있다. 
				//이전 상황에서 1에 있어서 자두를 얻는 경우, 
				//이전 상황에 2에 있어서 한번 옮기고 자두를 얻는 경우
				memo[2][i][j] = max(memo[2][i][j], memo[2][i - 1][j]);
				memo[2][i][j] = max(memo[2][i][j], memo[1][i - 1][j - 1]);
				//현재 나는 자두나무 2에 있다. 
				//이전 상황에서 2에 있어서 자두를 못 얻는 경우, 
				//이전 상황에 1에 있어서 한번 옮기고 자두를 못 얻는 경우
			}
			else//나무 2에서 자두가 떨어진다.
			{
				memo[1][i][j] = max(memo[1][i][j], memo[1][i - 1][j]);
				memo[1][i][j] = max(memo[1][i][j], memo[2][i - 1][j - 1]);
				//현재 나는 자두나무 1에 있다. 
				//이전 상황에서 1에 있어서 자두를 못 얻는 경우, 
				//이전 상황에 2에 있어서 한번 옮기고 자두를 못 얻는 경우

				memo[2][i][j] = max(memo[2][i][j], memo[2][i - 1][j] + 1);
				memo[2][i][j] = max(memo[2][i][j], memo[1][i - 1][j - 1] + 1);
				//현재 나는 자두나무 2에 있다. 
				//이전 상황에서 2에 있어서 자두를 얻는 경우, 
				//이전 상황에 1에 있어서 한번 옮기고 자두를 얻는 경우
			}
		}
	}

	for (int i = 0; i <= w; i++)
	{
		ans = max(ans, memo[1][t][i]);
		ans = max(ans, memo[2][t][i]);
	}
	cout << ans;

	return 0;
}

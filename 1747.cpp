//https://www.acmicpc.net/problem/1747
/*풀이 : 에라토스테네스의 체로 시간복잡도를 O(log(n)*n)으로 줄였따.. 하지만 더 줄일 수 있는 방법이
있다... 더 공부하자.. */
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

bool visit[1004001];
bool check(string tmp)
{
	for (int i = 0; i < ceil(tmp.length() / 2); i++)
	{
		if (tmp[i] != tmp[tmp.length() - 1 - i])
			return false;
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	visit[1] = true;
	int n;
	cin >> n;
	for (int i = 2; i <= 110; i++)
	{
		for (int j = n; j <= 1004000; j++)
		{
			if (!visit[j] && j % i == 0 && j != i)
			{
				visit[j] = true;
			}

		}
	}
	for (int j = n; j < 1004000; j++)
	{
		if (!visit[j])
		{
			if (check(to_string(j)))
			{
				cout << j;
				exit(0);
			}
		}
	}

	return 0;
}

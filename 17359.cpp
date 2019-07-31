//https://www.acmicpc.net/problem/17359
/*풀이 : dfs를 구현하는 것 보다 next_permutation을 사용하는 것이 더 빠르다.
기본적으로 전구묶음들의 바뀌는 횟수를 미리 저장해 놓고 전구묶음의 맨 앞과 맨 뒤를
모든 전구 묶음의 나열에서 바뀌는지 안 바뀌는지만 체크한다.*/
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string bulb[11];
int n,base = 0;
int jemul[11];
int minn = 1e9;
int main()
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> bulb[i];
	for (int i = 0; i < n; i++)
	{
		char start = bulb[i][0];
		for (int j = 1; j < bulb[i].length(); j++)
		{
			if (bulb[i][j] != start)
			{
				base++;
				start = bulb[i][j];
			}
		}
		jemul[i] = i;
	}
	do
	{
		int cnt = 0;
		for (int i = 0; i < n - 1; i++)
		{
			if (bulb[jemul[i]][bulb[jemul[i]].length() - 1] !=
				bulb[jemul[i + 1]][0])
			{
				cnt++;
			}
		}
		minn = min(minn, cnt+base);
	} while (next_permutation(jemul, jemul + n));
	cout << minn;
	return 0;
}

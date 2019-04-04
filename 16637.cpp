//https://www.acmicpc.net/problem/16637
/*풀이 : 현재 위치에 괄호가 있으면
여탯동안 더해온거,부호,괄호로 둘러싸인 식을 연산해주고..
그렇지 않으면 여탯동안 더해온가,부호,현재 숫자..*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int n;
bool use[20];
int su[20];
int bu[20];
string tmp;

long long int cal(long long int a, char b, long long int c)
{
	if (b == '+')
		return a + c;
	if (b == '-')
		return a - c;
	else
		return a * c;
}
long long int res = -1e9-1;
void dfs(bool flag,long long int one,char buho,long long int two,int now)
{
	if (now >= n - 1)
	{
		res = max(res, cal(one, buho, two));
		return;
	}
	if (flag == 0)
	{
		dfs(0, cal(one, buho, two), bu[now + 1], su[now + 2], now + 2);
		dfs(1, cal(one, buho, two), bu[now + 1], su[now + 2], now + 2);
	}
	else
	{
		dfs(0, one, buho, cal(two, bu[now + 1], su[now + 2]), now + 2);
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	cin >> tmp;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			su[i] = (tmp[i] - '0');
		else
			bu[i] = tmp[i];
	}
	dfs(0, 0, '+', su[0], 0);
	dfs(1, 0, '+', su[0], 0);
	cout << res;
	return 0;
}

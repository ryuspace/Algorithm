//https://www.acmicpc.net/problem/14888
/*풀이 : dfs를 이용하여 모든 가능한 연산자 순열을 만들어 전부 계산해 본다.
(n-1)*(n-2)*(n-3)*....1 번의 함수가 호출되므로 시간복잡도는 대략 n! .... (?!)*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
bool visit[11];
vector<int> su;
vector<int> bu;
vector<int> ans;
int n;
int minn = 1e9+1;
int maxx = -1e9-1;
void dfs(int cnt)
{
	if (cnt == n - 1)
	{
		int num = su[0];
		for (int i = 1; i < su.size(); i++)
		{
			if (ans[i - 1] == 0)
			{
				num += su[i];
			}
			else if (ans[i - 1] == 1)
			{
				num -= su[i];
			}
			else if (ans[i - 1] == 2)
			{
				num *= su[i];
			}
			else
			{
				num /= su[i];
			}
		}
		minn = min(num, minn);
		maxx = max(num, maxx);
		return;
	}
	for (int i = 0; i < bu.size(); i++)
	{
		if (visit[i] == false)
		{
			ans.push_back(bu[i]);
			visit[i] = true;
			dfs(cnt + 1);
			ans.pop_back();
			visit[i] = false;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		su.push_back(a);
	}
	for (int i = 0; i < 4; i++)
	{
		int a;
		cin >> a;
		for (int j = 0; j < a; j++)
		{
			bu.push_back(i);
		}
	}
	dfs(0);
	cout << maxx << '\n' << minn << '\n';
	return 0;
}

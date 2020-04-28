//https://www.acmicpc.net/problem/2503
/*풀이 : 숫자 세개를 완탐으로 정해놓고 주어진 조건들과 부합하는 지 체크한다.*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

struct point
{
	string num;
	int s, b;
};
int n;
bool visit[10];
int ans;
vector<point> hint;
void check(string tmp)
{
	for (int i = 0; i < hint.size(); i++)
	{
		int st = 0;
		int ba= 0;
		for (int j = 0; j < 3; j++)
		{
			for (int r = 0; r < 3; r++)
			{
				if (hint[i].num[j] == tmp[r])
				{
					if (j == r)
					{
						st++;
					}
					else
					{
						ba++;
					}
				}
			}
		}
		if (!(st == hint[i].s && ba == hint[i].b))
		{
			return;
		}
	}
	ans++;
}
void dfs(int cnt,string tmp)
{
	if (cnt == 3)
	{
		check(tmp);
		return;
	}
	for (int i = 1; i <= 9; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			char hi = i + '0';
			dfs(cnt + 1,tmp+hi);
			visit[i] = false;
		}
	}
}
int main()
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		hint.push_back({ to_string(a),b,c });
	}
	dfs(0,"");
	cout << ans;
	return 0;
}

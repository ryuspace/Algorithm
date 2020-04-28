//https://www.acmicpc.net/problem/17136
/*풀이 : 1이 있는 곳을 왼쪽 상단으로 맞춰서 붙이는게 가장 효율적인 방법이다. 그리고
5x5부터 차례대로 1이 있는 곳에 붙여본다.*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
int arr[11][11];
vector <pii> v;
bool visit[11][11];
int minn = 1e9;

void re(int num, pii idx)
{
	int x = idx.first;
	int y = idx.second;
	for (int i = x; i < x + num; i++)
	{
		for (int j = y; j < y + num; j++)
		{
			visit[i][j] = false;
		}
	}
}
void paste(int num, pii idx)
{
	int x = idx.first;
	int y = idx.second;
	for (int i = x; i < x + num; i++)
	{
		for (int j = y; j < y + num; j++)
		{
			visit[i][j] = true;
		}
	}
}
bool check(int num, pii idx)
{
	int x = idx.first;
	int y = idx.second;
	if (x + num > 10 || y + num > 10)
		return false;
	for (int i = x; i < x + num; i++)
	{
		for (int j = y; j < y + num; j++)
		{
			if (visit[i][j] == 1 || arr[i][j] == 0)
				return false;
		}
	}
	return true;
}
void dfs(int one, int two, int three, int four, int five, int cnt)
{
	if (one > 5 || two > 5 || three > 5 || four > 5 || five > 5)
		return;
	if (cnt == v.size())
	{
		minn = min(one + two + three + four + five, minn);
		return;
	}
	if (!visit[v[cnt].first][v[cnt].second])
	{

		for (int i = 5; i >= 1; i--)
		{

			if (check(i, { v[cnt].first,v[cnt].second }))
			{
				paste(i, { v[cnt].first,v[cnt].second });
				if (i == 5)
				{
					dfs(one, two, three, four, five + 1, cnt + 1);
				}
				else if (i == 4)
				{
					dfs(one, two, three, four + 1, five, cnt + 1);
				}
				else if (i == 3)
				{
					dfs(one, two, three + 1, four, five, cnt + 1);
				}
				else if (i == 2)
				{
					dfs(one, two + 1, three, four, five, cnt + 1);

				}
				else if (i == 1)
				{
					dfs(one + 1, two, three, four, five, cnt + 1);
				}
				re(i, { v[cnt].first,v[cnt].second });
			}
		}
	}
	else if (visit[v[cnt].first][v[cnt].second] == 1)
	{
		dfs(one, two, three, four, five, cnt + 1);
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				v.push_back({ i,j });
		}
	}
	dfs(0, 0, 0, 0, 0, 0);
	if (!v.size())
		cout << 0;
	else if (minn == 1e9)
		cout << -1;
	else
		cout << minn;
	return 0;

}


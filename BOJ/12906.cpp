//https://www.acmicpc.net/problem/12906
/*풀이 : bfs를 이용해 현재 조합이 정답의 조합과 같을 경우일 때 까지 움직여본다. map에는 원판의 조합을 string으로 받고
그 조합을 만든 시간을 담는다.*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <queue>
using namespace std;

int cnt[3];
int main()
{
	ios_base::sync_with_stdio(0);
	vector<string> s(3);
	for (int i = 0; i < 3; i++)
	{
		int a;
		cin >> a;
		if (a > 0)
		{
			cin >> s[i];
		}
	}

	vector<string> ans(3);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < s[i].size(); j++)
		{
			ans[s[i][j] - 'A'] += (char)s[i][j];
		}
	}
	map<vector<string>, int> d;
	queue< vector<string>> q;
	q.push(s);
	d[s] = 0;
	int cnt = 0;
	while (!q.empty())
	{
		int sizz = q.size();
		while (sizz--)
		{
			vector<string> now = q.front();
			q.pop();
			if (now == ans)
			{
				cout << cnt;
				exit(0);
			}
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (i == j)
						continue;
					if (now[i].length() == 0)
						continue;
					vector<string> next = now;
					next[j].push_back(next[i].back());
					next[i].pop_back();
					if (d.count(next) == 0)
					{
						q.push(next);
						d[next] = 1;
					}

				}
			}
		}
		cnt++;
	}
	return 0;
}

//https://www.acmicpc.net/problem/12100
/*풀이 : 처음 숫자를 벡터에 넣어주고, 다음 숫자가 벡터에 있는 숫자와 같고 합쳐진 적이 없으면 합친다.
벡터에 있는 숫자와 다르거나 합쳐진 적이 있으면 그냥 벡터에 push 한다.
검사한 행 또는 열은 전부 0으로 초기화 해주고 방향에 맞게 벡터의 원소를 나열해준다.*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
int t;
int map[21][21];
int n;
void fun(int dir)
{
	if (dir == 0)
	{
		for (int i = 0; i < n; i++)
		{
			int idx = 0;
			vector<pii> v;
			while (idx< n && map[i][idx] == 0)
			{
				idx++;
			}
			if (idx < n)
			{
				v.push_back({ map[i][idx],0 });
				map[i][idx] = 0;
				for (int j = idx + 1; j < n; j++)
				{
					if (map[i][j] != 0 && map[i][j] == v.back().first &&
						v.back().second == 0)
					{
						v.pop_back();
						v.push_back({ map[i][j] * 2,1 });
						map[i][j] = 0;
					}

					else if (map[i][j] != 0 && map[i][j] == v.back().first &&
						v.back().second == 1 || map[i][j] != 0 && map[i][j] != v.back().first)
					{
						v.push_back({ map[i][j],0 });
						map[i][j] = 0;
					}
				}
				for (int j = 0; j < v.size(); j++)
				{
					map[i][j] = v[j].first;
				}

			}

		}
	}
	else if (dir == 1)
	{
		for (int i = n - 1; i >= 0; i--)
		{
			int idx = n - 1;
			vector<pii> v;
			while (idx >= 0 && map[i][idx] == 0)
			{
				idx--;
			}
			if (idx >= 0)
			{
				v.push_back({ map[i][idx],0 });
				map[i][idx] = 0;
				for (int j = idx - 1; j >= 0; j--)
				{
					if (map[i][j] != 0 && map[i][j] == v.back().first &&
						v.back().second == 0)
					{
						v.pop_back();
						v.push_back({ map[i][j] * 2,1 });
						map[i][j] = 0;
					}
					else if (map[i][j] != 0 && map[i][j] == v.back().first &&
						v.back().second == 1 || map[i][j] != 0 && map[i][j] != v.back().first)
					{
						v.push_back({ map[i][j],0 });
						map[i][j] = 0;
					}
				}
				for (int j = 0; j < v.size(); j++)
				{
					map[i][n - 1 - j] = v[j].first;
				}
			}
		}
	}
	else if (dir == 2)
	{
		for (int i = n - 1; i >= 0; i--)
		{
			int idx = n - 1;
			vector<pii> v;
			while (idx >= 0 && map[idx][i] == 0)
			{
				idx--;
			}
			if (idx >= 0)
			{
				v.push_back({ map[idx][i],0 });
				map[idx][i] = 0;
				for (int j = idx - 1; j >= 0; j--)
				{
					if (map[j][i] != 0 && map[j][i] == v.back().first &&
						v.back().second == 0)
					{
						v.pop_back();
						v.push_back({ map[j][i] * 2,1 });
						map[j][i] = 0;
					}
					else if (map[j][i] != 0 && map[j][i] == v.back().first &&
						v.back().second == 1 || map[j][i] != 0 && map[j][i] != v.back().first)
					{
						v.push_back({ map[j][i],0 });
						map[j][i] = 0;
					}
				}
				for (int j = 0; j < v.size(); j++)
				{
					map[n - 1 - j][i] = v[j].first;
				}

			}

		}
	}
	else if (dir == 3)
	{
		for (int i = 0; i < n; i++)
		{
			int idx = 0;
			vector<pii> v;
			while (idx< n && map[idx][i] == 0)
			{
				idx++;
			}
			if (idx < n)
			{
				v.push_back({ map[idx][i],0 });
				map[idx][i] = 0;
				for (int j = idx + 1; j < n; j++)
				{
					if (map[j][i] != 0 && map[j][i] == v.back().first &&
						v.back().second == 0)
					{
						v.pop_back();
						v.push_back({ map[j][i] * 2,1 });
						map[j][i] = 0;
					}
					else if (map[j][i] != 0 && map[j][i] == v.back().first &&
						v.back().second == 1 || map[j][i] != 0 && map[j][i] != v.back().first)
					{
						v.push_back({ map[j][i],0 });
						map[j][i] = 0;
					}
				}
				for (int j = 0; j < v.size(); j++)
				{
					map[j][i] = v[j].first;
				}

			}

		}
	}
}
int res = 0;
void dfs(int cnt)
{
	int tmp[21][21];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tmp[i][j] = map[i][j];
		}
	}
	int maxx = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			maxx = max(maxx, map[i][j]);
		}
	}
	res = max(res, maxx);
	if (cnt == 5)
	{
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		fun(i);
		dfs(cnt + 1);
		for (int r = 0; r < n; r++)
		{
			for (int j = 0; j < n; j++)
			{
				map[r][j] = tmp[r][j];
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	dfs(0);
	cout << res;
	return 0;
}


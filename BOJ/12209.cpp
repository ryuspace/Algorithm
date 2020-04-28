//https://www.acmicpc.net/problem/12209
/*풀이 : 시뮬레이션. 시키는 대로 한다. 한번 합쳐진 애는 다시 안 합쳐지는 거 주의*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
int t;
int map[21][21];
void fun(int n, string dir)
{
	if (dir == "left")
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
	else if (dir == "right")
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
	else if (dir == "down")
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
	else if (dir == "up")
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
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> t;
	for (int r = 1; r <= t; r++)
	{
		int n;
		string dir;
		cin >> n >> dir;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
			}
		}
		fun(n, dir);
		cout << "Case #" << r << ":" << '\n';
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << map[i][j] << " ";
			}
			cout << '\n';
		}
	}
	return 0;
}

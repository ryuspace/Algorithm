//https://www.acmicpc.net/problem/16402
/*풀이 : 왕국끼리 싸우는 경우를 나눠서 union_find 해준다.*/
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

int n, m;
map <string, int> mp;
map <int, string> mp2;
int parent[501];
vector <string> v;

void Union(int x, int y, int num)
{
	if (num == 1)
	{
		if (parent[x] == y)
		{
			for (int i = 0; i < n; i++)
			{
				if (parent[i] == y)
				{
					parent[i] = x;
				}
			}
		}
		else
		{
			//속국 속국
			if (parent[x] != x && parent[y] != y)
			{
				x = parent[x];
				y = parent[y];
			}
			//주국 속국

			if (parent[x] == x && parent[y] != y)
			{
				y = parent[y];
			}

			//속국 주국

			if (parent[x] != x && parent[y] == y)
			{
				x = parent[x];
			}
			for (int i = 0; i < n; i++)
			{
				if (parent[i] == y)
				{
					parent[i] = x;
				}
			}
		}

	}
	else if (num == 2)
	{
		if (parent[y] == x)
		{
			for (int i = 0; i < n; i++)
			{
				if (parent[i] == x)
				{
					parent[i] = y;
				}
			}
		}
		else
		{
			//속국 속국
			if (parent[x] != x && parent[y] != y)
			{
				x = parent[x];
				y = parent[y];
			}
			//주국 속국

			if (parent[x] == x && parent[y] != y)
			{
				y = parent[y];
			}

			//속국 주국

			if (parent[x] != x && parent[y] == y)
			{
				x = parent[x];
			}
			for (int i = 0; i < n; i++)
			{
				if (parent[i] == x)
				{
					parent[i] = y;
				}
			}
		}
	}
}
int main()
{

	ios_base::sync_with_stdio(0);

	cin >> n >> m;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		string a, b;
		string c;
		cin >> a >> b >> c;
		mp[c] = cnt;
		mp2[cnt] = c;
		cnt++;
		parent[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		string a, b;

		string c;
		string d;
		string e;
		
		string name1="";
		string name2="";
		
		cin >> a >> b >> c >> d >> e;

		int cnt = 0;
		while (c[cnt] != ',')
		{
			name1+= c[cnt];
			cnt++;
		}
		cnt = 0;

		while (e[cnt] != ',')
		{
			name2 += e[cnt];
			cnt++;
		}
		cnt++;
		int num = e[cnt] - '0';


		Union(mp[name1], mp[name2], num);
	}
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		if (parent[i] == i)
		{
			v.push_back(mp2[i]);
			res++;
		}
	}
	cout << res << '\n';
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		cout << "Kingdom of " << v[i] << '\n';
	}
	return 0;
}
